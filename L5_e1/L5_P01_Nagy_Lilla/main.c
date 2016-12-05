#include <stdio.h>
#include <stdlib.h>
#include "module.h"

int main()
{
    int *a, *b, n = 0, x, length;
    printf("Please input your numbers!\n");
    a = read(a, &n);
    printf("\nThe array is:\n");
    write(a, n);
    printf("\nThe subsequence is:\n");
    b = subsequence(a, n, &length);
    write(b, length);
    return 0;
}
