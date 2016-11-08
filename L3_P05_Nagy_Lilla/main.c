#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void convert(int x)
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

void nullify(int a[])
{
    int i;
    for (i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        a[i] = 0;
    }
}

void introduc(int a[], int *n)
{
    int i,x, max = INT_MIN;
    printf("Cate numere vrei sa introduci?\n");
    scanf("%d", n);
    for (i = 0; i < *n; i++)
    {
        scanf("%d", &x);
        a[x/32] += pow(2, x % 32);
        if (x > max)
        {
            max = x;
        }
    }
    *n = max / 32;
    return;
}

void afis(int a[], int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        convert(a[i]);
        printf("\n");
    }
    return;
}

int card(int a[], int n)
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

void reuniune(int a[], int n1, int b[], int n2)
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

void intersectie(int a[], int n1, int b[], int n2)
{
    int *c, i;
    printf("n1 = %d, n2 = %d\n", n1, n2);
    if (n1 > n2)
    {
        c = (int*) malloc(n1 * sizeof(int));
    }
    else
    {
        c = (int*) malloc(n2 * sizeof(int));
    }
    printf("sizeof(c) / sizeof(int) = %d \n", sizeof(c) / sizeof(int));
    for (i = 0; i <= (sizeof(c) / sizeof(int)); i++)
    {
        c[i] = a[i] & b[i];
    }
    afis(c, sizeof(c) / sizeof(int));
}

void dif(int a[], int n1, int b[], int n2)
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

int apartine(int a[], int n, int x)
{
    int check = pow(2, x);
    if ( (check & a[x/32]) == check)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int size = INT_MAX / sizeof(int);
    int answer, *a, *b, n1, n2 = 0, x;
    a = (int*) malloc(size * sizeof(int));
    b = (int*) malloc(size * sizeof(int));
    printf("Ce vrei sa faci?\n1. Introduc o multime\n2. Afisarea multimii\n3. Cardinalitatea multimii\n4. Reuniunea a doua multimi\n5. Intersectia a doua multimi\n6. Diferenta a doua multimi\n7. Interogarea daca un numar apartine multimii A\n8. Iesire\nScrie numarul!\n");
    while (scanf("%d", &answer) >= 0)
    {
        switch(answer)
        {
        case 1:
            introduc(a, &n1);
            break;
        case 2:
            printf("\nA:\n");
            afis(a,n1);
            printf("\n");
            break;
        case 3:
            printf("card(A) = %d\n", card(a,n1));
            break;
        case 4:
            if (card(a, n1) == 0)
            {
                introduc(a, &n1);
            }
            if (card(b, n2) == 0)
            {
                printf("Introduce o alta multime!\n");
                introduc(b, &n2);
                printf("\nB:\n");
                afis(b, n2);
                printf("\ncard(B) = %d\n", card(b,n2));
            }
            printf("Reuniunea: \n");
            reuniune(a,n1,b,n2);
            break;
        case 5:
            if (card(a, n1) == 0)
            {
                introduc(a, &n1);
            }
            if (card(b, n2) == 0)
            {
                printf("Introduce o alta multime!\n");
                introduc(b, &n2);
                printf("\nB:\n");
                afis(b, n2);
                printf("\ncard(B) = %d\n", card(b,n2));
            }
            printf("Intersectia: \n");
            intersectie(a,n1,b,n2);
            break;
        case 6:
            if (card(a, n1) == 0)
            {
                introduc(a, &n1);
            }
            if (card(b, n2) == 0)
            {
                printf("Introduce o alta multime!\n");
                introduc(b, &n2);
                printf("\nB:\n");
                afis(b, n2);
                printf("\ncard(B) = %d\n", card(b,n2));
            }
            printf("Diferenta: \n");
            dif(a,n1,b,n2);
            break;
        case 7:
            if (card(a, n1) == 0)
            {
                introduc(a, &n1);
            }
            printf("Ce numar vrei sa verifici?\n");
            scanf("%d", &x);
            if (apartine(a, n1, x) == 1)
            {
                printf("Apartine\n");
            }
            else
            {
                printf("Nu apartine\n");
            }
            break;
        case 8:
            return 0;
            break;
        default:
            break;
        }
        printf("Ce vrei sa faci?\n1. Introduc o multime\n2. Afisarea multimii\n3. Cardinalitatea multimii\n4. Reuniunea a doua multimi\n5. Intersectia a doua multimi\n6. Diferenta a doua multimi\n7. Interogarea daca un numar apartine multimii A\n8. Iesire\nScrie numarul!\n");
    }

    return 0;
}
