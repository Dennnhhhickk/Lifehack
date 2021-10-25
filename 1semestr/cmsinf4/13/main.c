#include <stdio.h>
#include <math.h>
#include <string.h>

typedef long long ll;

ll min (ll a, ll b)
{
    if (a < b)
        return a;
    return b;
}

int main(void)
{
    char a[1000010];
    ll z[1000010] = {0}, n;
    scanf("%s", a);

    n = strlen(a);

    z[0] = 0;

    ll l = 0, r = 0;

    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        for (; i + z[i] < n && a[z[i]] == a[i + z[i]];)
            z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }

    for(int i = 0; i <= n; i++)
        if (z[i] + i == n)
            printf("%d ", i);

    printf("\n");
    return 0;
}