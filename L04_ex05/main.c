#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int *a, *b, sizeA = 0, sizeB = 0, i;
    printf("How many elements do you want A to have?");
    scanf("%d", &sizeA);
    a = (int) malloc(sizeof(int) * sizeA);
    for (i = 0; i < sizeA; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("How many elements do you want B to have?");
    scanf("%d", &sizeB);
    b = (int) malloc(sizeof(int) * sizeB);
    for (i = 0; i < sizeB; i++)
    {
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }
    qsort(a, sizeA, sizeof(int), compare);
    qsort(b, sizeB, sizeof(int), compare);
    afisare(a, b, sizeA, sizeB);
    uniune(a, b, sizeA, sizeB);
    intersectie(a, b, sizeA, sizeB);
    diferenta(a, b, sizeA, sizeB);
    return 0;
}
