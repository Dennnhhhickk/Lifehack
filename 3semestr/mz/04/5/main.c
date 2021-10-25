#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

unsigned long long
hash_function(unsigned long long);

int
main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Not enough arguments\n");
        return 1;
    }
    char *end = NULL;
    int f = open(argv[1], O_RDWR | O_CREAT, 0660);
    if (f != -1) {
        unsigned long long h0 = strtoull(argv[2], &end, 16);
        unsigned long long count = strtoull(argv[3], &end, 10);
        off_t size = lseek(f, 0, SEEK_END);
        for (unsigned long long i = 0; i < count; i++) {
            lseek(f, size + (count - 1 - i) * sizeof(h0), SEEK_SET);
            write(f, &h0, sizeof(h0));
            h0 = hash_function(h0);
        }
        close(f);
    }
    return 0;
}