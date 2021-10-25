#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>

enum
{
    CHAR_BIT_ON_TARGET_MACHINE = 12,
};

int
main(int argc, char ** argv)
{
    if (argc < 2) {
        fprintf(stderr, "Specify the filename!\n");
        return 1;
    }

    int f = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (f < 0) {
        return 1;
    } 
    unsigned t;
    
    unsigned char buf[4];

    while (scanf("%u", &t) == 1) {
        unsigned p2 = t & 0x00000FFF, p1 = t >> CHAR_BIT_ON_TARGET_MACHINE;
        buf[0] = p1 >> CHAR_BIT;
        buf[1] = p1;
        buf[2] = p2 >> CHAR_BIT;
        buf[3] = p2;

        if (write(f, buf, sizeof(buf)) != sizeof(buf)) {
            fprintf(stderr, "Error while writing result\n");
            close(f);
            return 1;
        }
    }

    close(f);

    return 0;
}
