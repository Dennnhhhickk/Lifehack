#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    long long sum_positive = 0;
    long long sum_negative = 0;
    for (int i = 1; i < argc; i++) { 
        char *end;
        long long tmp = strtoll(argv[i], &end, 10);
        if (tmp < 0) {
            sum_negative += tmp;
        } else {
            sum_positive += tmp;
        }
    }
    printf("%lli\n%lli\n", sum_positive, sum_negative);
    return 0;
}
