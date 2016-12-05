#include "modul.h"

int **initializare_structura(int **inel, int *rows, int *columns, int *nrinele)
{
//initializeaza structura cu un vector citit
    int i, x, y;
    printf("Please introce the number of rows and columns for your first ring!\n");
    scanf("%d %d", rows, columns);
    (*nrinele)++;
    if ((*rows) > 2 && (*columns) > 2)
    {
        printf("Wrong data!");
    }
    inel = (int**) calloc((*nrinele), sizeof(int*));
    inel[1] = (int*) calloc((*rows) * (*columns), sizeof(int));
    printf("Please introduce the elements of your first ring!\n");
    for (i = 0; i < (*rows) * (*columns); i++)
    {
        scanf("%d", &inel[1][i]);
    }
    return inel;
}

int **adaugare_inel(int **a, int *rows, int *columns, int *nrinele)
{
//adaugarea unui inel in forma de vector
    int ring, i;
    printf("Which ring do you want to introduce?");
    scanf("%d", &ring);
    if (a[ring] != NULL)
    {
        printf("Ring already exists\n");
        return a;
    }
    int more = ring - *nrinele + 1;
    (*nrinele) ++;
    if (more > 0)
    {
        *rows += more;
        *columns += more;
    }
    a = (int**) realloc(a, sizeof(int*) * (*nrinele));
    a[ring] = (int*) realloc(a, (*rows) * (*columns) * sizeof(int));
    if (a[ring] == NULL)
    {
        printf("a[%d] is null\n", ring);
    }
    printf("rows = %d, columns = %d\n", *rows, *columns);
    printf("Please introduce the elements of ring nr %d!\n", ring);
    for (i = 0; i < (*rows) * (*columns); i++)
    {
        printf("Entered for\n");
        scanf("%d", &a[ring][i]);
    }
    return a;
}

int **stergere_inel(int **a, int *rows, int *columns, int *nrinele)
{
//stergerea unui inel (un vector dintre vectori)
    int ring;
    printf("Which ring do you want to delete?\n");
    scanf("%d", &ring);
    free(a[ring]);
    (*nrinele) --;
    if (ring > nrinele)
    {
        int i = ring;
        while (a[i] == NULL)
        {
            i--;
        }
        (*rows) -= (ring - i) * 2;
        (*columns) -= (ring - i) * 2;
    }
    return **a;
}

void afisare_matrice(int **a, int rows, int columns, int nrinele)
{
//afisarea matricei
    printf("afisare_matrice\n");
    int **b, i, j, k, orig_rows = rows, orig_columns = columns;
    b = (int**) calloc(rows, sizeof(int*));
    printf("after malloc\n");
    for (i = 0; i < rows; i++)
    {
        printf("Entered for\n");
        b[i] = (int*) calloc(columns, sizeof(int*));
        printf("after malloc\n");
    }
    printf("After for\n");
    if (nrinele == 1)
    {
        int x = 0;
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < columns; j++)
            {
                printf("%d ", a[nrinele][x]);
                x++;
            }
            printf("\n");
        }
    }
    else
    {
        for (i = nrinele; i > 0; i--)
        {
            printf("Entered for\n");
            int x = 0;
            for (j = 0; j < rows; j++)
            {
                printf("Entered first for\n");
                if (a[i] == NULL)
                {
                    b[rows - 1][j] = -1;
                }
                else
                {
                    b[rows - i][j] = a[i][x];
                }
                x++;
            }
            for (j = 1; j < columns; j++)
            {
                printf("entered second for\n");
                printf("j = %d\n", j);
                if (a[i] == NULL)
                {
                    b[j][columns - 1] = -1;
                }
                else
                {
                    b[j][columns - 1] = a[i][x];
                }
                printf("x = %d\n", x);
                x++;
            }
            for (j = rows - 1; j >= 0; j--)
            {
                printf("entered 3rd for\n");
                if (a[i] == NULL)
                {
                    b[rows - 1][j] = -1;
                }
                else
                {
                    b[rows - i][j] = a[i][x];
                }
                x++;
            }
            for (j = 1; j < columns; j++)
            {
                if (a[i] == NULL)
                {
                    b[j][columns - 1] = -1;
                }
                else
                {
                    b[j][columns - 1] = a[i][x];
                }
                x++;
            }
            rows--;
            columns--;
        }
        for (i = 0; i < orig_rows; i++)
        {
            for (j = 0; j < orig_columns; j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    }
}

