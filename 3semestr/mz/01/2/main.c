#include <stdio.h>

enum
{
    UNREAD_SIGN = -1,
    FIRST_NUM = 1,
    FIRST_SML_LTR = '9' - '0' + 1 + FIRST_NUM,
    FIRST_LRG_LTR = 'z' - 'a' + 1 + FIRST_SML_LTR,
    MAX_NUM = 'Z' - 'A' + 1 + FIRST_LRG_LTR,
};

int
char_to_num(int ch)
{
    if ('0' <= ch && ch <= '9') {
        return ch - '0' + FIRST_NUM;
    }
    if ('a' <= ch && ch <= 'z') {
        return ch - 'a' + FIRST_SML_LTR;
    }
    if ('A' <= ch && ch <= 'Z') {
        return ch - 'A' + FIRST_LRG_LTR;
    }
    return UNREAD_SIGN;
}

int
num_to_char(int ch)
{
    if (ch < FIRST_NUM) {
        return '@';
    }
    if (ch < FIRST_SML_LTR) {
        return ch - FIRST_NUM + '0';
    }
    if (ch < FIRST_LRG_LTR) {
        return ch - FIRST_SML_LTR + 'a';
    }
    if (ch < MAX_NUM) {
        return ch - FIRST_LRG_LTR + 'A';
    }
    return '#';
}

int
main(void)
{
    int ch;
    while (ch = getchar(), ch != EOF) {
        ch = char_to_num(ch);
        if (ch != UNREAD_SIGN) {
            ch ^= 8;
            ch &= ~(4);
            ch = num_to_char(ch);
            putchar(ch);
        }
    }
    printf("\n");
    return 0;
}
