#include <stdio.h>
 
int main(void)
{
    int n, m;
    scanf ("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a[i]);
    }
    scanf ("%d", &m);
    int b[m];
    for (int i = 0; i < m; i++) {
        scanf ("%d", &b[i]);
    }
    if (n < m) {
        for (int i = 0; i < 2*n; i++) {
            if (i % 2 == 0) {
                    printf("%d ", a[i/2]);
            }
            else {
                printf("%d ", b[i/2]);
            }
        }
        for (int i = n; i < m; i++) {
            printf ("%d ", b[i]);
        }
    }
    else {
            for (int i = 0; i < 2*m; i++) {
            if (i % 2 == 0) {
                    printf("%d ", a[i/2]);
            }
            else {
                printf("%d ", b[i/2]);
            }
        }
        for (int i = m; i < n; i++) {
            printf ("%d ", a[i]);
        }
    }
    return 0;
}
