#include "header.h"

int prim(int x)
{
    int i;
    if (x < 2)
    {
        return 0;
    }
    for (i = 2; i <= abs(sqrt(x)); i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int nrLength(int x)
{
    int n = 0;
    while (x > 0)
    {
        n++;
        x /= 10;
    }
    return n;
}

int circular(int x, int n, int isCirc, int it)
{
    if (n == x && isCirc && it != 0)
    {
        return 1;
    }
    if (n == x && !isCirc && it != 0)
    {
        return 0;
    }
    if (!prim(x))
    {
        isCirc = 0;
        return 0;
    }
    x = (x % 10) * nrLength(x) + x / 10;
    it++;
    circular(x, n, isCirc, it);
}
