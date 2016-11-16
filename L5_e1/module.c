#include "module.h"

int *read(int *a, int *n)
{
    int x;
    a = (int*) malloc(sizeof(int) * 100);
    scanf("%d", &x);
    while (x != -1)
    {
        a[*n] = x;
        (*n)++;
        scanf("%d", &x);
    }
    a = (int*) realloc(a, sizeof(int) * (*n));
    return a;
}

void write(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int *subsequence(int *a, int n, int *length)
{
    int i = 0, j = 1, found = 0, jsub = 0, isub = 0, exit = 0, first = 0, last = 0, k = 0;
    int x;
    int *b;
    while (i < n)
    {
        jsub = 0;
        exit = 0;
        j = i + 1;
        while (j < n && exit == 0)
        {
            if (a[j] > a[i])
            {
                jsub++;
                j++;
            }
            else
            {
                exit = 1;
                if (jsub > isub)
                {
                    isub = jsub;
                    first = i - 1;
                    last = j;
                }
            }
        }
        i++;
    }
    *length = last - first;
    b = (int*) malloc(sizeof(int) * (*length));
    for (i = first; i < last; i++)
    {
        b[k] = a[i];
        k++;
    }
    return b;
}
