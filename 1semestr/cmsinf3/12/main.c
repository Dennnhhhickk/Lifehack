#include <stdio.h>
#include <math.h>

typedef long long ll;

int a[20];

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

long long f(ll b, ll n)
{
    ll res = 0, res1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (b % 3 == 1)
            res += a[i];
        if (b % 3 == 2)
            res1 += a[i];
        b /= 3;
    }
    return res1 == res ? res : 0;
}

int main(void)
{
    ll n, step, ans = 0;
    scanf("%lli", &n);
    for (ll i = 0; i < n; i++)
        scanf("%d", a + i);
    step = pow(3, n);
    for (ll i = 0; i <= step; i++)
        ans = max(ans, f(i, n));
    printf("%lli", ans);
    return 0;
}