#include <stdio.h>
#include <math.h>
#include "header.h"

int main()
{
	int a = 2;
	int b = 3;
	int n = 3;
	if (TESTEAZA(a,b,n) == 0)
	{
		printf("Not in interval\n");
	}
	else
	{
		printf("In interval");
	}
	printf("Media: %lf\n", MEDIA(a, b, n));
	printf("Polinom: %d\n", POLINOM(1));
	return 0;
}
