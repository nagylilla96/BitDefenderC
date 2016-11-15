#include <stdio.h>
#include <stdlib.h>

void allocate(int *a, int sizeA)
{
    a = (int*) malloc(sizeof(int) * sizeA);
    if (a == NULL)
    {
        printf("The set is null!\n");
    }
    printf("size: %d \n", sizeA);
}

int compare(const void *a, const void *b)
{
    return ( *(int*)a - *(int*)b);
}

void afisare(int *a, int*b, int sizeA, int sizeB)
{
    int i;
    printf("A:\n");
    for (i = 0; i < sizeA; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nB:\n");
    for (i = 0; i < sizeB; i++)
    {
        printf("%d ", b[i]);
    }
}

void uniune(int *a, int *b, int sizeA, int sizeB)
{
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

void intersectie(int *a, int *b, int sizeA, int sizeB)
{
    int i = 0, j = 0;
    printf("\nIntesection:\n");
    while (i < sizeA && j < sizeB)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            if (a[i] > b[j])
            {
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
}

void diferenta(int *a, int *b, int sizeA, int sizeB)
{
    int i = 0, j = 0;
    printf("\nDifference\n");
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
                j++;
            }
            else
            {
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
