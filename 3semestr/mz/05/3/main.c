#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint32_t
handler(uint32_t tmp, uint32_t n)
{
    tmp <<= 32 - n;
    tmp >>= 32 - n;
    if (tmp & ((uint32_t)1 << (n - 1))) {
        tmp &= ~((uint32_t)1 << (n - 1));
        tmp = ~tmp;
        tmp++;
    }
    return tmp;
}

int
main()
{
    uint32_t n, s, N;
    int w;
    scanf("%"PRId32" %"PRId32" %d", &n, &s, &w);
    if (n != 32) {
        N = ((uint32_t)1 << n) - 1;
    } else {
        N = -1;
    }
    uint32_t residual = N;
    for (uint32_t i = 0; i <= N && residual >= N - i; i += s) {
        residual = N - i;
        printf("|%*"PRIo32"|%*"PRIu32"|%*"PRId32"|\n", w, i, w, i, w, handler(i, n));
    }
    return 0;
}
