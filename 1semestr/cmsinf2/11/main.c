#include <stdio.h>
#include <string.h>
 
int main(void)
{
    int k = 0, x = 0, y = 0;
    char a[300];
    scanf("%s", a);
    int d[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            d[i][j] = 0;
        }
    }
    int i = 0;
    while (i+1 < strlen(a)) {
                y = a[i] - 'a' + 1;
                x = a[i+1] - '0';
                d[x][y] = 1;
                d[x+1][y] = 1;
                d[x][y+1] = 1;
                d[x+1][y+1] = 1;
                d[x-1][y] = 1;
                d[x][y-1] = 1;
                d[x-1][y-1] = 1;
                d[x-1][y+1] = 1;
                d[x+1][y-1] = 1;
                i += 2;
        }
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (d[i][j] == 0) {
                k++;
            }
        }
    }
    printf ("%d\n", k);
    return 0;
}
