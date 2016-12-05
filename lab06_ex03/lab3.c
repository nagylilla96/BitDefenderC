#include "lab3.h"

char *delete_space(char *s)
{
    int i = 0, n = strlen(s);
    while (i < n)
    {
        if ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (s[i+1] == ' ' || s[i+1] == '\t' || s[i+1] == '\n'))
        {
            strcpy(s + i, s + i + 1);
            n--;
        }
        else
        {
            i++;
        }
    }
    s = (char*) realloc(s, sizeof(char) * strlen(s));
    return s;
}

char *delete_last(char *s, char *w)
{
    int i = strlen(s);
    while (i >= -1)
    {
        if (s[i] != ' ')
        {
            i--;
        }
        else
        {
            if (strncmp(s + i + 1, w, strlen(w) - 1) == 0)
            {
                strcpy(s + i, s + i + strlen(w));
                i = -2;
            }
            else
            {
                i--;
            }
        }
    }
    return s;
}

char *delete_all(char *s, char *w)
{
    int i = strlen(s);
    while (i >= 0)
    {
        if (strncmp(s + i, w, strlen(w) - 1) == 0)
        {
            strcpy(s + i, s + i + strlen(w));
        }
        i--;
    }
    return s;
}

char *insert(char *s, char *w, int ind)
{
    char *substr;
    int n = strlen(w);
    substr = (char*) malloc(100 * sizeof(char));
    strcpy(substr, w);
    printf("substr = %s\n", substr);
    strcpy(substr + n - 1, s + ind);
    printf("substr = %s\n", substr);
    strcpy(s + ind, substr);
    printf("s = %s\n", s);
    return s;
}

void histogram(char *s)
{
    int i;
    int *a;
    a = (int*) malloc (256 * sizeof(int));
    a = memset(a, 0, 256);
    for (i = 0; i < strlen(s); i++)
    {
        a[(int) s[i]] ++;
    }
    for (i = 0; i < 256; i++)
    {
        printf("%c = %d | ", (char) i, a[i]);
    }
}
