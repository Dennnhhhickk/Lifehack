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
    ll n, a[10000], b[10000], c[10000];
    scanf("%lli", &n);
    for (int i = 0; i < n; i++)
        scanf("%lli", a + i);
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < n; i++)
            c[i] = b[a[i] - 1];
        for (int i = 0; i < n; i++)
            b[i] = c[i];
    }
    for (int i = 0; i < n; i++)
        printf("%lli ", b[i]);
    return 0;
}