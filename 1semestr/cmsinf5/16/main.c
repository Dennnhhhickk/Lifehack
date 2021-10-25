#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#pragma GCC optimize ("-O2")

#define TL for(;;)

typedef long long ll;
typedef unsigned long long ull;

void copy(int *a, int *b, int size)
{
	for (int i = 0; i < size * size; i++)
		*(a + i) = *(b + i);
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(int *a, int k)
{
	for (int i = 0; i < k / 2; i++)
		swap(a + i, a + k - 1 - i);
}

void power(int *A, int *B, int k, int step, int p)
{
	if (step == 1)
	{
		copy(B, A, k);
		return;
	}
	if (step % 2)
	{
		power(A, B, k, step - 1, p);
		int *C = malloc(k * k * sizeof(int));
		for (int i = 0; i < k * k; i++)
			*(C + i) = 0;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				for (int z = 0; z < k; z++)
				{
					*(C + i * k + j) = (*(C + i * k + j) + ((*(A + i * k + z)) * 1ll * (*(B + z * k + j))) % p) % p;
				}
		copy(B, C, k);
		free(C);
	}
	else
	{
		power(A, B, k, step / 2, p);
		int *C = malloc(k * k * sizeof(int));
		for (int i = 0; i < k * k; i++)
			*(C + i) = 0;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				for (int z = 0; z < k; z++)
				{
					*(C + i * k + j) = (*(C + i * k + j) + ((*(B + i * k + z)) * 1ll * (*(B + z * k + j))) % p) % p;
				}
		copy(B, C, k);
		free(C);
	}
}

int main(void)
{
	int k, n, p;
	scanf("%d %d %d", &k, &n, &p);

	int *A = malloc((k + 1) * (k + 1) * sizeof(int));
	int *F = malloc((1 + k) * sizeof(int));

	for (int i = 0; i < k; i++)
		scanf("%d", F + i);

	for (int i = 0; i < k * k; i++)
		*(A + i) = 0;
	for (int i = 0; i < k; i++)
		scanf("%d", A + i);
	for (int i = 0; i < k - 1; i++)
		*(A + (i + 1) * k + i) = 1;

	if (n <= k)
		return printf("%d", F[n - 1] % p), 0;
	reverse(F, k);

	int *B = malloc((1 + k) * (1 + k) * sizeof(int));

	power(A, B, k, n - k, p);
	
	int ans = 0;
	for (int i = 0; i < k; i++)
		ans = (ans + ((*(B + i)) * 1ll * (*(F + i))) % p) % p;
	printf("%d", ans);
	free(B);
	free(A);
	free(F);
	return 0;
}
