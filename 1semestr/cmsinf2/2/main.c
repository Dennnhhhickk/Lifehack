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
    ll a[10000], b, k = 0;
    scanf("%lli", &b);
    while (b != 0)
    {
        a[k] = b;
        k++;
        scanf("%lli", &b);
    }
    for (int i = 0; i < k; i += 2)
        printf("%lli ", a[i]);
    k--;
    for (int i = (k / 2) * 2 - 1 + 2 * (k % 2); i >= 0; i -= 2)
        printf("%lli ", a[i]);
    return 0;
}
