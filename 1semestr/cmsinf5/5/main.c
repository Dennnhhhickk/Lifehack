#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TL for(;;)

typedef long long ll;

void copy(char *a, char *b, int n)
{
	a = realloc(a, n * sizeof(char));
	for (int i = 0; i < n; i++)
		*(a + i) = *(b + i);
}

void update(char *a, int size)
{
	a = realloc(a, size * 2);
}

void concat(char *a, int m, char *b, int n)
{
	for (int i = 0; i < n; i++)
		*(a + i + m) = *(b + i);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	n++;
	char *a[3] = {0};
	// char c = getchar();
	/*
	for (int i = 0; i < 3; i++)
	{
		char *b = malloc(sizeof(char));
		int len = 0, size = 1;
		while ((c = getchar ()) != '\n')
		{
			*(b + len) = c;
			len++;
			if (len == size)
				update(b, size);
		}
		a[i] = realloc(a[i], len);
		copy(a[i], b, len);
	}
	*/
	/*
	c = getchar();
	for (int j = 0; j < 3; j++)
	{
		char *b = malloc(n * sizeof(char));
		*b = c;
		for (int i = 1; i < n; i++)
		{
			c = getchar();
			*(b + i) = c;
		}
		a[j] = malloc(n * sizeof(char));
		copy(a[j], b, n);
		while(j != 2 && ((c = getchar()) == ' ' || c == '\n'));
		free(b);
	}
	*/

	for (int i = 0; i < 3; i++)
	{
		a[i] = malloc(n * sizeof(char));
		scanf("%s", a[i]);
	}

	int g[] = {2, 0, 1};

	char *ans = malloc(3 * n * sizeof(char));
	for (int i = 0; i < 3; i++)
		concat(ans, i * n, a[g[i]], n);

	printf("%s%s%s", a[2], a[0], a[1]);
	free(ans);
    return 0;
}