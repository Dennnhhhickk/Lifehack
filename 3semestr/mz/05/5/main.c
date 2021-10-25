#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

unsigned short
reverse(unsigned short a)
{
    unsigned short res = 0;
    for (int i = 0; i < 2; i++) {
        res <<= 8;
        res |= a & ((1 << 8) - 1);
        a >>= 8;
    }
    return res;
}

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Not enough arguments\n");
        return 1;
    }
    int f = open(argv[1], O_RDONLY);
    if (f != -1) {
        unsigned short ans = 0;
        int bol = 0;
        unsigned short u;
        while(read(f, &u, sizeof(u))) {
            u = reverse(u);
            if (!(u & 1)) {
                if (u < ans || bol == 0) {
                    ans = u;
                    bol = 1;
                }
            }
        }

        if (bol) {
            printf("%u\n", ans);
        }

        close(f);
    }
    return 0;
}