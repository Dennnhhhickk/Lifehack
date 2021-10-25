#include <stdio.h>
#include <time.h>

enum { THURSDAY = 4, BIAS = 1900, LOOP_STEP = 60*60*24 };

int
main(void)
{
    int year;
    scanf("%d", &year);
    time_t time_now = time(NULL);
    struct tm *now = gmtime(&time_now);
    now->tm_sec = 1;
    now->tm_min = 0;
    now->tm_hour = 0;
    now->tm_mday = 1;
    now->tm_mon = 0;
    now->tm_year = year - BIAS;
    now->tm_isdst = -1;
    time_t time_then = timegm(now);
    for (;now = gmtime_r(&time_then, now), now->tm_year == year - BIAS; time_then += LOOP_STEP) {
        if (now->tm_wday == THURSDAY && now->tm_mday % 3 &&
                ((7 < now->tm_mday && now->tm_mday <= 14) ||
                (21 < now->tm_mday && now->tm_mday <= 28))) {
            printf("%d %d\n", now->tm_mon + 1, now->tm_mday);
        }
    }
    return 0;
}
