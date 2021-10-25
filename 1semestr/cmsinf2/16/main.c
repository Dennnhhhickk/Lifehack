#include <stdio.h>

#define bit 64
#define N 150000000/bit + 1
#define TL for(;;)

typedef unsigned long long ull;

int main(void)
{
    ull a[N] = {0}, n;
    scanf("%llu", &n);
    for (int i = 0; i < n; i++)
    {
        ull tmp;
        scanf("%llu", &tmp);
        tmp++;
        a[tmp / bit] ^= 1 << (tmp % bit);
    }
    ull ans1 = 0, ans2 = 0, ans3 = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] != 0)
        {
            for (int j = 0; j < bit; j++)
                if ((1 << j) & a[i])
                {
                    ans3 = ans2;
                    ans2 = ans1;
                    ans1 = i * bit + j;
                }
        }
    }
    printf("%llu %llu %llu", ans3 - 1, ans2 - 1, ans1 - 1);
    TL;
    return 0;
}