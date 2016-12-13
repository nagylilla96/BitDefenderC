#include "e08.h"

int main()
{
    FILE *f;
    f = fopen("input.txt", "r");
    read(f);
    fclose(f);
    return 0;
}
