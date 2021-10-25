#include "checker.h"
#include "generate.h"
#include "sort.h"

#define TEST_COUNT 4
#define mkstr(s) # s

int N[] = {10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};
int N_size = 10;
long long comps[TEST_COUNT], movs[TEST_COUNT];

void view(int n, typ* a)
{
    for (int i = 0; i < n; i++)
        printf(OUT, a[i]);
    printf("\n");
}

void show(int n, FILE* out)
{
    for (int i = 1; i < TEST_COUNT; i++)
        {
            comps[TEST_COUNT - i] -= comps[TEST_COUNT - i - 1];
            movs[TEST_COUNT - i] -= movs[TEST_COUNT - i - 1];
        }
        fprintf(out, "%d;Сравнения;", n);
        for(int i = 0; i < TEST_COUNT; i++)
            fprintf(out, "%lld;", comps[i]);
        fprintf(out, "%.2lf\n", comparasion * (double)1 / TEST_COUNT);
        fprintf(out, ";Перемещения;");
        for(int i = 0; i < TEST_COUNT; i++)
            fprintf(out, "%lld;", movs[i]);
        fprintf(out, "%.2lf\n", moving * (double)1 / TEST_COUNT);
}

void init(FILE* out)
{
    fprintf(out, "n;Параметр;Номер сгенерированного массива");
    for (int i = 0; i < TEST_COUNT; i++)
        fprintf(out, ";");
    fprintf(out, "Среднее значение\n;;");
    for (int i = 0; i < TEST_COUNT; i++)
        fprintf(out, "%d;", i + 1);
    fprintf(out, "\n");
}

void process(void (*func)(int, typ*), char* str)
{
    FILE* out = fopen(str, "w");
    init(out);
    int n;
    typ* a = malloc(sizeof(typ));
    for (int i = 0; i < N_size; i++)
    {
        n = N[i];
        a = realloc(a, sizeof(typ) * n);
        comparasion = 0;
        moving = 0;
        for (int test = 0; test < TEST_COUNT; test++)
        {
            certaingenerate(n, a, min(test, 2));
            func(n, a);
            comps[test] = comparasion;
            movs[test] = moving;
        }
        show(n, out);
    }
    free(a);
    fclose(out);
}

void Test(void (*func)(int n, typ* a), char *name)
{
    int n;
    typ* a = malloc(sizeof(typ));
    typ* b = malloc(sizeof(typ));
    for (int i = 0; i < N_size; i++)
    {
        n = N[i];
        a = realloc(a, sizeof(typ) * n);
        b = realloc(b, sizeof(typ) * n);
        for (int test = 0; test < TEST_COUNT; test++)
        {
            certaingenerate(n, a, 3);
            for (int j = 0; j < n; j++)
                b[j] = a[j];
            func(n, a);

            qsort (b, n, sizeof(typ), comp);

            if (!check(n, a, b))
            {
                printf("ERROR %s\n", name);
                view(n, a);
                view(n, b);
                exit(2);                //Не правильно отсортирован массив
            }

        }
    }
    printf("%s - OK\n", name);

    free(a);
    free(b);
}

int main(void)
{
    srand(time(NULL));
    process(BubbleSort, "Stats/BubbleSort.csv");
    process(SelectionSort, "Stats/SelectionSort.csv");
    process(ShellSort, "Stats/ShellSort.csv");
    process(QuickCall, "Stats/QuickSort.csv");
    Test(QuickCall, mkstr(QuickSort));
    Test(ShellSort, mkstr(ShellSort));
    Test(SelectionSort, mkstr(SelectionSort));
    Test(BubbleSort, mkstr(BubbleSort));
    return 0;
}