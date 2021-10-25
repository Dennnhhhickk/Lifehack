#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TL for(;;)

typedef unsigned long long ull;
typedef long long ll;

int bol;

union N
{
	int i;
	char ch[2];
};

union IN
{
	int i;
	char ch[4];
};

union UL
{
	ll i;
	char ch[8];
};

FILE *cin, *cout;

void startt(void)
{
	while ((cin = fopen("matrix.in", "rb")) == NULL)
	{
		printf("Cannot open file 1.\n");
		exit(228);
	}

	while ((cout = fopen("trace.out", "w")) == NULL)
	{
		printf("Cannot open file 2.\n");
		exit(228);
	}
}

void endd(void)
{
	fclose(cin);
	fclose(cout);
}

int main(void)
{
	startt();

	union N n;

	n.i = 0;

	fread(&(n.ch[1]), sizeof(char), 1, cin);			
	fread(&(n.ch[0]), sizeof(char), 1, cin);

	union IN a[2010][2010];

	for (int i = 0; i < n.i; i++)
		for (int j = 0; j < n.i; j++)
		{
			for (int z = 0; z < 4; z++)
				fread(&(a[i][j].ch[3 - z]), sizeof(char), 1, cin);
		}

	union UL ans;
	ans.i = 0;

	for (int i = 0; i < n.i; i++)
		ans.i += a[i][i].i;

	for (int i = 0; i < 8; i++)
		fwrite(&(ans.ch[7 - i]), sizeof(char), 1, cout);

	endd();

    return 0;
}