#include <stdio.h>
#include <math.h>

#define sqr(a) ((a) * (a))

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

int main(void)
{
    ll n, a[10000], ans = 0, b;
    scanf("%lli", &n);
    for (int i = 0; i < n; i++)
        scanf("%lli", a + i);
    for (int i = 0; i < n; i++)
    {
        scanf("%lli", &b);
        ans += max(b, a[i]);
    }
    printf("%lli\n", ans);
    return 0;
}
