#include <stdio.h>
 
int ppn(void) {
    char a;
    int rezu, h = 0;
    scanf ("%c", &a);
    if (a == '/') {
        rezu = ppn() / ppn();
        return (rezu);
    }
    else if (a == '*') {
        rezu = ppn() * ppn();
        return (rezu);
    }
    else if (a == ' ') {
        return (ppn());
    }
    else {
        if (a == '-') {
        return (-ppn());
        }
        else {
            while ((a != ' ') && (a != '\n')) {
                h = h * 10 + (a - '0');
                scanf ("%c", &a);
            }
        return (h);
        }
    }
}
int main(void)
{
    int rez;
    rez = ppn();
    printf ("%d", rez);
    return 0;
}
