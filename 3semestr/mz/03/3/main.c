#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

enum { DEC = 10, PERC = 100, POINT = 10000 };

int
main(int argc, char *argv[])
{
    char *end;
    double answer = strtod(argv[1], &end);
    double tmp;
    for (int i = 2; i < argc; i++) {
        tmp = strtod(argv[i], &end);
        answer += answer * tmp / PERC;
        answer = round(answer * POINT) / POINT;
    }
    printf("%.4lf\n", answer);
    return 0;
}
