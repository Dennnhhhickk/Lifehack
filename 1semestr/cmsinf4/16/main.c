#include <stdio.h>
#include <math.h>
#include <string.h>

typedef long long ll;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void out(int d, char* a)
{
    int n = strlen(a);
    for (int i = 0; i < n; i++)
        printf("%c", a[(n + (i + d) % n) % n]);
    printf("\n");
}

int check(char* a, int b, int c, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[(b + i) % n] < a[(c + i) % n])
            return b;
        else
            if (a[(b + i) % n] > a[(c + i) % n])
                return c;
    }
    return b;
}

int main(void)
{
    char a[2000002];
    int b[2000002];
    scanf("%s", a);

    int tmp = 0, n = strlen(a);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '0')
            tmp++;
        else
        {
            b[i - tmp] = tmp;
            tmp = 0;
        }
    }

    b[n - tmp] = tmp;

    int ans = 0, ansi = 0, last = 0, lasti = 0;

    for (int i = 0; i < n; i++)
    {
        if (b[i])
        {
            if (ans <= b[i])
            {
                if (ans == b[i])
                    ansi = check(a, ansi, i, n);
                else
                    ansi = i;
                ans = b[i];
            }
            last = b[i];
            lasti = i;
        }
    }

    if (b[0] && last + lasti == n && ans <= last + b[0])
    {
        if (ans == last + b[0])
            ansi = check(a, ansi, lasti, n);
        else
            ansi = lasti;
        ans = last + b[0];
    }

    out(ansi, a);

    return 0;
}


/*

0001000111
1000100011
1100010001
1110001000

*/