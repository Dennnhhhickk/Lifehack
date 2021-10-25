#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    char *end;
    unsigned long long count = strtoull(argv[1], &end, 10);
    unsigned long long modulo = strtoull(argv[2], &end, 10);

    int fds[2];
    pipe(fds);
    int p1 = fork();
    if (p1 == 0) {
        int fd[2];
        pipe(fd);
        int p2 = fork();
        if (p2 == 0) {
            dup2(fd[0], 0);
            dup2(fds[1], 1);

            close(fds[0]);
            close(fds[1]);
            close(fd[0]);
            close(fd[1]);

            execlp(argv[3], argv[3], NULL);
            _exit(0);
        } else {
            close(fds[0]);
            close(fds[1]);
            close(fd[0]);
            FILE *out = fdopen(fd[1], "w");
            unsigned long long a;
            for (int i = 1; i <= count; ++i) {
                a = 1ull * (i % modulo) * (i % modulo) % modulo;
                fprintf(out, "%llu ", a);
            }
            fflush(out);
            fclose(out);

            waitpid(p2, NULL, 0);
            _exit(0);
        }
    }
    int p3 = fork();
    if (p3 == 0) {
        int p4 = fork();
        if (p4 == 0) {
            char ch[4096];
            close(fds[1]);
            size_t size;
            while ((size = read(fds[0], &ch, sizeof(ch))) > 0) {
                for (int i = 0; i < size; ++i) {
                    if (ch[i] == ' ') {
                        putchar('\n');
                    } else {
                        putchar(ch[i]);
                    }
                }
            }
            fflush(stdout);
            close(fds[0]);
            _exit(0);
        } else {
            close(fds[0]);
            close(fds[1]);
            waitpid(p4, NULL, 0);
            _exit(0);
        }
    }
    close(fds[0]);
    close(fds[1]);
    waitpid(p1, NULL, 0);
    waitpid(p3, NULL, 0);
    printf("0\n");
    return 0;
}
