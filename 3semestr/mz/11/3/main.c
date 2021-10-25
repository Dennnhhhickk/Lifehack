#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <math.h>

enum { FIRST_PRIME = 2 };

int main(int argc, char *argv[])
{
    char *end;
    int size = 1, k = 0, *pids = calloc(size, sizeof(*pids));
    unsigned long long N = strtoll(argv[1], &end, 10);
    if (N > argc - 2) {
        N = argc - 2;
    }
    for (int i = 0; i < N; ++i) {
        int pid = fork();
        if (pid == 0) {
            char path[PATH_MAX + 2];
            FILE *file = fopen(argv[i + 2], "r");
            fgets(path, PATH_MAX + 1, file);
            fclose(file);
            path[strlen(path) - 1] = '\0';
            execlp(path, path, NULL);
            _exit(1);
        } else {
            pids[k] = pid;
            ++k;
            if (k == size) {
                size <<= 1;
                pids = realloc(pids, size * sizeof(*pids));
            }
        }
    }
    int ans = 0;
    int *status = calloc(k, sizeof(*status));
    for (int i = 0; i < k; ++i) {
        waitpid(pids[i], &status[i], 0);
        if (WIFEXITED(status[i]) && WEXITSTATUS(status[i]) == 0) {
            ++ans;
        }
    }
    for (int i = N; i < argc - 2; ++i) {
        int pid = fork();
        if (pid == 0) {
            char path[PATH_MAX + 2];
            FILE *file = fopen(argv[i + 2], "r");
            fgets(path, PATH_MAX + 1, file);
            fclose(file);
            path[strlen(path) - 1] = '\0';
            execlp(path, path, NULL);
            _exit(1);
        } else {
            int stat;
            waitpid(pid, &stat, 0);
            if (WIFEXITED(stat) && WEXITSTATUS(stat) == 0) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
