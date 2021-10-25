#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TL for(;;)

typedef unsigned long long ull;
typedef long long ll;

FILE *cin, *cout;

void startt(void)
{
	while ((cin = fopen("input.txt", "r")) == NULL)
	{
		// printf("Cannot open file.\n");
		exit(228);
	}

	while ((cout = fopen("output.txt", "w")) == NULL)
	{
		// printf("Cannot open file.\n");
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

	ll ans = 0, cnt = 0;
	char ch[2], lst = '|';
	int bol = 0;

	while (fread(ch, sizeof(char), 1, cin))
	{
		if ('0' <= ch[0] && ch[0] <= '9')
		{
			if (!bol)
			{
				cnt = 0;
				bol = 1;
			}
			cnt = cnt * 10 + ch[0] - '0';
		}
		else
		{
			bol = 0;
			if (ch[0] == '+' || ch[0] == '-' || ch[0] == '\n')
			{
				if (lst != '|')
				{
					if (lst == '+')
						ans += cnt;
					else
						ans -= cnt;
				}
				else
					ans = cnt;
				lst = ch[0];
			}

		}
	}

	fprintf(cout, "%lli", ans);

	endd();
    return 0;
}