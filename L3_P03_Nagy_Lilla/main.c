#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int create_mask(int pozitie_start, int nr_biti)
{
    int i;
    int numar = 0;
    for (i = pozitie_start; i < pozitie_start + nr_biti; i++)
    {
        numar += pow(2, i);
    }
    return numar;
}

unsigned int inversare_biti(unsigned int numar, int pozitie_start, int nr_biti)
{
    unsigned int masca = create_mask(pozitie_start, nr_biti);
    return masca ^ numar;
}

int main()
{
    unsigned int number;
    int pozitie_start, nr_biti;
    printf("Please input number! ");
    scanf("%d", &number);
    printf("Please input start position! ");
    scanf("%d", &pozitie_start);
    printf("Please input number of bits! ");
    scanf("%d", &nr_biti);
    printf("Result: %d", inversare_biti(number, pozitie_start, nr_biti));
    return 0;
}
