#include <stdio.h>
#include <math.h>

#define sqr(a) ((a) * (a))

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

ld max(ld a, ld b)
{
    if (a > b)
        return a;
    return b;
}

ld D(ld s, ld a, ld v)
{
    if (fabs(a) < 1e-13)
        return s / v;
    else
        return (sqrt(sqr(v) + 2 * a * s) - v) / a;
}

int main(void)
{
    ll n;
    ld s[110], a[110];
    scanf("%lli", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf", s + i);
    for (int i = 0; i < n; i++)
        scanf("%lf", a + i);
    ld ans = 0, v = 0;
    for (int i = 0; i < n; i++)
    {
        ld t = D(s[i], a[i], v);
        v += a[i] * t;
        ans += t;
    }
    printf("%.4lf\n", ans);
    return 0;
}
