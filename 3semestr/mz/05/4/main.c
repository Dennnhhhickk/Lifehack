#include <stdio.h>
#include <string.h>

const char STR[] = "rwxrwxrwx";

enum { ERROR_CODE = -1};

int
parse_rwx_permissions(const char *str)
{
    if (str == NULL) {
        fprintf(stderr, "Str indicates NULL\n");
        return ERROR_CODE;
    }
    size_t len = strlen(STR);
    int res = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] != STR[i] && str[i] != '-') {
            fprintf(stderr, "Invalid character\n");
            return ERROR_CODE;
        } else if (str[i] == STR[i] && str[i] != '\0') {
            res |= 1 << (len - 1 - i);
        }
    }
    return res;
}
