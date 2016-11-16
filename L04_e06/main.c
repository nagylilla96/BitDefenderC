#include "NUMERE.h"

int main()
{
    int n, m, o;
    unsigned long long int myLong;
    printf("Please introduce a number!\n");
    scanf("%d", &n);
    if (palindrom(n))
    {
        printf("\nNumber %d is palindrom\n", n);
    }
    else
    {
        printf("\nNumber %d is not palindrom\n", n);
    }
    printf("The number of digits in number %d is %d\n", n, cifre(n));
    printf("Please introduce two other numbers!\n");
    scanf("%d %d", &m, &o);
    printf("The biggest of the numbers %d, %d and %d is %d\n", n, m, o, max3(n, m, o));
    printf("n = %d \n", n);
    perfects(n);
    if (o < m)
    {
        int temp = o;
        o = m;
        m = temp;
    }
    printf("\nA random int from the range [%d, %d] is: %d\n", m, o, randomint(m, o));
    printf("Introduce an long long int!\n");
    scanf("%llu", &myLong);
    factorprim(myLong);
    return 0;
}
