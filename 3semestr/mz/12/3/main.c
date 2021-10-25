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

volatile int ans;

void
handler1(int sig)
{
    ans += 5;
    printf("10 %d\n", ans);
    fflush(stdout);
}

void
handler2(int sig)
{
    ans -= 4;
    printf("12 %d\n", ans);
    fflush(stdout);
    if (ans < 0) {
        _exit(0);
    }
}

int main(int argc, char *argv[])
{
    ans = 0;
    struct sigaction sa1 = {0};
    sa1.sa_handler = handler1;
    sigaction(SIGUSR1, &sa1, NULL);
    struct sigaction sa2 = {0};
    sa2.sa_handler = handler2;
    sigaction(SIGUSR2, &sa2, NULL);
    printf("%d\n", getpid());
    fflush(stdout);
    while (1) {
        pause();
    }
    return 0;
}
