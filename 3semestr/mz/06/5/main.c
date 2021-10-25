#include <stdio.h>
#include <sys/stat.h>

struct Task
{
    unsigned uid;
    int gid_count;
    unsigned *gids;
};

static int
check_rights(mode_t st_mode, int access, int bais)
{
    return (((st_mode >> bais) & access) == access);
}

static int
check_creator(unsigned uid, const struct stat *stb, int access)
{
    return (uid == stb->st_uid && check_rights(stb->st_mode, access, 6));
}

static int
check_group(unsigned gid, const struct stat *stb, int access)
{
    return (gid == stb->st_gid && check_rights(stb->st_mode, access, 3));
}

static int
check_others(const struct stat *stb, int access)
{
    return (check_rights(stb->st_mode, access, 0));
}

int
myaccess(const struct stat *stb, const struct Task *task, int access)
{
    if (task->uid == 0 || check_creator(task->uid, stb, access)) {
        return 1;
    }
    if (task->uid == stb->st_uid) {
        return 0;
    }
    for (int i = 0; i < task->gid_count; i++) {
        if (check_group(task->gids[i], stb, access)) {
            return 1;
        } else if (task->gids[i] == stb->st_gid) {
            return 0;
        }
    }
    return check_others(stb, access);
}