#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
    int pid = fork();
    if (pid == 0) {
        int pid1 = fork();
        if (pid1 == 0) {
            printf("3 ");
            return 0;
        }
        wait(NULL);
        printf("2 ");
        return 0;
    }
    wait(NULL);
    printf("1\n");
    return 0;
}
