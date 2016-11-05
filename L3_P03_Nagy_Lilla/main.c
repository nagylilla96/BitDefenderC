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
    printf("%d\n", numar);
    return numar;
}

unsigned int inversare_biti(unsigned int numar, int pozitie_start, int nr_biti)
{
    unsigned int masca = create_mask(pozitie_start, nr_biti);
    return masca ^ numar;
}



int main()
{
    printf("Result: %d", inversare_biti(139,2,4));
    return 0;
}
