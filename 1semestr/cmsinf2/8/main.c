#include <stdio.h>
#include <math.h>

#define sqr(a) ((a) * (a))

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

int main(void)
{
    ll n, a[4000], ans = 0;
    scanf("%lli", &n);
    for (int i = 0; i < n; i++)
        scanf("%lli", a + i);
    for (int i = 0; i < n; i++)
        for (int j = i + 2; j < n; j++)
            if ((i + j) % 2 == 0 && a[i] + a[j] == 2 * a[(i + j) / 2])
                ans++;
    printf("%lli", ans);
    return 0;
}
