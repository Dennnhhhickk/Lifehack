#include "headers.h"

int check(int n, typ* a, typ* b)
{
    for (int i = 0; i < n; i++)
        if (a[i] < b[i] || a[i] > b[i])
            return 0;
    return 1;
}