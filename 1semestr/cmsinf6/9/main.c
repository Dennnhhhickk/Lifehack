#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TL for(;;)

typedef unsigned long long ull;
typedef long long ll;

int bol;

FILE *cin, *cout;

void startt(void)
{
	while ((cin = fopen("input.bin", "rb")) == NULL)
	{
		printf("Cannot open file.\n");
		exit(228);
	}

	while ((cout = fopen("output.bin", "wb")) == NULL)
	{
		printf("Cannot open file.\n");
		exit(228);
	}
}

void endd(void)
{
	fclose(cin);
	fclose(cout);
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int check(int v, int *a, int k)
{
	if (v * 2 < k && v * 2 + 1 < k)
	{
		int ans = 2;
		if (a[v * 2] < a[v] && a[v * 2 + 1] < a[v])
			ans = -1;
		if (a[v * 2] > a[v] && a[v * 2 + 1] > a[v])
			ans = 1;
		if ((a[v * 2] < a[v] && a[v * 2 + 1] > a[v]) || (a[v * 2 + 1] < a[v] && a[v * 2] > a[v]))
			ans = 0;
		int ans1 = check(v * 2, a, k);
		int ans2 = check(v * 2 + 1, a, k);
		// printf("%d %d %d %d\n",v, ans, ans1, ans2);
		if (ans1 == ans2 && ans1 == ans)
			return ans;
		if (ans1 == -ans2 || ans1 == -ans || ans == -ans2)
			return 0;
		if (!(ans && ans1 && ans2))
			return 0;
		if (ans != 2)
			return ans;
		if (ans1 != 2)
			return ans1;
		return ans2;
	}
	else
		if (v * 2 < k)
		{
			return check(v * 2, a, k);
		}
		else
			if (v != 1)
				return (a[v] < a[v / 2] ? -1 : (a[v] == a[v / 2] && bol ? 2 : 1));
			else
				return 1;
}

int main(void)
{
	bol = 0;
	startt();

	int tmp, *a = malloc(sizeof(int) * 2), size = 2, k = 1;
	while (fread(&tmp, sizeof(int), 1, cin))
	{
		if (k == size)
		{
			size *= 2;
			a = realloc(a, sizeof(int) * size);
		}
		a[k] = tmp;
		if (a[k] != a[1])
			bol = 1;
		k++;
	}

	tmp = check(1, a, k);

	// printf("%d\n", tmp);

	fwrite(&tmp, sizeof(int), 1, cout);

	free(a);

	endd();

    return 0;
}