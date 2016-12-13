#include "e07.h"

void inverse(FILE *f, FILE *g)
{
    int n, i, j;
    char *str, **array;
    str = malloc(sizeof(char) * 500);
    array = malloc(sizeof(char*) * 100);
    i = 0;
    while (fgets(str, 500, f))
    {
        array[i] = malloc(sizeof(char) * strlen(str));
        strcpy(array[i], str);
        i++;
    }
    n = i;
    array = realloc(array, sizeof(char*) * n);
    for (i = n-1; i >= 0; i--)
    {
        fputs(array[i], g);
        free(array[i]);
    }
    free(array);
    free(str);
}
