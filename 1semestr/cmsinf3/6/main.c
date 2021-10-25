#include <stdio.h>
#include <math.h>

long long f(long long n)
{
    if (n <= 3)
        return n;
    if (n % 2)
        return f(n + 3) * 2;
    return 3 + f(n / 2);
}

int main(void)
{
    long long n;
    scanf("%lli", &n);
    printf("%lli\n", f(n));
    return 0;
}