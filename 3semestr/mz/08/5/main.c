#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Комментарии к коду
// в случае если процесс не смог создаться, я не проверяю, что ввод не закончился

int main(void)
{
    int n, status, m = 0;
    if (scanf("%d", &n) == EOF) {
        return 0;
    }
    while (1) {
        int pid = fork();
        if (pid == -1) {
            printf("-1\n");
            exit(2);
        } else if (pid == 0) {
            if (scanf("%d", &n) == EOF) {
                exit(0);
            }
            m++;
        } else {
            wait(&status);
            if (WEXITSTATUS(status) == 0) {
                printf("%d\n", n);
                if (m) {
                    exit(1);
                } else {
                    break;
                }
            } else if (WEXITSTATUS(status) == 1) {
                printf("%d\n", n);
                if (m) {
                    exit(1);
                } else {
                    break;
                }
            } else {
                if (m) {
                    exit(2);
                } else {
                    break;
                }
            }
        }
    }
    return 0;
}
