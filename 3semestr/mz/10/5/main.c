#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <math.h>

int main(int argc, char *argv[])
{
    FILE *in, *out, *tmp;
    char *end;
    long long max = strtoll(argv[1], &end, 10);
    int fd1[2];
    int fd2[2];
    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        return 1;
    }
    int b = 0;
    tmp = fdopen(fd1[1], "w");
    fprintf(tmp, "1\n");
    fflush(tmp);
    int pid1 = fork();
    int pid2 = -1;
    if (pid1 != 0) {
        pid2 = fork();
    }
    if (pid1 == 0) {
        fclose(tmp);
        close(fd2[0]);
        in = fdopen(fd1[0], "r");
        out = fdopen(fd2[1], "w");
    } else if (pid2 == 0) {
        close(fd2[1]);
        close(fd1[0]);
        in = fdopen(fd2[0], "r");
        out = tmp;
    } else {
        close(fd1[0]);
        fclose(tmp);
        close(fd2[0]);
        close(fd2[1]);
    }
    while (pid1 == 0 || pid2 == 0) {
        if (pid1 == 0) {
            if (fscanf(in, "%d", &b) == EOF) {
                fclose(in);
                fclose(out);
                _exit(0);
            }
            if (b < max) {
                printf("1 %d\n", b);
                fflush(stdout);
                b++;
                fprintf(out, "%d\n", b);
                fflush(out);
            } else {
                fclose(in);
                fclose(out);
                _exit(0);
            }
        } else if (pid2 == 0) {
            if (fscanf(in, "%d", &b) == EOF) {
                fclose(in);
                fclose(out);
                _exit(0);
            }
            if (b < max) {
                printf("2 %d\n", b);
                fflush(stdout);
                b++;
                fprintf(out, "%d\n", b);
                fflush(out);
            } else {
                fclose(in);
                fclose(out);
                _exit(0);
            }
        }
    }
    wait(NULL);
    wait(NULL);
    printf("Done\n");
    return 0;
}
