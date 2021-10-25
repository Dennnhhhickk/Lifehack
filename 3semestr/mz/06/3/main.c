#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
cpy(const char *str)
{
    char *result = malloc(sizeof(char) * (strlen(str) + 1));
    int len = strlen(str);
    for (int i = 0; i <= len; i++) {
        result[i] = str[i];
    }
    return result;
}

void
rewrite(char *str, int step)
{
    int len = strlen(str);
    for (int i = 0; i <= len - step; i++) {
        str[i] = str[i + step];
    }
}

void
reverse(char *str)
{
    for (int i = 0; i < strlen(str) / 2; i++) {
        char tmp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = tmp;
    }
}

int
equal(const char *a, const char *b)
{
    if (strlen(a) < strlen(b)) {
        return -1;
    }
    for (int i = 0; i < strlen(b); i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

char *
normalized(char *str)
{
    // s1/./s2 -> s1/s2
    for (int i = 0; i < (int)strlen(str) - 2; i++) {
        if (equal(&str[i], "/./") == 1) {
            rewrite(&str[i], 2);
            i--;
        }
    }
    // s1/s2/../s3 -> s1/s3
    reverse(str);
    for (int i = 0; i < strlen(str); i++) {
        if (equal(&str[i], "/../") == 1 && equal(&str[i + 3], "/../") != 1 && strlen(&str[i + 4])) {
            int j;
            for (j = 0; j + i + 4 < strlen(str); j++) {
                if (str[j + i + 4] == '/') {
                    break;
                }
            }
            if (i + j + 4 == strlen(str)) {
                j--;
            }
            rewrite(&str[i], 4 + j);
            i -= 4;
            if (i < 0) {
                i = -1;
            }
        }
    }
    reverse(str);
    // /../s -> /s
    while ((int)strlen(str) - 3 > 0) {
        if (equal(str, "/../") == 1) {
            rewrite(str, 3);
        } else {
            break;
        }
    }
    return str;
}

char *
add(char *a, const char *b)
{
    size_t len = strlen(a);
    a = realloc(a, (len + strlen(b) + 1) * sizeof(char));
    for (int i = 0; i <= strlen(b); i++) {
        a[len + i] = b[i];
    }
    return a;
}

char *
relativize_path(const char *path1, const char *path2)
{
    char *a = cpy(path1);
    a = add(a, "/");
    a = normalized(a);
    if (strlen(a) > 1) {
        a[strlen(a) - 1] = '\0';
    }
    while (strlen(a) > 1 && a[strlen(a) - 1] != '/') {
        a[strlen(a) - 1] = '\0';
    }
    if (strlen(a) > 1) {
        a[strlen(a) - 1] = '\0';
    }
    char *b = cpy(path2);
    b = add(b, "/");
    b = normalized(b);
    if (strlen(b) > 1) {
        b[strlen(b) - 1] = '\0';
    }

    int len = strlen(a);
    if (len > strlen(b)) {
        len = strlen(b);
    }
    int matching = 0;
    for (int i = 0; i <= len; i++) {
        if (a[i] == b[i]) {
            if (i == len || a[i] == '/') {
                matching = i;
            }
        } else {
            if ((a[i] == '\0' && b[i] == '/') || (a[i] == '/' && b[i] == '\0')) {
                matching = i;
            }
            break;
        }
    }
    char *ans = malloc(2 * sizeof(char));
    ans[0] = '.';
    ans[1] = '\0';
    if (matching == strlen(a) && matching == strlen(b)) {
        free(a);
        free(b);
        return ans;
    }
    int bol = 0;
    if (strlen(a) - 1 > matching) {
        ans = add(ans, "..");
        bol = 1;
    }
    for (int i = matching + 1; i < strlen(a); i++) {
        if (a[i] == '/') {
            ans = add(ans, "/..");
            bol = 1;
        }
    }
    if (bol && strlen(b) - 1 > matching) {
        ans = add(ans, "/");
    }
    ans = add(ans, &b[matching + 1]);
    if (strlen(ans) != 1) {
        rewrite(ans, 1);
    }
    free(a);
    free(b);
    return ans;
}