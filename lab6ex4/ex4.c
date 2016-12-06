#include "ex4.h"

/*int findstring(char **array, char *string)
{
    int i;
    for (i = 0; i < )
}*/

void read(FILE *f)
{
    char *s, ch;
    int i, nr;
    s = (char*) malloc(sizeof(char) * 5000);
    char **listOfStrings = (char**) malloc(sizeof(char*) * 100);
    if (listOfStrings == NULL)
    {
        printf("listofstring is null1\n");
    }
    printf("dmgksngsd\n");
    for (i = 0; i < 100; i++)
    {
        listOfStrings[i] = (char*) malloc(sizeof(char) * 50);
    }
    if (listOfStrings != NULL)
    {
        printf("ListOfStrings is not null\n");
    }
    //int nrOfWords = 0;
    i = 0;
    while (fscanf(f, "%s%ch", s, &ch) > 0)
    {
        printf("%s %d\n", s, strlen(s));
        while (!((s[strlen(s) - 1] >= 'a' && s[strlen(s) - 1] <= 'z') ||
              (s[strlen(s) - 1] >= 'A' && s[strlen(s) - 1] <= 'Z')))
        {
            s[strlen(s) - 1] = '\0';
            printf("%s %d\n", s, strlen(s));
        }
        strcpy(listOfStrings[i], s);
        listOfStrings[i] = (char*) realloc(listOfStrings[i], sizeof(char) * strlen(s));
        i++;
        if (ch == '\n')
        {
            printf("eol\n");
        }
        //nrOfWords++;
    }
    nr = i;
    **listOfStrings = (char**) realloc(**listOfStrings, sizeof(char*) * nr);
    for (i = 0; i < nr; i++)
    {
        printf("%s\n", listOfStrings[i]);
    }
}

