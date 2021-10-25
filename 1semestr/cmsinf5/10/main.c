#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TL for(;;)

typedef long long ull;
typedef unsigned long long ll;

const int N = 100100;
const int count = 8;

ll power[15];
char c;

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int copy(int *a, int *b, int bb)
{
	for (int i = 0; i < bb; i++)
		a[i] = b[i];
	return bb;
}

void swapint(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(int *a, int aa, int *b, int bb)
{
	for (int i = 0; i < max(aa, bb); i++)
		swapint(a + i, b + i);
}

void out(int *a, int aa)
{
	printf("%d", a[aa - 1]);
	for (int i = 1; i < aa; i++)
	{
		for (int j = count - 1; j >= 0; j--)
			printf("%lli", (a[aa - 1 - i] % power[j + 1]) / power[j]);
	}
}

int plus(int *a, int aa, int *b, int bb)
{
	ll d = 0, tmp;
	aa = max(aa, bb);
	for (int i = 0; i < aa; i++)
	{
		tmp = a[i] + b[i] + d;
		d = tmp / power[count];
		a[i] = tmp % power[count];
	}
	while (d)
	{
		a[aa] = d % power[count];
		aa++;
		d /= power[count];
	}
	return aa;
}

int smes(int *a, int aa, int smes)
{
	for (int i = 0; i < aa; i++)
		a[min(N, aa - 1 + smes - i)] = a[min(N, aa - 1 - i)];

	for (int i = 0; i < smes; i++)
		a[i] = 0;

	return aa + smes;
}

int prodnum(int *a, int aa, int b, int *c, int cc)
{
	ll d = 0, tmp;
	cc = aa;
	for (int i = 0; i < cc; i++)
	{
		tmp = a[i] * 1ll * b + d;
		d = tmp / power[count];
		c[i] = tmp % power[count];
	}
	while (d)
	{
		c[cc] = d % power[count];
		cc++;
		d /= power[count];
	}
	return cc;
}

int product(int *a, int aa, int *b, int bb)
{
	int ans[N], c[N], anss = 0, cc = 0;
	for (int i = 0; i < N; i++)
	{
		ans[i] = 0;
		c[i] = 0;
	}
	for (int i = 0; i < bb; i++)
	{
		for (int j = 0; j < cc; j++)
			c[j] = 0;
		cc = 0;

		cc = prodnum(a, aa, b[i], c, cc);
		cc = smes(c, cc, i);
		anss = plus(ans, anss, c, cc);
	}
	aa = copy(a, ans, anss);
	int k = -1;
	for (int i = 0; i < aa - 1; i++)
		if (!a[aa - 1 - i])
			k = i;
		else
			break;
	return aa - k - 1;
}

int check(int *a, int aa, int *b, int bb)
{
	for (int i = 0; i < aa; i++)
	{
		if (a[aa - 1 - i] == b[bb - 1 - i])
			continue;
		if (a[aa - 1 - i] < b[bb - 1 - i])
			return 1;
		if (a[aa - 1 - i] > b[bb - 1 - i])
			return 0;
	}
	return 0;
}

int minus(int *a, int aa, int *b, int bb)
{
	int bol = 0;
	if (aa < bb || (aa == bb && check(a, aa, b, bb)))
	{
		swap(a, aa, b, bb);
		swapint(&aa, &bb);
		bol = 1;
	}
	ll d = 0;
	for (int i = 0; i < aa; i++)
	{
		a[i] -= d;
		d = 0;
		if (a[i] < b[i])
		{
			a[i] = power[count] + a[i] - b[i];
			d = 1;
		}
		else
			a[i] -= b[i];
	}
	int k = -1;
	for (int i = 0; i < aa - 1; i++)
		if (!a[aa - 1 - i])
			k = i;
		else
			break;
	if (bol)
		a[aa - 1 - (k + 1)] *= -1;
	return aa - k - 1;
}

int in(int *a)
{
	for (int i = 0; i < N; i++)
		a[i] = 0;
	int num = 0, ssize = 1;
	char *s = malloc(sizeof(char));
	while ((c = getchar()) != '+' && c != '-' && c != '*' && c != '\n')
	{
		s[num] = c;
		num++;
		if (num == ssize)
		{
			s = realloc(s, 2 * ssize * sizeof(char));
			ssize *= 2;
		}
	}
	for (int i = 0; i < num / 2; i++)
	{
		char tmp = *(s + i);
		*(s + i) = *(s + num - 1 - i);
		*(s + num - 1 - i) = tmp;
	}
	int size = 0, dig = 0;
	for (int i = 0; i < num; i++)
	{
		if (dig == count)
		{
			size++;
			dig = 0;
		}
		a[size] += (s[i] - '0') * power[dig];
		dig++;
	}
	free(s);
	return size + 1;
}

int main(void)
{

	power[0] = 1;
	for (int i = 1; i < 15; i++)
		power[i] = power[i - 1] * 10;

	int *a = malloc(N * sizeof(int)), *b = malloc(N * sizeof(int)), aa, bb;
	char ch;

	aa = in(a);
	ch = c;
	bb = in(b);




	switch(ch)
	{
		case '+':
			aa = plus(a, aa, b, bb);
			break;
		case '*':
			aa = product(a, aa, b, bb);
			break;
		case '-':
			aa = minus(a, aa, b, bb);
			break;
		default:
			break;
	}
	out(a, aa);
	free(a);
	free(b);
    return 0;
}