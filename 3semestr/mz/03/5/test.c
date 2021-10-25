#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum { N = 100 };

int
main(int argc, char **argv)
{
    srand(time(NULL));
    for (int i = 1; i < argc; i += 2) {
        FILE *f = fopen(argv[i], argv[i + 1]);
        for (int j = 0; j < N; j++) {
            fprintf(f, "%c", rand() % 255 + 1);
        }
        fclose(f);
    }
    return 0;
}