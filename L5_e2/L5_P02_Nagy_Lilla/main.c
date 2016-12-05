#include "header.h"

/* Created at 12/11/2016
    by Nagy Lilla
*/

int main()
{
    int start, end;
    printf("Please input start and end values!\n");
    scanf("%d %d", &start, &end);
    printf("start = %d, end = %d\n", start, end);
    //printf("circular(%d) = %d, circular(%d) = %d\n", start, circular(start, start, 1, 0), end, circular(end, end, 1, 0));
    findCirculars(start, end);
    return 0;
}
