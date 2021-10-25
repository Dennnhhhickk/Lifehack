#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TL for(;;)

typedef long long ll;

int isprime(int a)
{
	for (int i = 2; i <= sqrt(a); i++)
		if (a % i == 0)
			return 0;
	return 1;
}

void rec(int a, int n)
{
	if (n == 0)
	{
		printf("%d ", a);
		return;
	}
	for (int i = 1; i < 10; i++)
		if (isprime(a * 10 + i))
			rec(a * 10 + i, n - 1);
}


int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 2; i < 10; i++)
		if (isprime(i))
			rec(i, n - 1);
    return 0;
}