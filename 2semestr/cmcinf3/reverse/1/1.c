#include <stdio.h>
#include <stdlib.h>

void swap(unsigned int *a, unsigned int *b)
{
    unsigned int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int n;
    unsigned int a = 0, b = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        swap(&a, &b);
        b += a;
    }
    printf("%u", a);
    return 0;
}
