#include <stdio.h>
#include <stdlib.h>

int index = 0;

void recursion(int n, int sir[])
{
    printf("Index: %d\n");
    sir[index] = n;
    if (n == 1)
    {
        return;
    }
    if (n % 2 == 0)
    {
        index++;
        recursion(n/2,sir);
    }
    else
    {
        index++;
        recursion((3 * n) + 1,sir);
    }
}

int main()
{
    int n, sir[100], i;
    printf("Please input n! ");
    scanf("%d", &n);
    recursion(n,sir);
    printf("Result: \n");
    for (i = 0; i <= index; i++)
    {
        printf("%d ", sir[i]);
    }
    return 0;
}
