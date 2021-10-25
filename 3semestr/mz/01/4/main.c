#include <ctype.h>

int
mystrspccmp(const char *p1, const char *p2)
{
    while (1) {
        while (isspace((unsigned char)*p1)) {
            p1++;
        }
        while (isspace((unsigned char)*p2)) {
            p2++;
        }
        if (*p1 == *p2 && *p1 != '\0') {
            p1++;
            p2++;
        } else {
            return (unsigned char) *p1 - (unsigned char) *p2;
        }
    }
}
