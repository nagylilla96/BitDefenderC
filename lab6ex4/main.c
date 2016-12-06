#include "ex4.h"

int main()
{
    FILE *f;
    int n;
    f = fopen("file.txt", "r");
    printf("How many words do you want?\n");
    scanf("%d", &n);
    read(f, n);
    fclose(f);
    return 0;
}
