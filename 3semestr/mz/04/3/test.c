#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

struct Node
{
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
};

int
main()
{
    int f = open("input", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    long long tmp;
    while (scanf("%lld", &tmp) != EOF) {
        printf("%lld\n", tmp);
        write(f, &tmp, sizeof(tmp));
    }
    return 0;
}