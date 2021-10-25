#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        int f = open(argv[i], O_WRONLY);
        if (f == -1) {
            fprintf(stderr, "Error\n");
            return 1;
        }

        unsigned short u;
        while (scanf("%hu", &u) != EOF) {
            write(f, &u, sizeof(u));
        }
        close(f);
    }
    return 0;
}