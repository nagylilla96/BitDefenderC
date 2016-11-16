#include "VECTOR.h"

int *read(int n)
{
    int i;
    int *a = (int*) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    return a;
}

void write(int *a, int n)
{
    int i;
    printf("The vector is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int *insert(int *a, int k, int x, int n)
{
    int i;
    a = (int*) realloc(a, sizeof(int) * (n + 1));
    for (i = n; i > k; i--)
    {
        a[i] = a[i - 1];
    }
    a[k] = x;
    return a;
}

int *myDelete(int *a, int k, int n)
{
    int i;
    a = (int *) realloc(a, sizeof(int) * (n - 1));
    for (i = k; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    return a;
}

int minFunc(int *a, int n)
{
    int min = INT_MAX;
    int i, k = -1;
    for (i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            k = i;
        }
    }
    return k;
}

int maxFunc(int *a, int n)
{
    int max = INT_MIN;
    int i, k = -1;
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            k = i;
        }
    }
    return k;
}

void majoritar(int *a, int n)
{
    int i, nr = 0;
    int *temp = (int*) malloc(sizeof(int) * a[maxFunc(a, n)]);
    for (i = 0; i < a[maxFunc(a,n)]; i++)
    {
        temp[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        temp[a[i]] ++;
    }
    if (maxFunc(temp, a[maxFunc(a, n)]) == 1)
    {
    printf("Every element has the same frequency\n");
    }
    else
    {
        printf("The most frequent element of the vector is %d\n", maxFunc(temp, a[maxFunc(a,n)]));
    }
}

int compare(const void *a, const void *b)
{
    return ( *(int*)a - *(int*)b);
}

void intercalare(int *a, int *b, int sizeA, int sizeB)
{
    qsort(a, sizeA, sizeof(int), compare);
    qsort(b, sizeB, sizeof(int), compare);
    int i = 0, j = 0;
    printf("\nUnion: \n");
    while (i < sizeA && j < sizeB)
    {
        if (a[i] < b[j])
        {
            printf("%d ", a[i]);
            i++;
        }
        else
        {
            if (a[i] > b[j])
            {
                printf("%d ", b[j]);
                j++;
            }
            else
            {
                printf("%d ", a[i]);
                i++;
                j++;
            }
        }
    }
    while (i < sizeA)
    {
        printf("%d ", a[i]);
        i++;
    }
    while (j < sizeB)
    {
        printf("%d ", b[j]);
        j++;
    }
}
