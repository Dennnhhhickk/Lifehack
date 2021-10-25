#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

struct Task
{
    unsigned uid;
    int gid_count;
    unsigned *gids;
};

extern int
myaccess(const struct stat *, const struct Task *, int);

int main()
{
    struct stat buf;
    stat("test", &buf);
    struct Task task;
    task.uid = 0;
    task.gid_count = 0;
    task.gids = NULL;
    int acces;
    scanf("%d", &acces);
    printf("%d %d\n", myaccess(&buf, &task, acces), ((access("test", 3) != -1 ? access("test", 3) : 0) << 2) + ((access("test", 2) != -1 ? access("test", 2) : 0) << 2) + (access("test", 1) != -1 ? access("test", 1) : 0));
    return 0;
}