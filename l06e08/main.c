#include "e08.h"

int main()
{
    FILE *f;
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("File read failed\n");
    }
    read(f);
    fclose(f);
    return 0;
}
