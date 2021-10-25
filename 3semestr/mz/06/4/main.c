#include <stdio.h>
#include <time.h>

enum { HOUR24 = 24 * 60 * 60, DAYS = 30, MONS = 12 };

int
main(void)
{
    time_t now = time(NULL);
    struct tm *first = gmtime(&now);
    first->tm_year = 25;
    first->tm_mday = 7;
    first->tm_mon = 9;
    first->tm_sec = 0;
    first->tm_min = 0;
    first->tm_hour = 0;
    first->tm_isdst = -1;
    time_t first_sec = timegm(first);
    int year, mon, day;
    while (scanf("%d %d %d", &year, &mon, &day) != EOF) {
        first->tm_year = year - 1900;
        first->tm_mon = mon - 1;
        first->tm_mday = day;
        long long that_moment = timegm(first);
        that_moment -= first_sec;

        if (that_moment >= 0) {
            year = (that_moment) / (HOUR24 * DAYS * MONS);
            that_moment %= (HOUR24 * DAYS * MONS);
            mon = (that_moment / (HOUR24 * DAYS)) % MONS;
            that_moment %= (HOUR24 * DAYS);
            day = (that_moment / HOUR24) % DAYS;
        } else {
            for(;;);
        }

        printf("%d %d %d\n", year + 1, mon + 1, day + 1);
    }
    return 0;
}
