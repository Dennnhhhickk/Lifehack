#include <stdio.h>
#include <string.h>
 
char vol[] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
 
int volume(char sign) {
    for (int i = 0; i < strlen(vol); i++) {
        if (sign == vol[i]) {
            return 1;
        }
    }
    return 0;
}
int main(void)
{
    char hokku[120];
    char hokku2[10000][120];
    int n, k = 0, m = 0;
    scanf ("%d ", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf ("%d ", &a[i]);
    }
    for (int i = 0; i < sizeof(hokku); ++i) {
        hokku[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        fgets (hokku, sizeof(hokku), stdin);
        for (int j = 0; j < sizeof(hokku); ++j) {
            if ((volume(hokku[j]) == 1) && (volume(hokku[j+1]) == 0)) {
                ++k;
            }
        }
        if (k == a[i]) {
            for (int i = 0; i < 120; ++i) {
                hokku2[m][i]= hokku[i];
            }
        ++m;
        }
        for (int i = 0; i < sizeof(hokku); ++i) {
            hokku[i] = 0;
        }
        k = 0;
    }
    for (int j = 0; j < m; ++j) {
        fputs(hokku2[j], stdout);
    }
    return 0;
}
