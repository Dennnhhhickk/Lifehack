#include <stdio.h>

const double LSIDE = 1.0;
const double RSIDE = 7.0;
const double TSIDE = 5.0;
const double BSIDE = 2.0;
const double COORD_SUM = 10.0;

int
main(void)
{
    double x, y;
    scanf("%lf%lf", &x, &y);
    int answer = LSIDE <= x && x <= RSIDE && BSIDE <= y && y <= TSIDE && x + y <= COORD_SUM;
    printf("%d\n", answer);
    return 0;
}
