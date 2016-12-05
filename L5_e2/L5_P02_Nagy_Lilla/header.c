#include "header.h"

int prim(int x) //returns 1 if the number x is prime, 0 if not
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

int nrLength(int x) //returns the lenght of a number (how many numbers it's composed of)
{
    int n = 0;
    while (x > 0)
    {
        n++;
        x /= 10;
    }
    return n;
}

int circular(int x, int n, int isCirc, int it) // returns 1 if a number is circular, 0 otherwise
{
    if (n == x && isCirc && it != 0)
    {
        return 1;
    }
    if (n == x && !isCirc && it != 0)
    {
        return 0;
    }
    if (prim(x) == 0)
    {
        isCirc = 0;
        return 0;
    }
    x = (x % 10) * pow(10, nrLength(x) - 1) + x / 10;
    it++;
    circular(x, n, isCirc, it);
}

int findCirculars(int start, int end) // finds all circular numbers from a given interval
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (circular(i, i, 1, 0))
        {
            printf("%d ", i);
        }
    }
}
