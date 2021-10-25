#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>

int
mycmp(const void *a, const void *b)
{
    return strcasecmp(*(const char**)a, *(const char**)b);
}

void
rec(const char *str, const char *dire)
{
    DIR *dir = opendir(str);
    if (dir == NULL) {
        //fprintf(stderr, "Can't open directory %s\n", str);
        return;
    }
    int size = 1, k = 0;
    char **list = calloc(size, sizeof(*list));
    struct dirent *next;
    struct stat buf;
    char p[2 * PATH_MAX];
    while ((next = readdir(dir)) != NULL) {
        snprintf(p, PATH_MAX, "%s/%s", str, next->d_name);
        if (strcmp(next->d_name, "..") && strcmp(next->d_name, ".") && 
            lstat(p, &buf) != -1 && S_ISDIR(buf.st_mode)) {
            int len = strlen(next->d_name);
            list[k] = calloc(len + 1, sizeof(**list));
            for (int i = 0; i <= len; i++) {
                list[k][i] = next->d_name[i];
            }
            k++;
            if (k == size) {
                size <<= 1;
                list = realloc(list, size * sizeof(*list));
            }
            if (list == NULL) {
                fprintf(stderr, "Can't resize list\n");
                for(;;);
                return;
            }
        }
    }
    closedir(dir);

    // sort list

    qsort(list, k, sizeof(*list), mycmp);

    int str_len = strlen(str);
    char *path = calloc(str_len + 2, sizeof(*path));
    for (int i = 0; i < str_len; i++) {
        path[i] = str[i];
    }
    path[str_len] = '/';
    path[str_len + 1] = '\0';
    for (int i = 0; i < k; i++) {
        int len = strlen(list[i]);
        path = realloc(path, sizeof(*path) * (str_len + 2 + len));
        for (int j = 0; j <= len; j++) {
            path[j + str_len + 1] = list[i][j];
        }
        if (strlen(str) <= PATH_MAX - 1 && (dir = opendir(path)) != NULL) {
            closedir(dir);
            printf("cd %s\n", list[i]);
            rec(path, list[i]);
            printf("cd ..\n");
        }
    }
    free(path);
    for (int i = 0; i < k; i++) {
        free(list[i]);
    }
    free(list);
}

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Not enough arguments\n");
        return 1;
    }
    rec(argv[1], NULL);
    return 0;
}
