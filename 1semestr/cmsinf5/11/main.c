#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TL for(;;)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

ull n, m;
ull **a, **ans;

ull max(ull a, ull b)
{
	if (a > b)
		return a;
	return b;
}

int main(void)
{
	scanf("%llu %llu", &n, &m);
	a = malloc(n * sizeof(ull*));
	for (int i = 0; i < n; i++)
		a[i] = malloc(m * sizeof(ull));
	ans = malloc(n * sizeof(ull*));
	for (int i = 0; i < n; i++)
		ans[i] = malloc(m * sizeof(ull));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%llu", &a[i][j]);
			ans[i][j] = 0;
		}

	for (int i = 0; i < n; i++)
		ans[i][0] = a[i][0];

	for (int j = 1; j < m; j++)
		for (int i = 0; i < n; i++)
		{
			if (i)
				ans[i][j] = max(ans[i][j], ans[i - 1][j - 1]);
			ans[i][j] = max(ans[i][j], ans[i][j - 1]);
			if (i < n - 1)
				ans[i][j] = max(ans[i][j], ans[i + 1][j - 1]);
			ans[i][j] += a[i][j];
		}

	// for (int i = 0; i < n; i++, printf("\n"))
	// 	for (int j = 0; j < m; j++)
	// 		printf("%llu ", ans[i][j]);

	// for (int i = 0; i < n; i++, printf("\n"))
	// 	for (int j = 0; j < m; j++)
	// 		printf("%llu ", a[i][j]);

	ull answer = 0;
	for (int i = 0; i < n; i++)
		answer = max(answer, ans[i][m - 1]);
	printf("%llu", answer);
    return 0;
}

/*


*/