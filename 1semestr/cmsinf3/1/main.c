#include <stdio.h>
 
int evk(int x, int y) {
   int t;
   while (y != 0) {
      t = x % y;
      x = y;
      y = t;
   }
   return (x >= 0 ? x : -x);
}
int main(void)
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", evk(evk(evk(a, b), c), d));
    return 0;
}
