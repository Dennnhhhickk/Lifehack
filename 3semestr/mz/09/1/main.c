#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
//    if (argc < 5) {
//        fprintf(stderr, "Not enough arguments\n");
//        return 1;
//    }
//
//    Рекомендую вообще ничего не выводить в stderr, так как многие ловили из-за этого частичное
    int status, pid = fork();
    if (pid == 0) {
        int err = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0660);
        if (err == -1) {
            exit(42);
        }
        dup2(err, 2);
        close(err);
        
        int input = open(argv[2], O_RDONLY);
        if (input == -1) {
            exit(42);
        }
        dup2(input, 0);
        close(input);
        
        int output = open(argv[3], O_WRONLY | O_APPEND | O_CREAT, 0660);
        if (output == -1) {
            exit(42);
        }
        dup2(output, 1);
        close(output);
        
        execlp(argv[1], argv[1], NULL);
        exit(42);
    }
    
    wait(&status);
    printf("%d\n", status);
    return 0;
}
