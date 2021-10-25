#include <stdio.h>
#include <stdlib.h>

enum { A = 1103515245, C = 12345, OST = 1 << 31 };

typedef struct RandomGenerator
{
    int seed;
    struct RandomOperations *ops;
} RandomGenerator;

typedef struct RandomOperations
{
    int (*next)(RandomGenerator *);
    void (*destroy)(RandomGenerator *);
} RandomOperations;

static void
destroy(RandomGenerator *a)
{
    free(a->ops);
    free(a);
}

static int
next(RandomGenerator *a)
{
    a->seed = ((A * 1ll * a->seed) % OST + C) % OST;
    return a->seed;
}

RandomGenerator *
random_create(int seed)
{
    RandomGenerator *a = calloc(1, sizeof(RandomGenerator));
    a->ops = calloc(1, sizeof(RandomOperations));
    a->ops->next = next;
    a->ops->destroy = destroy;
    a->seed = seed;
    return a;
}
