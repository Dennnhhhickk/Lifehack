#include <stdio.h>
#include <math.h>

int isprime(long long a)
{
    for (long long i = 2; i * i <= a; i++)
        if (a % i == 0)
            return 0;
    return 1;
}

int main(void)
{
    long long n;
    scanf("%lli", &n);
    if (n == 1)
        return printf("2\n"), 0;
    for (long long i = 0; ; i++)
        if (isprime(n + i))
            return printf("%lli\n", n + i), 0;
    return 0;
}