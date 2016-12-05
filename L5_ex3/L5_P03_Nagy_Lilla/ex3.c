#include "ex3.h"

int **read(int **a, int n) // reads a matrix of size n and allocates space for it
{
    int x, i, j;
    a = (int**) malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        a[i] = (int*) malloc (n * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    return a;
}

void write(int **a, int n) //writes a matrix of size n
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void sumaLinii(int **a, int n) // write the sum of all elements from every line
{
    int suma = 0, i, j;
    for (i = 0; i < n; i++)
    {
        suma = 0;
        for (j = 0; j < n; j++)
        {
            suma += a[i][j];
        }
        printf("The sum of members from line %d is %d\n", i, suma);
    }
}

void sumaColoane(int **a, int n) // writes the sum of elements from every column
{
    int suma = 0, i, j;
    for (i = 0; i < n; i++)
    {
        suma = 0;
        for (j = 0; j < n; j++)
        {
            suma += a[j][i];
        }
        printf("The sum of members from column %d is %d\n", i, suma);
    }
}

void sumaMainDiagonal(int **a, int n) // prints the sum of elements from the main diagonal
{
    int suma = 0, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                suma += a[i][j];
            }
        }
    }
    printf("The sum of members from the main diagonal is %d\n", suma);
}

void sumaSecondaryDiagonal(int **a, int n) // prints the sum of elements from the secondary diagonal
{
    int suma = 0, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == n - i - 1)
            {
                suma += a[i][j];
            }
        }
    }
    printf("The sum of members from the secondary diagonal is %d\n", suma);
}

void rings(int **a, int n)
{
    printf("Entered rings\n");
    int x, sum, p = 1;
    if (n % 2 == 0)
    {
        x = n / 2;
        printf("x = %d\n", x);
    }
    else
    {
        x = (n / 2) + 1;
        printf("x = %d\n", x);
        p = 0;
    }
    int i, j, k = 0;
    while (k < x)
    {
        if (k == x - 1 && p == 0)
        {
            sum = a[x - 1][x - 1];
        }
        else
        {
            printf("k = %d\n", k);
            sum = 0;
            for (i = k; i < (n - k); i++)
            {
                printf("first for i = %d\n", i);
                sum += a[i][k];
                sum += a[k][i];
            }
            sum -= a[k][k];
            for (i = k + 1; i < (n - k); i++)
            {
                printf("second for i = %d\n", i);
                sum += a[i][n - k - 1];
                sum += a[n - k - 1][i];
            }
            sum -= a[n - k - 1][n - k - 1];
        }
        printf("The sum of numbers in ring %d: %d\n", k, sum);
        k++;
    }
}
