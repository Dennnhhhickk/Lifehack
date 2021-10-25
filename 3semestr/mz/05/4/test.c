#include <stdio.h>

const char str[] = "rwxrwxrwx";

void
tostr(int a)
{
    for (int i = 0; i < 9; i++) {
        if (a & (1 << (8 - i))) {
            printf("%c", str[i]);
        } else {
            printf("-");
        }
    }
    printf("\n");
}

int main()
{
    int N = 1 << 9;
    for (int i = 0; i < N; i++) {
        tostr(i);
    }
    return 0;
}
