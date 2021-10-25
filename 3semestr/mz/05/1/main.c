#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

enum { SIZE = 1024 };

int
main(int argc, char *argv[])
{
    unsigned long long answer = 0;
    for (int i = 1; i < argc; i++) {
        struct stat buf;
        if (lstat(argv[i], &buf) >= 0 && buf.st_size % SIZE == 0 && buf.st_nlink == 1 &&
                S_ISREG(buf.st_mode)) {
            answer += buf.st_size;
        }
    }
    printf("%llu\n", answer);
    return 0;
}
