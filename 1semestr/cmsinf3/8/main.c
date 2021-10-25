#include <stdio.h>
 
int m(int a, int b, int c) {
   int t;
   if (a > b) {
    t = a;
    a = b;
    b = t;
   }
   if (b > c) {
    t = b;
    b = c;
    c = t;
   }
   if (a > b) {
    t = a;
    a = b;
    b = t;
   }
   return (b);
}
int main(void)
{
    int n, l;
    scanf("%d", &n);
    int a[n];
    l = n;
    int b[n-2];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < (l-1)/2; j++){
       for (int i = 0; i < n - 2; i++) {
            b[i] = m(a[i], a[i+1], a[i+2]);
       }
       for (int k = 0; k < n - 2; k++) {
           a[k] = b[k];
       }
       n = n - 2;
    }
    printf("%d\n", a[0]);
    return 0;
}
