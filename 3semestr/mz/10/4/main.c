#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

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

void
end(int *pids, int n)
{
    for (int i = 0; i < n && pids[i] != -1; ++i) {
        kill(pids[i], SIGKILL);
        waitpid(pids[i], NULL, 0);
    }
    _exit(1);
}

int main(int argc, char *argv[])
{
    int fd[2], fds;
    int *pids = calloc(argc - 1, sizeof(*pids));
    if (pids == NULL) {
        _exit(1);
    }
    for (int i = 0; i < argc - 1; ++i) {
        pids[i] = -1;
    }
    if (pipe(fd) == -1) {
        end(pids, argc - 1);
    }
    fds = dup(0);

    for (int i = 0; i < argc - 1; ++i) {
        if (i > 0 && dup2(fd[0], fds) == -1) {
            end(pids, argc - 1);
        }
        if (close(fd[0]) == -1) {
            end(pids, argc - 1);
        }
        if (close(fd[1]) == -1) {
            end(pids, argc - 1);
        }
        if (pipe(fd) == -1) {
            end(pids, argc - 1);
        }
        pids[i] = fork();
        if (pids[i] == -1) {
            end(pids, argc - 1);
        } else if (pids[i] == 0) {
            if (i < argc - 2) {
                dup2(fd[1], 1);
            }
            if (dup2(fds, 0) == -1) {
                end(pids, argc - 1);
            }
            free(pids);
            close(fd[0]);
            close(fd[1]);
            close(fds);
            execlp(argv[i + 1], argv[i + 1], NULL);
            _exit(0);
        }
    }

    if (close(fd[0]) == -1) {
        end(pids, argc - 1);
    }
    if (close(fd[1]) == -1) {
        end(pids, argc - 1);
    }
    if (close(fds) == -1) {
        end(pids, argc - 1);
    }
    int status;
    for (int i = 0; i < argc - 1; ++i) {
        if (waitpid(pids[i], &status, 0) == -1) {
            end(pids, argc - 1);
        }
    }
    return 0;
}
