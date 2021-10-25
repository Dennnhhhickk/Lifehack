#include <stdio.h>
 
int main(void)
{
    int n, t, k = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == (i + 1)) {
                k++;
        }
    }
    if (k == n) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    return 0;
}
