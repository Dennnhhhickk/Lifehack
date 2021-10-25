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

unsigned long long last_prime;

void
handler1(int sign)
{
    static int cnt = 0;
    if (cnt == 3) {
        _exit(0);
    }
    printf("%llu\n", last_prime);
    cnt++;
    fflush(stdout);
}

void
handler2(int sign)
{
    _exit(0);
}

int
prime(unsigned long long a)
{
    for (unsigned long long i = FIRST_PRIME; i < sqrt((double)a); i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    unsigned long long low, high;
    scanf("%llu %llu", &low, &high);

    struct sigaction sa = {0};
    sa.sa_handler = handler1;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, NULL);
    struct sigaction sb = {0};
    sb.sa_handler = handler2;
    sb.sa_flags = SA_RESTART;
    sigaction(SIGTERM, &sb, NULL);

    printf("%d\n", getpid());
    fflush(stdout);

    last_prime = 0;

    for (unsigned long long i = low; i < high; i++) {
        if (prime(i)) {
            last_prime = i;
        }
    }
    printf("-1\n");
    fflush(stdout);
    return 0;
}
