#include <stdio.h>
#include <stdlib.h>

enum { MAX_N = 2000 };

int
main(void)
{
    int n, mod;
    scanf("%d", &n);
    if (n < 2 || n >= MAX_N) {
        fprintf(stderr, "Incorrectly entered N");
        exit(1);
    }
    int **table = calloc(n, sizeof(*table));
    if (table == NULL) {
        fprintf(stderr, "Memory allocation error");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        table[i] = calloc(n, sizeof(**table));
        if (table[i] == NULL) {
            fprintf(stderr, "Memory allocation error");
            exit(1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            mod = (i * j) % n;
            table[mod][i] = j;
            table[mod][j] = i;
        }
    }
    for (int i = 0; i < n; i++, printf("\n")) {
        for (int j = 1; j < n; j++) {
            printf("%d ", table[i][j]);
        }
    }
    return 0;
}
