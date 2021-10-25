#include <stdio.h>
#include <stdlib.h>

extern char *
relativize_path(const char *, const char *);

enum { N = 4096 };

int
main()
{
    char str1[N], str2[N];
    scanf("%s %s", str1, str2);
    char *str3 = relativize_path(str1, str2);
    printf("|%s|\n", str3);
    free(str3);
    return 0;
}