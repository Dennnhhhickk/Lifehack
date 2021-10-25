#include <stdio.h>
int m[15];
int n,k;
 
void func_leks (int a, int b, int c){
        if (b == 0) {
            for (int i = 0; i < k; ++i) {
                printf ("%d ", m[i]);
            }
            printf ("\n");
        }
        else {
            for (int i = a + 1; i <= (c - b); ++i) {
                m[k-b] = i;
                func_leks (i, b - 1, c);
            }
        }
}
int main(void)
{
    scanf ("%d %d", &n, &k);
    func_leks (-1, k, n);
    return 0;
}
