#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

int
reverse(int a)
{
    int res = 0;
    for (int i = 0; i < 4; i++) {
        res <<= 8;
        res |= a & ((1 << 8) - 1);
        a >>= 8;
    }
    return res;
}

int
main(int argc, char *argv[])
{
    int max = 0, max1 = 0;
    int bol = 0, bol1 = 0;
    for (int i = 1; i < argc; i++) {
        int f = open(argv[i], O_RDONLY);
        if (f != -1) {
            char str[16];
            int tmp;
            while (read(f, str, sizeof(str))) {
                read(f, &tmp, sizeof(tmp));
                //tmp = reverse(tmp);
                if (bol == 0 || tmp > max) {
                    bol1 = bol;
                    bol = 1;
                    max1 = max;
                    max = tmp;
                } else if (bol == 1 && tmp != max && (bol1 == 0 || tmp > max1)) {
                    bol1 = 1;
                    max1 = tmp;
                }
            }
            close(f);
        }
    }
    if (bol1) {
        if (max1 < 0) {
            printf("-");
        }
        printf("%d.%.2d\n", abs(max1 / 100), abs(max1 % 100));
    }
    return 0;
}