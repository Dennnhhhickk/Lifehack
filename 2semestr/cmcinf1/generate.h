#include "headers.h"
#include <stdio.h>

#define rand_ost 32768
#define INT_COUNT 3
#define LONG_LONG_COUNT 5
#define DOUBLE_FIRST_COUNT 6
#define DOUBLE_SECOND_COUNT 3
\
int comp (const void * elem1, const void * elem2) 
{
    typ* f = ((typ*)elem1);
    typ* s = ((typ*)elem2);
    if (*f > *s)                    //Числа упорядочиваются по неубыванию:
    // if (module(*f) > module(*s))    //Числа упорядочиваются по неубыванию модулей, т.е. при сравнении элементов не учитывается знак.
    // if (*f < *s)                    //Числа упорядочиваются по невозрастанию
    // if (module(*f) < module(*s))    //Числа упорядочиваются по невозрастанию модулей, т.е. при сравнении элементов не учитывается знак.
        return 1;
    if (*f < *s)                    //Числа упорядочиваются по неубыванию:
    // if (module(*f) < module(*s))    //Числа упорядочиваются по неубыванию модулей, т.е. при сравнении элементов не учитывается знак.
    // if (*f > *s)                    //Числа упорядочиваются по невозрастанию
    // if (module(*f) > module(*s))    //Числа упорядочиваются по невозрастанию модулей, т.е. при сравнении элементов не учитывается знак.
        return -1;
    return 0;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

typ ost(int n, long long F)
{
    long long ans = 1;
    for (int i = 0; i < n; i++)
        ans = (ans * (rand() % rand_ost)) % F;
    return ans * (2 * (rand() % 2) - 1);
}

typ fost(int a, int b)
{
    typ ans = 1;
    for (int i = 0; i < a; i++)
        ans *= (rand() % rand_ost);
    for (int i = 0; i < b; i++)
        ans /= (1 + rand() % rand_ost);
    return ans * (2 * (rand() % 2) - 1);
}

void generate(int n, typ* a)
{
    for (int i = 0; i < n; i++)
        if (Type == INT)
            a[i] = ost(rand() % INT_COUNT, INT32_MAX);                      // Целые числа (int).
        else
            if (Type == LONG_LONG)
                a[i] = ost(rand() % LONG_LONG_COUNT, __LONG_LONG_MAX__);    // 64-разрядные целые числа (long long int).
            else
                if (Type == DOUBLE)
                {
                    int first = rand() % DOUBLE_FIRST_COUNT;                //Вещественные числа двойной точности (double).
                    a[i] = fost(first, rand() % (min(first + 1, DOUBLE_SECOND_COUNT)));
                }
                else
                    exit(1);                                                //Ошбика типа
}

void reverse(int n, typ* a)
{
    for (int i = 0; i < n / 2; i++)
    {
        typ tmp = *(a + i);
        *(a + i) = *(a + n - i - 1);
        *(a + n - i - 1) = tmp;
    }
}

void certaingenerate(int n, typ* a, int flag)
{
    // flag == 0 => прямой
    // flag == 1 => обратный
    // flag == 2 => рандомный
    generate(n, a);
    if (flag < 2)
    {
        qsort (a, n, sizeof(typ), comp);
        if (flag)
            reverse(n, a);
    }
}