#include <stdio.h>
#include <stdlib.h>

int nrOfBits(int numar, int baza)
{
    if (baza <= 1 || baza > 36)
    {
        printf("The number is not correct! Aborting...\n");
        return 0;
    }
    int nr = 0;
    while (numar / baza != 0)
    {
        nr++;
        numar /= baza;
    }
    nr++;
    return nr;
}

void itob(int numar, char sir[], int baza)
{
    int i = nrOfBits(numar, baza) - 1;
    if (baza <= 1 || baza > 36)
    {
        printf("The number is not correct! Aborting...");
        return 0;
    }
    while (numar != 0)
    {
        if (numar % baza >= 10)
        {
            sir[i] = (char) 'A' + (numar % baza - 10);
        }
        else
        {
            sir[i] = numar % baza;
        }
        i--;
        numar /= baza;
    }
}

int main()
{
    int number, base, i;
    char *sir;
    printf("Please input the number! ");
    scanf("%d", &number);
    printf("Please input the base! ");
    scanf("%d", &base);
    if (base <= 1 || base > 36)
    {
        printf("The inputted number is not good! You have to input a number between 2 and 36!\n");
        scanf("%d", &base);
    }
    if (nrOfBits(number, base) != 0)
    {
        sir = malloc(sizeof(char) * nrOfBits(number, base));
        itob(number, sir, base);
        printf("Result:\n");
        for (i = 0; i < nrOfBits(number, base); i++)
        {
            if (sir[i] >= 'A' && sir[i] <= 'Z')
            {
                printf("%c", sir[i]);
            }
            else
            {
                printf("%d", sir[i]);
            }
        }
    }
    return 0;
}
