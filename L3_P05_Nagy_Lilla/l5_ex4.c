#include "l5_ex4.h"

void convert(int x) //convert decimal numbers to binary
{
    int i;
    for (i = 0; i < 32; i++)
    {
        if (x & 1 == 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        x = x >> 1;
    }
}

void nullify(int a[]) // fill array with zeroes
{
    int i;
    for (i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        a[i] = 0;
    }
}

int *introduc(int *a, int *n) //read numbers until one of them is -1
{
    int i,x, max = INT_MIN;
    scanf("%d", &x);
    a = (int*) calloc(1, sizeof(int));
    while (x != -1)
    {
        a[x/32] += pow(2, x % 32);
        if (x > max)
        {
            max = x;
        }
        (*n)++;
        a = (int*) realloc(a, sizeof(int) * (*n));
        scanf("%d", &x);
    }
    *n = max / 32;
    return a;
}

void afis(int a[], int n) // print the array (in binary)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        convert(a[i]);
        printf("\n");
    }
    return;
}

int card(int a[], int n) // returns the cardinality of an array
{
    int i, j, nr = 0, x;
    for (i = 0; i <= n; i++)
    {
        x = a[i];
        for (j = 0; j < 32; j++)
        {
            if ( x & 1 == 1)
            {
                nr++;
            }
            x = x >> 1;
        }
    }
    return nr;
}

void reuniune(int a[], int n1, int b[], int n2) //prints out the union of two sets
{
    int *c, i;
    if (n1 > n2)
    {
        c =(int*) malloc(n1 * sizeof(int));
    }
    else
    {
        c =(int*) malloc(n2 * sizeof(int));
    }
    for (i = 0; i <= sizeof(c) / sizeof(int); i++)
    {
        c[i] = a[i] | b[i];
    }
    afis(c, sizeof(c) /sizeof(int));
}

void intersectie(int a[], int n1, int b[], int n2) //prints out the intersection of two sets
{
    int *c, i;
    if (n1 > n2)
    {
        c = (int*) malloc(n1 * sizeof(int));
    }
    else
    {
        c = (int*) malloc(n2 * sizeof(int));
    }
    for (i = 0; i <= (sizeof(c) / sizeof(int)); i++)
    {
        c[i] = a[i] & b[i];
    }
    afis(c, sizeof(c) / sizeof(int));
}

void dif(int a[], int n1, int b[], int n2) //prints out the difference of two sets
{
    int *c, i, j, nr = 0, x, y;
    if (n1 > n2)
    {
        c = (int*) malloc(n1 * sizeof(int));
    }
    else
    {
        c = (int*) malloc(n2 * sizeof(int));
    }
    for (i = 0; i <= sizeof(c) / sizeof(int); i++)
    {
        x = a[i];
        y = b[i];
        c[i] = 0;
        for (j = 0; j < 32; j++)
        {
            if ((x%2 == 1) && (y % 2 == 0))
            {
                c[i] += pow(2, j);
            }
            x = x >> 1;
            y = y >> 1;
        }
    }
    afis(c, sizeof(c) / sizeof(int));
}

int apartine(int a[], int n, int x) // return 1 if a number is an element from an array, 0 otherwise
{
    int check = pow(2, x);
    if ( (check & a[x/32]) == check)
    {
        return 1;
    }
    return 0;
}
