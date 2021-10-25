#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int
result(int pid)
{
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
        return (WEXITSTATUS(status) == 0);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 6) {
        fprintf(stderr, "Not enough arguments\n");
        return 1;
    }

    int fds[2];
    pipe(fds);

    int pid1 = fork();
    if (pid1 == 0) {
        int f = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0666);
        dup2(f, 1);
        close(f);
        dup2(fds[0], 0);
        close(fds[0]);
        close(fds[1]);
        execlp(argv[3], argv[3], NULL);
        _exit(0);
    }

    int pid2 = fork();
    if (pid2 == 0) {
        dup2(fds[1], 1);
        close(fds[1]);
        close(fds[0]);

        int pid3 = fork();
        if (pid3 == 0) {
            int f = open(argv[4], O_RDONLY);
            dup2(f, 0);
            close(f);
            execlp(argv[1], argv[1], NULL);
            _exit(1);
        }

        if (!result(pid3)) {
            _exit(0);
        }

        pid3 = fork();
        if (pid3 == 0) {
            execlp(argv[2], argv[2], NULL);
            _exit(1);
        }
        waitpid(pid3, NULL, 0);
        _exit(0);
    }
    close(fds[0]);
    close(fds[1]);
    waitpid(pid2, NULL, 0);
    waitpid(pid1, NULL, 0);
    return 0;
}
