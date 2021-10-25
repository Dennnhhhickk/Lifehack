#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int fds[2];
    pipe(fds);
    int pid1 = fork();

    if (pid1 > 0) {
        close(fds[0]);
        int a;
        while (scanf("%d", &a) != EOF) {
            write(fds[1], &a, sizeof(a));
        }
        close(fds[1]);
        waitpid(pid1, NULL, 0);
        return 0;
    }

    int pid2 = fork();

    if (pid2 > 0) {
        close(fds[0]);
        close(fds[1]);
        waitpid(pid2, NULL, 0);
        return 0;
    }

    close(fds[1]);

    long long sum = 0;

    int a;
    while (read(fds[0], &a, sizeof(a)) > 0) {
        sum += a;
    }
    printf("%lld\n", sum);
    close(fds[0]);
    return 0;
}
