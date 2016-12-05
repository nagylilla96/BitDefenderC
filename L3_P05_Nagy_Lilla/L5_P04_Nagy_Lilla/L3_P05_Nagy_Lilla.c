#include "l5_ex4.h"

//Corrected on 21/11/2016
//by Nagy Lilla

int main()
{
    int size = INT_MAX / sizeof(int);
    int answer, *a, *b, n1, n2 = 0, x;
    printf("Ce vrei sa faci?\n1. Introduc o multime\n2. Afisarea multimii\n3. Cardinalitatea multimii\n4. Reuniunea a doua multimi\n5. Intersectia a doua multimi\n6. Diferenta a doua multimi\n7. Interogarea daca un numar apartine multimii A\n8. Iesire\nScrie numarul!\n");
    while (scanf("%d", &answer) >= 0)
    {
        switch(answer)
        {
        case 1:
            a = introduc(a, &n1);
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
