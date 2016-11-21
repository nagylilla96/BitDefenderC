#include <stdio.h>
#include <stdlib.h>

int main()
{
    int start, end;
    printf("Please input start and end values!\n");
    scanf("%d %d", &start, &end);
    printf("start = %d, end = %d\n", start, end);
    printf("circular(%d) = %d, circular(%d) = %d\n", start, circular(start), end, circular(end));
    return 0;
}
