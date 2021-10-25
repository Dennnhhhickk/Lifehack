#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum { NBYTES = 16, DEC = 10 };

unsigned long long
handler(char *str, int size, unsigned long long sum, unsigned long long *prev, char *sign_prev)
{
    unsigned long long tmp = *prev;
    char sign = *sign_prev;
    for (int i = 0; i < size; i++) {
        if (isspace((unsigned char)str[i])) {
            if (sign) {
                sum -= tmp;
            } else {
                sum += tmp;
            }
            tmp = 0;
            sign = 0;
        } else if (str[i] == '-' || str[i] == '+') {
            sign = 0;
            if (str[i] == '-') {
                sign = 1;
            }
        } else if (isdigit((unsigned char)str[i])) {
            tmp = tmp * (unsigned long long)DEC 
                    + (unsigned char)str[i] - (unsigned char)'0';
        }
    }
    *prev = tmp;
    *sign_prev = sign;
    return sum;
}

int
main(void)
{
    char buf[NBYTES] = "", sign_prev = 0;
    unsigned long long answer = 0, prev = 0;
    int readed;
    while (readed = read(0, buf, NBYTES), readed != 0) {
        answer = handler(buf, readed, answer, &prev, &sign_prev);
    }
    if (sign_prev) {
        answer -= prev;
    } else {
        answer += prev;
    }
    printf("%lli\n", answer);
    return 0;
}
