#include "NUMERE.h"

int palindrom(int x)
{
    int n = x;
    int i = 0;
    while (x != 0)
    {
        i = i * 10 + x % 10;
        x = x / 10;
    }
    if (n == i)
    {
        return 1;
    }
    return 0;
}

int cifre(int x)
{
    int nr = 0;
    while (x != 0)
    {
        nr++;
        x = x / 10;
    }
    return nr;
}

int max3(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (a > c)
        {
            return b;
        }
        else
        {
            if (b > c)
            {
                return b;
            }
            else
            {
                return c;
            }
        }
    }
}

int *perfect(int x)
{
    int *a = (int*) malloc(sizeof(int) * 5);
    a[0] = 6;
    a[1] = 28;
    a[2] = 496;
    a[3] = 8128;
    a[4] = 33550336;
    return a;
}

void perfects(int n)
{
    int i = 0, *a = perfect(n), found = 0;
    printf("The perfect numbers that are smaller than number %d:\n", n);
    while (i < 5 && found == 0)
    {
        if (n > a[i])
        {
            printf("%d ", a[i]);
            i++;
        }
        else
        {
            found = 1;
            if (i == 0)
            {
                printf("No perfect numbers that are smaller than number %d", n);
            }
        }
    }
}

int randomint(int min, int max)
{
    time_t t;
    srand((unsigned) time(&t));
    int y = rand() % (max - min);
    int x = y + min;
    return x;
}

int prim(unsigned long long int x)
{
    unsigned long long int j = 2;
    int prime = 1;
    while (j <= abs(sqrt(x)) && prime == 1)
    {
        if (x % j == 0)
        {
            prime = 0;
        }
        j++;
    }
    return prime;
}

void factorprim(unsigned long long int x)
{
    unsigned long long int i = 2;
    printf("Prime factors:\n");
    if (prim(x))
    {
        printf("The number is a prime\n");
    }
    else
    {
        while (i <= x && (x != 0))
        {
            printf("i = %d\n", i);
            printf("x = %d\n", x);
            if (prim(i) && (x % i == 0))
            {
                x = x / i;
                printf("%d ", i);
            }
            else
            {
                i++;
            }
        }
    }
}
