#include <stdio.h>

extern int
parse_rwx_permissions(const char *str);

int main()
{
    char str[256];
    while (scanf("%s", str) != EOF) {
        printf("%s = %o\n", str, parse_rwx_permissions(str));
    }
    printf("\"rwxrwxrwx \" = %d\n", parse_rwx_permissions("rwxrwxrwx "));
    return 0;
}
