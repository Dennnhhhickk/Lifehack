#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <math.h>

volatile sig_atomic_t flag = 0;

void
handler(int sign)
{
    flag = 1;
}

int main(int argc, char *argv[])
{
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);

    char *end;
    long long max = strtoll(argv[1], &end, 10);
    int fd[2];
    if (pipe(fd) == -1) {
        return 1;
    }
    int b, res, pids[2] = {-1, -1};
    FILE *in, *out;
    in = fdopen(fd[0], "r");
    out = fdopen(fd[1], "w");
    int pid = fork(), a = 1;
    if (pid > 0) {
        pids[0] = pid;
        a = 2;
        pid = fork();
        if (pid > 0) {
            pids[1] = pid;
        }
    }
    while (pid == 0) {
        if (flag) {
            int p;
            if ((res = fscanf(in, "%d %d", &p, &b)) == EOF || b >= max) {
                if (res == EOF) {
                    printf("HUI\n");
                    fflush(stdout);
                }
                fprintf(out, "%d %d\n", getpid(), b);
                fflush(out);
                fclose(in);
                fclose(out);
                _exit(0);
            }
            printf("%d %d\n", a, b);
            fflush(stdout);
            ++b;
            fprintf(out, "%d %d\n", getpid(), b);
            fflush(out);
            kill(p, SIGUSR1);
            flag = 0;
        }
    }
    fprintf(out, "%d 1\n", pids[1]);
    fflush(out);
    fclose(in);
    fclose(out);
    kill(pids[0], SIGUSR1);
    int p = wait(NULL);
    for (int i = 0; i < 2; ++i) {
        if (p == pids[i]) {
            kill(pids[1 - i], SIGUSR1);
            waitpid(pids[1 - i], NULL, 0);
            break;
        }
    }
    printf("Done\n");
    return 0;
}
