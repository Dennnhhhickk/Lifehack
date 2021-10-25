#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int
cmp(char *str)
{
    int len = strlen(str);
    if (len >=4 && str[len - 1] == 'e' && str[len - 2] == 'x' && str[len - 3] == 'e' &&
            str[len - 4] == '.') {
        return 1;
    }
    return 0;
}

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Not enough arguments\n");
        return 1;
    }
    DIR *dir = opendir(argv[1]);
    if (!dir) {
        fprintf(stderr, "Can\'t open directory\n");
        return 1;
    }
    char str[8192];
    for (int i = 0; i < strlen(argv[1]); i++) {
        str[i] = argv[1][i];
    }
    str[strlen(argv[1])] = '/';
    struct dirent *buf;
    int ans = 0;
    while ((buf = readdir(dir)) != NULL) {
        for (int i = 0; i <= strlen(buf->d_name); i++) {
            str[strlen(argv[1]) + i + 1] = buf->d_name[i];
        }
        struct stat buff;
        if (stat(str, &buff) >= 0 && S_ISREG(buff.st_mode) && access(str, 1) == 0 &&
                cmp(buf->d_name)) {
            ans++;
        }
    }
    printf("%d\n", ans);
    closedir(dir);
    return 0;
}