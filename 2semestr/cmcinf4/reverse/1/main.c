#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TL for(;;)

unsigned int f(unsigned int a)
{
    unsigned int ans = 1;
    for (int i = 0; i < a; i++)
        ans *= 3;
    return ans;
}

int main(void)
{
    unsigned int a;
    scanf("%u", &a);
    a = f(a);
    printf("%u\n", a);
    return 0;
}
