#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum { OCT = 8 };

const char STR[] = "rwxrwxrwx";

enum { STR_LEN = sizeof(STR) - 1 };

int
main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        char *end;
        char res[STR_LEN + 1] = "---------";
        long tmp = strtol(argv[i], &end, OCT);
        for (int j = 0; j < STR_LEN; j++) {
            if (tmp & (1 << (STR_LEN - 1 - j))) {
                res[j] = STR[j];
            }
        }
        puts(res);
    }
    return 0;
}
