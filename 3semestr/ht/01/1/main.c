#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/mman.h>

enum { N = 4 };

int
main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Not enough arguments\n");
        return 1;
    }
    char *end = NULL;
    int bias = strtol(argv[2], &end, 16);
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Can't open file\n");
        return 1;
    }
    unsigned short *p = mmap(0, 1024 * 64, PROT_READ, MAP_PRIVATE, fd, 0);
    if (p == MAP_FAILED) {
        fprintf(stderr, "MAP FAILED\n");
        close(fd);
        return 1;
    }
    unsigned short *pp = p + bias / sizeof(*pp);
    unsigned a;
    while (scanf("%xu", &a) == 1) {
        unsigned f = pp[a >> 9];
        printf("%u\n", p[(f + (a & 511)) / sizeof(*p)]);
    }
    munmap(p, 1024 * 64);
    close(fd);
    return 0;
}
