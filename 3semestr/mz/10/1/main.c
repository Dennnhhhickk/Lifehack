#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fds[2];
    pipe(fds);
    int pid1 = fork();

    if (pid1 > 0) {
        waitpid(pid1, NULL, 0);
        time_t sec;
        read(fds[0], &sec, sizeof(sec));
        struct tm *now = calloc(1, sizeof(*now));
        now = localtime_r(&sec, now);
        int a = now->tm_year + 1900;
        printf("Y:%d\n", a);
        fflush(stdout);
        close(fds[0]);
        close(fds[1]);
        free(now);
        return 0;
    }

    int pid2 = fork();

    if (pid2 > 0) {
        waitpid(pid2, NULL, 0);
        time_t sec;
        read(fds[0], &sec, sizeof(sec));
        struct tm *now = calloc(1, sizeof(*now));
        now = localtime_r(&sec, now);
        int a = now->tm_mon + 1;
        printf("M:%02d\n", a);
        fflush(stdout);
        close(fds[0]);
        close(fds[1]);
        free(now);
        _exit(0);
    }

    int pid3 = fork();

    if (pid3 > 0) {
        waitpid(pid3, NULL, 0);
        time_t sec;
        read(fds[0], &sec, sizeof(sec));
        struct tm *now = calloc(1, sizeof(*now));
        now = localtime_r(&sec, now);
        int a = now->tm_mday;
        printf("D:%02d\n", a);
        fflush(stdout);
        close(fds[0]);
        close(fds[1]);
        free(now);
        _exit(0);
    }
    time_t now = time(NULL);
    for (int i = 0; i < 3; ++i) {
        write(fds[1], &now, sizeof(now));
    }
    close(fds[0]);
    close(fds[1]);
    _exit(0);
}
