#include "e08.h"

int cmp(const void *a, const void *b) { //compare function for the qsort
    const char **ia = (const char **) a;
    const char **ib = (const char **) b;
    return strcmp(*ia, *ib);
}

void sortAlph(char **arrayOfStrings, int n) { //sort array of strings alphabetically
    qsort(arrayOfStrings, n, sizeof(char*), cmp);
    show(arrayOfStrings, n);
}

int nrOfWords(char *arrayOfStrings) { //count the number of words from a string
    int i, count = 0;
    for (i = 0; i < strlen(arrayOfStrings); i++) {
        if (arrayOfStrings[i] == ' ') {
            count++;
        }
    }
    if (arrayOfStrings[strlen(arrayOfStrings) - 1] != ' ') {
        return count + 1;
    }
    return count;
}

void sortStrings(char **arrayOfStrings, int n, int byChar) { //sort strings
    int i, j;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (byChar) { //by number of characters
                if (strlen(arrayOfStrings[j]) > strlen(arrayOfStrings[j + 1])) {
                    char temp[500];
                    strcpy(temp, arrayOfStrings[j]);
                    strcpy(arrayOfStrings[j], arrayOfStrings[j + 1]);
                    strcpy(arrayOfStrings[j + 1], temp);
                }
            }
            else { // or by number of words
                if (nrOfWords(arrayOfStrings[j]) > nrOfWords(arrayOfStrings[j + 1])) {
                    char temp[500];
                    strcpy(temp, arrayOfStrings[j]);
                    strcpy(arrayOfStrings[j], arrayOfStrings[j + 1]);
                    strcpy(arrayOfStrings[j + 1], temp);
                }
            }
        }
    }
    show(arrayOfStrings, n);
}

void show(char **arrayOfStrings, int n) //show strings
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s", arrayOfStrings[i]);
    }
}

void read(FILE *f) //read from file
{
    char *str, **arrayOfStrings;
    int i, n;
    str = malloc(sizeof(char) * 500);
    arrayOfStrings = malloc(sizeof(char*) * 100);
    i = 0;
    while (fgets(str, 500, f))
    {
        arrayOfStrings[i] = malloc(sizeof(char) * strlen(str));
        strcpy(arrayOfStrings[i], str);
        printf("string[%d] = %s\n", i, arrayOfStrings[i]);
        i++;
    }
    n = i;
    arrayOfStrings = realloc(arrayOfStrings, sizeof(char*) * n);
    show(arrayOfStrings, n);
    printf("\nsorted alphabetically: \n");
    sortAlph(arrayOfStrings, n);
    printf("\nsorted by nr of words: \n");
    sortStrings(arrayOfStrings, n, 0);
    printf("\nsorted by nr of chars:\n");
    sortStrings(arrayOfStrings, n, 1);
}
