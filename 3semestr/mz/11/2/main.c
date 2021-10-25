#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

volatile sig_atomic_t mode = 0;

void
handler1(int sign)
{
    mode = 0;
}

void
handler2(int sign)
{
    mode = 1;
}

int main(int argc, char *argv[])
{
    mode = 0;

    struct sigaction summ = {0};
    summ.sa_handler = handler1;
    summ.sa_flags = SA_RESTART;
    sigaction(SIGINT, &summ, NULL);
    struct sigaction proz = {0};
    proz.sa_handler = handler2;
    proz.sa_flags = SA_RESTART;
    sigaction(SIGQUIT, &proz, NULL);

    printf("%d\n", getpid());
    fflush(stdout);

    int res = 0, a;

    while (scanf("%d", &a) != EOF) {
        if (mode == 0) {
            __builtin_sadd_overflow(res, a, &res);
        } else {
            __builtin_smul_overflow(res, a, &res);
        }
        printf("%d\n", res);
        fflush(stdout);
    }
    return 0;
}
