#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int 
main()
{
    unsigned long long cnt[10] = {0};
    char path[8192];
    if (fgets(path, 8192, stdin) != NULL) {
        if (path[strlen(path) - 1] == '\n'){
            path[strlen(path) - 1] = '\0';
        }
        if (path[strlen(path) - 1] == '\r'){
            path[strlen(path) - 1] = '\0';
        }
        FILE *in = fopen(path, "r");
        char str[8192];
        if (in != NULL) {
            while (fgets(str, 8192, in) != NULL) {
                int len = strlen(str);
                for (int i = 0; i < len; i++) {
                    if (isdigit((unsigned char)str[i])) {
                        cnt[str[i] - '0']++;
                    }
                }
            }
            fclose(in);
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d %llu\n", i, cnt[i]);
    }
    return 0;
}