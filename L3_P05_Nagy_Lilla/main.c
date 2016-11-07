#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

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
    *n = max / 32 + 1;
    return;
}

void afis(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return;
}

int card(int a[], int n)
{
    int i, j, nr = 0, x;
    printf("n = %d\n", n);
    for (i = 0; i < n; i++)
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
        c = malloc(n1);
    }
    else
    {
        c = malloc(n2);
    }
    for (i = 0; i < sizeof(c); i++)
    {
        c[i] = a[i] | b[i];
    }
    afis(c, sizeof(c));
}

void intersectie(int a[], int n1, int b[], int n2)
{
    int *c, i;
    if (n1 > n2)
    {
        c = malloc(n1);
    }
    else
    {
        c = malloc(n2);
    }
    for (i = 0; i < sizeof(c); i++)
    {
        c[i] = a[i] & b[i];
    }
    afis(c, sizeof(c));
}

void dif(int a[], int n1, int b[], int n2)
{
    int *c, i, j, nr = 0, x, y;
    if (n1 > n2)
    {
        c = malloc(n1);
    }
    else
    {
        c = malloc(n2);
    }
    for (i = 0; i < sizeof(c); i++)
    {
        x = a[i];
        y = b[i];
        c[i] = 0;
        for (j = 0; j < 32; j++)
        {
            printf("x= %d, y= %d\n", x, y);
            if ((x%2 == 1) && (y % 2 == 0))
            {
                c[i] += pow(2, j);
                printf("*");
            }
            x = x >> 1;
            y = y >> 1;
        }
        printf("\n");
    }
    afis(c, sizeof(c));
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
    int size = INT_MAX / 32;
    int answer, *a, *b, n1, n2 = 0, x;
    a = malloc(size);
    b = malloc(size);
    printf("Ce vrei sa faci?\n1. Introduc o multime\n2. Afisarea multimii\n3. Cardinalitatea multimii\n4. Reuniunea a doua multimi\n5. Intersectia a doua multimi\n6. Diferenta a doua multimi\n7. Interogarea daca un numar apartine unei multimi\n8. Iesire\nScrie numarul!\n");
    while (scanf("%d", &answer) >= 0)
    {
        switch(answer)
        {
        case 1:
            introduc(a, &n1);
            printf("n1 = %d\n", n1);
            break;
        case 2:
            afis(a,n1);
            break;
        case 3:
            printf("%d\n", card(a,n1));
            break;
        case 4:
            printf("Introduce o alta multime!\n");
            introduc(b, &n2);
            printf("n2 = %d\n", n2);
            afis(b, n2);
            printf("%d\n", card(b,n2));
            reuniune(a,n1,b,n2);
            break;
        case 5:
            printf("Introduce o alta multime!\n");
            introduc(b, &n2);
            printf("n2 = %d\n", n2);
            afis(b, n2);
            printf("%d\n", card(b,n2));
            intersectie(a,n1,b,n2);
            break;
        case 6:
            printf("Introduce o alta multime!\n");
            introduc(b, &n2);
            printf("n2 = %d\n", n2);
            afis(b, n2);
            printf("%d\n", card(b,n2));
            dif(a,n1,b,n2);
            break;
        case 7:
            printf("Ce numar vrei sa verifici?");
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
        printf("Ce vrei sa faci?\n1. Introduc o multime\n2. Afisarea multimii\n3. Cardinalitatea multimii\n4. Reuniunea a doua multimi\n5. Intersectia a doua multimi\n6. Diferenta a doua multimi\n7. Interogarea daca un numar apartine unei multim\n8. Iesire\nScrie numarul!\n");
    }

    return 0;
}
