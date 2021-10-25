#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Not enough arguments\n");
        return 1;
    }
    int f = open(argv[1], O_RDWR);
    if (f != -1) {
        long long tmp, res;
        unsigned long long postmp = 0, posres = 0;
        if (read(f, &res, sizeof(res)) == sizeof(res)) {
            while (read(f, &tmp, sizeof(tmp))) {
                postmp++;
                if (tmp < res) {
                    res = tmp;
                    posres = postmp;
                }
            }
            lseek(f, posres * sizeof(res), SEEK_SET);
            if (res != 0 && res != LLONG_MIN) {
                res = ~res + 1;
            }
            write(f, &res, sizeof(res));
        }
        close(f);
    }
    return 0;
}