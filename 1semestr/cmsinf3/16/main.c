#include <stdio.h>
int st(int a, int b) {
    if (b == 1) {
        return a;
    }
    else if (b == 0) {
        return 1;
    }
    else if (b % 2 == 1) {
        return (st(a, b / 2) * st(a, b / 2) * a);
    }
    else {
        return (st(a, b / 2) * st(a, b / 2));
    }
}
int superst(int a, int b, int m) {
    if (b == 1) {
        return a;
    }
    else if (b == 0) {
        return 1;
    }
    else if (b % 2 == 1) {
        return ((superst(a, b / 2, m) % m) * (superst(a, b / 2, m) % m) * (a % m));
    }
    else {
        return ((superst(a, b / 2, m) % m) * (superst(a, b / 2, m) % m));
    }
}
int main(void)
{
    int a, b, c, m, max, n1, n2, n3, n4, n5, n6;
    scanf ("%d %d %d %d", &a, &b, &c, &m);
    n1 = superst(a,st(b,c),m) % m;
    max = n1;
    n2 = superst(a,st(c,b),m) % m;
    n3 = superst(b,st(c,a),m) % m;
    n4 = superst(b,st(a,c),m) % m;
    n5 = superst(c,st(a,b),m) % m;
    n6 = superst(c,st(b,a),m) % m;
    if (n2 > max) {
        max = n2;
    }
    if (n3 > max) {
        max = n3;
    }
    if (n4 > max) {
        max = n4;
    }
    if (n5 > max) {
        max = n5;
    }
    if (n6 > max) {
        max = n6;
    }
    printf("%d\n", max);
    return 0;
}
