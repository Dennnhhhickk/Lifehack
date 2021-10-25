#include <time.h>
#include <stdio.h>

int mons[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int
main()
{
    int year, mon, day, n;
    scanf("%d-%d-%d %d", &year, &mon, &day, &n);
    time_t sec = time(NULL);
    struct tm *buf = gmtime(&sec);
    for (int i = 0; i < 2 * n; i++) {
        buf->tm_year = year - 1900;
        buf->tm_mon = mon - 1 + 6 * (i + 1);
        buf->tm_mday = day;
        buf->tm_sec = 1;
        buf->tm_min = 0;
        buf->tm_hour = 0;
        sec = timegm(buf);
        sec = timegm(buf);
        buf = gmtime_r(&sec, buf);
        if (buf->tm_wday == 0) {
            sec += 24 * 60 * 60;
            buf = gmtime_r(&sec, buf);
            printf("%04d-%02d-%02d\n", buf->tm_year + 1900, buf->tm_mon + 1, buf->tm_mday);
            sec -= 24 * 60 * 60;
            buf = gmtime_r(&sec, buf);
        } else if (buf->tm_wday == 6) {
            sec += 2 * 24 * 60 * 60;
            buf = gmtime_r(&sec, buf);
            printf("%04d-%02d-%02d\n", buf->tm_year + 1900, buf->tm_mon + 1, buf->tm_mday);
            sec -= 2 * 24 * 60 * 60;
            buf = gmtime_r(&sec, buf);
        } else {
            printf("%04d-%02d-%02d\n", buf->tm_year + 1900, buf->tm_mon + 1, buf->tm_mday);
        }
    }
    return 0;
}