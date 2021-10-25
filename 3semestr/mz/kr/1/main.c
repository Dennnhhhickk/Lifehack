#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
check(char *str)
{
    size_t len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isdigit((unsigned char)str[i]) || 'a' > str[i] || str[i] > 'z' || str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int
main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (check(argv[i])) {
            printf("%s\n", argv[i]);
        }
    }
    return 0;
}