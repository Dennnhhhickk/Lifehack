#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdlib.h>

struct Node
{
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
};

enum { SIZE = sizeof(struct Node) };

void
processing(int f, off_t current_offset)
{
    struct Node tmp;
    if (read(f, &tmp, SIZE) < SIZE) {
        fprintf(stderr, "Error in \"read\"\n");
        exit(1);
    }
    if (tmp.right_idx) {
        lseek(f, tmp.right_idx * SIZE, SEEK_SET);
        processing(f, tmp.right_idx * SIZE);
        lseek(f, current_offset, SEEK_SET);
    }
    printf("%"PRId32" ", tmp.key);
    if (tmp.left_idx) {
        lseek(f, tmp.left_idx * SIZE, SEEK_SET);
        processing(f, tmp.left_idx * SIZE);
        lseek(f, current_offset, SEEK_SET);
    }
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
        processing(f, 0);
        printf("\n");
        close(f);
    }

    return 0;
}