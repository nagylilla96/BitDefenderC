#include "e07.h"

int main(int argc, char *argv[])
{
    FILE *f, *g;
    f = fopen(argv[1], "r");
    g = fopen(argv[2], "w");
    inverse(f, g);
    fclose(f);
    fclose(g);
    return 0;
}
