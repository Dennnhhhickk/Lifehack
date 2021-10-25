#include <stdio.h>
#include <math.h>

#define sqr(a) ((a) * (a))

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

ll min(ll a, ll b)
{
    if (a < b)
        return a;
    return b;
}

int main(void)
{
    ll n = 16, a[16], ans = 0;
    for (int i = 0; i < n; i++)
        scanf("%lli", a + i);
    for (int i = 0; i < 8; i++)
    {
        int bol1 = 1, bol2 = 1;
        for (int j = 0; j < 8; j++)
        {
            if (a[7 - i] <= a[8 + j])
                bol1 = 0;
            if (a[8 + i] <= a[7 - j])
                bol2 = 0;
        }
        if (bol1 || bol2)
        {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            ans += min(a[7 - i], a[8 + j]);
    printf("%lli", ans);
    return 0;
}
