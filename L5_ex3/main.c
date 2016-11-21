#include "ex3.h"
//Created at 21/11/2016
//by Nagy Lilla

int main()
{
    int n, **a;
    printf("Please input the size of the matrix!\n");
    scanf("%d", &n);
    a = read(a, n);
    write(a, n);
    sumaLinii(a, n);
    sumaColoane(a, n);
    sumaMainDiagonal(a, n);
    sumaSecondaryDiagonal(a, n);
    return 0;
}
