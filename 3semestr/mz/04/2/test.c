#include <stdio.h>

int
reverse(int a)
{
    int res = 0;
    for (int i = 0; i < 4; i++) {
        res <<= 8;
        res |= a & ((1 << 8) - 1);
        a >>= 8;
    }
    return res;
}

int main()
{
    FILE *f = fopen("input", "wb");
    int tmp;
    char str[16] = "";
    while (scanf("%d", &tmp) != EOF) {
        fwrite(str, sizeof(str), 1, f);
        tmp = reverse(tmp);
        fwrite(&tmp, sizeof(tmp), 1, f);
    }
    fclose(f);
    return 0;
}