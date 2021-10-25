#include "headers.h"
#include <math.h>

long long comparasion, moving;

void swap(typ *a, typ* b)
{
    moving++;
    typ tmp = *a;
    *a = *b;
    *b = tmp;
}

int cmp(typ a, typ b)
{
    comparasion++;
    //Вид сортировки.
    if (a > b)                    //Числа упорядочиваются по неубыванию:
    // if (module(a) > module(b))    //Числа упорядочиваются по неубыванию модулей, т.е. при сравнении элементов не учитывается знак.
    // if (a < b)                    //Числа упорядочиваются по невозрастанию
    // if (module(a) < module(b))    //Числа упорядочиваются по невозрастанию модулей, т.е. при сравнении элементов не учитывается знак.
        return 1;
    return 0;
}

//Метод «пузырька»
void BubbleSort(int n, typ* b)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (cmp(*(b + j), *(b + j + 1)))
                swap(b + j, b + j + 1);
}

//Метод простого выбора
void SelectionSort(int n, typ* b)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (cmp(*(b + i), *(b + j)))
                swap(b + i, b + j);
}

void ShellSort(int n, typ* a)
{
    typ tmp;
    for (int step = n / 2; step > 0; step /= 2)
        for (int i = step; i < n; i++)
        {
            int j;
            tmp = a[i];
            for (j = i; j >= step; j -= step)
            {
                if (cmp(*(a + j - step), tmp))
                {
                    a[j] = a[j - step];
                    moving++;
                }
                else
                    break;
            }
            a[j] = tmp;
        }
}

void QuickSort(typ* s_arr, long long first, long long last)
{
    if (first < last)
    {
        long long left = first, right = last;
        typ middle = s_arr[(left + right) / 2];
        do
        {
            while (cmp(middle, s_arr[left]))
            {
                left++;
            }
            while (cmp(s_arr[right], middle))
            {
                right--;
            }
            if (left <= right)
            {
                if (cmp(s_arr[left], s_arr[right]))
                {
                    swap(s_arr + left, s_arr + right);
                }
                left++;
                right--;
            }
        } while (left <= right);
        QuickSort(s_arr, first, right);
        QuickSort(s_arr, left, last);
    }
}

void QuickCall(int n, typ* a)
{
    QuickSort(a, 0, n - 1);
}