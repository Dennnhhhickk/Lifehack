#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, ans = 0, a, b;
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            scanf("%d %d", &a, &b);
            ans += a * b;
        }
    }
    printf("%d \n", ans);
    return 0;
}
