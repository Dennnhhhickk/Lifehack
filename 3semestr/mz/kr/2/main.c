#include <stdio.h>

void
processing(char *str)
{
    char s[8196] = "";
    size_t len = strlen(str);
    FILE *input = fopen(str, "r");
    char ch;
    while (fscanf(input, "%c", &ch)) {
        if (isspace((unsigned char)ch))
    }
}

int
main()
{
    char str[1024] = "";
    char ch;
    int cnt = 0;
    while (scanf("%c", ch) != EOF) {
        if (ch == '\n') {
            processing(str);
        } else {
            str[cnt] = ch;
            str[cnt + 1] = '\0';
        }
    }
    return 0;
}