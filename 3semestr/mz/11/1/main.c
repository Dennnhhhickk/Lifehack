#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void
handler(int sign)
{
    static int cnt = 0;
    if (cnt < 5){
        printf("%d\n", cnt);
        fflush(stdout);
        cnt++;
    } else {
        _exit(0);
    }
}

int main(int argc, char *argv[])
{
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGHUP, &sa, NULL);
    printf("%d\n", getpid());
    fflush(stdout);
    while (1) {
        pause();
    }
    return 0;
}
