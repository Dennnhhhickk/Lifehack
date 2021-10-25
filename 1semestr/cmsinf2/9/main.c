#include <stdio.h>
 
int main(void)
{
    int n, m, k, z = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf ("%d", &m);
    int b[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    for (int j = m-1; j >= 0; j--) {
        k = b[j];
        z = a[0];
        for (int i = 1; i < n; i++) {
        z = z + a[i]*k;
        k = k * b[j];
        }
        printf("%d ", z);
    }
    return 0;
}
