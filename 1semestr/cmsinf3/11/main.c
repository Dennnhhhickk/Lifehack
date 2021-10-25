#include <stdio.h>
#include <math.h>

typedef long long ll;

ll __gcd(ll a, ll b)
{
    if( b == 0)
        return a;
    a %= b;
    return __gcd(b, a);
}

int main(void)
{
    ll n, a, b, c, d;
    scanf("%lli", &n);
    scanf("%lli%lli", &a, &b);
    for (int i = 1; i < n; i++)
    {
        scanf("%lli%lli", &c, &d);
        a = a * d + c * b;
        b = b * d;
    }
    ll gcd = __gcd(a, b);
    a /= gcd;
    b /= gcd;
    printf("%lli %lli %lli", a / b, a % b, b);
    return 0;
}
