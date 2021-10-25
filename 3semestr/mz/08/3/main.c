#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum { N = 3 };

void
proc(int i, int pid)
{
    if (pid == 0) {
        char s[10];
        read(0, s, 8);
        char *end = NULL;
        long t = strtol(s, &end, 10);
        printf("%d %ld\n", i, t * t);
    }
}

int main(void)
{
    for (int i = 0; i < N; i++) {
        int pid = fork();
        proc(i + 1, pid);
        if (pid == 0) {
            return 0;
        }
    }
    for (int i = 0; i < N; i++) {
        wait(NULL);
    }
    return 0;
}
