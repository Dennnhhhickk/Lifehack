#include <stdio.h>

typedef unsigned long long ull;

ull bit(ull a, ull i)
{
    return (a & (1<<i))>>i;
}

ull min(ull a, ull b)
{
    if (a < b)
        return a;
    return b;
}

ull max(ull a, ull b)
{
    if (a > b)
        return a;
    return b;
}

int main(void)
{
    ull n, mask[64] = {0}, a, x = 0;
    scanf("%llu", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%llu", &a);
        x ^= a;
        for (int i = 0; i < 64; i++)
            if (bit(a, i))
                mask[i] ^= a;
    }
    ull mx = 0;
    for (int i = 0; i < 64; i++)
        if (mask[i] != x)
            mx = max(mask[i], mx);
    printf("%llu %llu", min(mx, mx ^ x), max(mx, mx ^ x));
    return 0;
}