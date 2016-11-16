#include "VECTOR.h"

int main()
{
    int *a, *b, n, m, x, k;
    printf("How many elements do you want to have in vector a?\n");
    scanf ("%d", &n);
    a = read(n);
    write(a, n);
    printf("\nWhat number do you want to insert and on which position?\n");
    scanf("%d %d", &x, &k);
    a = insert(a, k, x, n);
    n++;
    write(a, n);
    printf("\nFrom which position do you want to delete?\n");
    scanf("%d", &k);
    a = myDelete(a, k, n);
    n--;
    write(a, n);
    printf("\nmin = %d, max = %d\n", a[minFunc(a, n)], a[maxFunc(a, n)]);
    majoritar(a, n);
    printf("How many elements do you want to have in vector b?\n");
    scanf ("%d", &m);
    b = read(n);
    write(b, n);
    intercalare(a, b, n, m);
    return 0;
}
