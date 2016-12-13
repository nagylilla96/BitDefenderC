#include "e06.h"

void inverse(FILE *f, FILE *g)
{
    int n, i;
    char ch;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    for (i = 0; i <= n; ++i)
    {
        fseek(f, -i, SEEK_END);
        ch = getc(f);
        fputc(ch, g);
    }
}
