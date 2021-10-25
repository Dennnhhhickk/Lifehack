#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

enum { N = 2, K = (1 << 12) - 1, L = 255 };

unsigned int
int_to_24(unsigned int a)
{
    unsigned int res = 0;
    for (int i = 0; i < N; i++) {
        unsigned int tmp = a & K;
        res <<= 8;
        res |= tmp & L;
        tmp >>= 8;
        res <<= 8;
        res |= tmp & L;
        a >>= 12;
    }
    return res;
}

int main(int argc, char *argv[])
{
    int f = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (f == -1) {
        return 1;
    }
    unsigned int tmp;
    while (scanf("%u", &tmp) == 1) {
        tmp = int_to_24(tmp);
        if (write(f, &tmp, sizeof(tmp)) == -1) {
            return 1;
        }
    }
    return 0;
}
