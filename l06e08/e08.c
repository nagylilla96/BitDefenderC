#include "e08.h"

char **sortAlph(char **arrayOfStrings, int n)
{

}

void show(char **arrayOfStrings, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s\n", arrayOfStrings[i]);
    }
}

void read(FILE *f)
{
    char *str, **arrayOfStrings;
    int i, n;
    arrayOfStrings = malloc(sizeof(char*) * 500);
    str = malloc(sizeof(char) * 500);
    i = 0;
    while (fgets(str, 500, f))
    {
        arrayOfStrings[i] = malloc(sizeof(char) * strlen(str));
        strcpy(arrayOfStrings[i], str);
        fputs(arrayOfStrings[i], stdout);
        i++;
    }
    n = i;
    arrayOfStrings = realloc(arrayOfStrings, sizeof(char*) * n);
}
