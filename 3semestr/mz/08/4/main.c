#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int pid = fork();
        if (pid == 0) {
            if (i) {
                printf(" ");
            }
            printf("%d", i + 1);
            fflush(stdout);
        } else {
            wait(NULL);
            return 0;
        }
    }
    wait(NULL);
    printf("\n");
    return 0;
}
