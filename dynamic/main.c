#include <stdio.h>
#include <stdlib.h>

int *read(int *a, int *n)
{
    int i, x;
    scanf("%d", &x);
    a = (int*) calloc(1, sizeof(int));
    while (x != -1)
    {
        printf("n = %d, x = %d", *n, x);
        a[*n] = x;
        printf("a[%d] = %d", *n, a[*n]);
        (*n)++;
        a = (int*) realloc(a, sizeof(int) * (*n));
        scanf("%d", &x);

    }
    return a;
}

void write(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int *a, n = 0;
    a = read(a, &n);
    write(a, n);
    return 0;
}
