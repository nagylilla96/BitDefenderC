#include "ex4.h"

int findstring(char **array, char *string, int nr)
{
    int i;
    for (i = 0; i < nr; i++)
    {
        if (strcmp(array[i], string) == 0) //finds a string in an array of strings and returns its index
        {
            return i;
        }
    }
    return 0;
}

void read(FILE *f, int n)
{
    char *s, ch;
    FILE *g;
    g = fopen("output.txt", "w");
    int i, nr, *nrStrFound, *nrOfLine;
    int *found;
    s = (char*) malloc(sizeof(char) * 5000);
    char **listOfStrings = (char**) malloc(sizeof(char*) * 100);
    for (i = 0; i < 100; i++)
    {
        listOfStrings[i] = (char*) malloc(sizeof(char) * 50);
    }
    i = 0;
    nrStrFound = (int*) malloc(sizeof(int) * 100);
    nrStrFound = memset(nrStrFound, 0, 100);
    nrOfLine = (int*) malloc(sizeof(int) * 100);
    nrOfLine = memset(nrOfLine, 0, 100);
    found = (int*) malloc(sizeof(int) * 100);
    found = memset(found, 0, 100);
    while (fscanf(f, "%s%ch", s, &ch) > 0)
    {
        while (!((s[strlen(s) - 1] >= 'a' && s[strlen(s) - 1] <= 'z') || //if a char is not a letter,
              (s[strlen(s) - 1] >= 'A' && s[strlen(s) - 1] <= 'Z'))) //it is deleted
        {
            s[strlen(s) - 1] = '\0';
        }
        if (findstring(listOfStrings, s, (i + 1)) != 0) //if the string is already found, the number
        {                                               //of its appearence increases, and the number
            nrStrFound[findstring(listOfStrings, s, i)]++; //of line increases only if it was already
            if (!found[findstring(listOfStrings, s, i)])   //found on this line
            {
                nrOfLine[findstring(listOfStrings, s, i)]++;
            }
        }
        else
        {
            strcpy(listOfStrings[i], s);
            nrStrFound[i]++;
            if (!found[i])
            {
                nrOfLine[i]++;
            }
            i++;
        }
        if (ch == '\n')
        {
           found = memset(found, 0, 100); //on a new line every found is reset to zero for appearence
        }                                 //on line calculation
    }
    nr = i;
    for (i = 0; i < nr; i++)
    {
        fprintf(g, "word: %s, frequency: %d, nr of lines: %d\n", listOfStrings[i], nrStrFound[i], nrOfLine[i]);
    }
    int j, index, lastmax = 9999, lastindex = -1;
    printf("The most frequent %d words are:\n", n);
    for (i = 0; i < n; i++) //this really inefficient algorithm looks for the maximum frequency of a word,
    {                       //and when found, it is listed, then set to zero (so we don't have to look at
        int max = 0;        //that case again)
        for (j = 0; j < nr; j++)
        {
            if (nrStrFound[j] > max)
            {
                max = nrStrFound[j];
                index = j;
            }
        }
        printf("%s\n", listOfStrings[index]);
        nrStrFound[index] = 0;
    }
    free(s);
    free(nrStrFound);
    free(nrOfLine);
    free(found);
    for (i = 0; i < nr; i++)
    {
        free(listOfStrings[i]);
    }
    free(listOfStrings);
    fclose(g);
}

