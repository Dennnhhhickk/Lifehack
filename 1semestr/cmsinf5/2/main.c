#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

void copy(int *a, int *b, int n)
{
	for (int i = 0; i < n * n; i++)
		*(a + i) = *(b + i);
}

int main(void)
{
	int n;
	int *ans = malloc(1 * sizeof(int));
	ll sumans = 0, anssize = 0;
	scanf("%d", &n);
	for (int j = 0; j < n; j++)
	{
		int m;
		scanf("%d", &m);

		int* a = (int*) malloc(m * m * sizeof(int));
		for (int i = 0; i < m * m; i++)
			scanf("%d", a + i);
		ll sum = 0;
		for (int i = 0; i < m; i++)
			sum += *(a + m * i + i);

		if (sumans < sum || j == 0)
		{
			ans = (int*) realloc(ans, m * m * sizeof(int));
			sumans = sum;
			copy(ans, a, m);
			anssize = m;
		}

		free(a);
	}
	for (int i = 0; i < anssize; i++, printf("\n"))
		for (int j = 0; j < anssize; j++)
			printf("%d ", *(ans + i * anssize + j));
	free(ans);
    return 0;
}