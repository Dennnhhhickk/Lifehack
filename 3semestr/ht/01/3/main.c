#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/mman.h>

int
min(int a, int b)
{
    if (a < b) {
        return a;
    }
    return b;
}

int
diam(int i, int j, int n, int m)
{
    return min(min(i, n - 1 - i), min(j, m - j - 1));
}

int
per(int d, int n, int m)
{
    return 1 + 2 * d * (n + m - 2 - 2 * (d - 1));
}

int
table(int i, int j, int n, int m)
{
    int d = diam(i, j, n, m);
    if ((i - d) * (m - 2 * d - 1) > (j - d) * (n - 2 * d - 1)) {
        return per(d + 1, n, m) - i - j + 2 * d;
    }
    return per(d, n, m) + i + j - 2 * d;
}

int
main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Not enough arguments\n");
        return 1;
    }
    char *end = NULL;
    long long n, m;
    n = strtoll(argv[2], &end, 10);
    m = strtoll(argv[3], &end, 10);
    int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0600);
    if (fd == -1) {
        fprintf(stderr, "Can't open and create file\n");
        return 1;
    }
    lseek(fd, (n * m - 1) * sizeof(int), SEEK_SET);
    int a = 0;
    write(fd, &a, sizeof(a));
    lseek(fd, 0, SEEK_SET);
    int (*p)[m] = (int (*)[m]) mmap(0, (n * m) * sizeof(a), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = table(i, j, n, m);
        }
    }
    munmap(p, n * m * sizeof(a));
    close(fd);
    return 0;
}
