#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 4096

typedef unsigned long long ull;

void s(char *a, ull length)
{
	char ch;
        int i;
	for (i = 0; i < length - 1; i++)
	{
		scanf("%c", &ch);
		if (ch == '\n' || ch == EOF)
			break;
		a[i] = ch;
	}
	a[i] = '\0';
}

void func(char *a, char *b, char *c)
{
	for (int i = 0; i != 255; i++)
		c[i] = i;
	if (strlen(a) != strlen(b))
		exit(0);
	for (int i = 0; a[i] && b[i]; i++)
		c[(unsigned char)(a[i])] = b[i];
}

void p(char* a, char *b)
{
	int i = 0;
	while(a[i])
	{
		a[i] = b[(unsigned char)a[i]];
		i++;
	}
}

int main(void)
{
	char a[256], b[256], c[256], e[BUF_SIZE], ch;
	s(a, 256);
	s(b, 256);
	func(a, b, c);
	int d;
	scanf("%d%c", &d, &ch);
	for(int i = 0; i < d; i++)
	{
		for (int j = 0; j < BUF_SIZE; j++)
			e[j] = '\0';
		s(e, 4096);
		p(e, c);
		printf("%s\n", e);
	}
	return 0;
}
