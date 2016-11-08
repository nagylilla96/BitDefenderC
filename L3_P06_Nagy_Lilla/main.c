#include <stdio.h>
#include <stdlib.h>

int index = 0;

void recursion(int n)
{
    printf("%d ", n);
    if (n == 1)
    {
        return;
    }
    if (n % 2 == 0)
    {
        index++;
        recursion(n/2);
    }
    else
    {
        index++;
        recursion((3 * n) + 1);
    }
}

int main()
{
    int n, sir[100], i;
    printf("Please input n! ");
    scanf("%d", &n);
    printf("Result: \n");
    recursion(n);
    return 0;
}
