#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    char *end;
    long long mod = strtoll(argv[2], &end, 10);
    creat(argv[1], 0751);
    FILE *o = fopen(argv[1], "w");
    fprintf(o, "#!/bin/python3\na=int(input())\n");
    fprintf(o, "print((a * (a + 1) // 2) %% %lld)\n", mod);
    fclose(o);
    return 0;
}
