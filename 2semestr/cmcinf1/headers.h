#include <stdlib.h>
#include <time.h>

#define INT "int"
#define LONG_LONG "long long"
#define DOUBLE "double"

// Данные (элементы массива).
// typedef int typ;            // Целые числа (int).
// #define module abs          //  Целые числа (int).
// #define OUT "%d "           //  Целые числа (int).
// #define Type "int"          //  Целые числа (int).

typedef long long typ;      // 64-разрядные целые числа (long long int).
#define module labs         // 64-разрядные целые числа (long long int).
#define OUT "%lld "         // 64-разрядные целые числа (long long int).
#define Type "long long"    // 64-разрядные целые числа (long long int).

// typedef double typ;         // Вещественные числа двойной точности (double).
// #define module fabs         // Вещественные числа двойной точности (double).
// #define OUT "%lf "          // Вещественные числа двойной точности (double).
// #define Type "double"       // Вещественные числа двойной точности (double).