#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    f = fopen("file.txt", "r");
    read(f);
    fclose(f);
    return 0;
}
