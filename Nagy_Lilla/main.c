#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **inel, rows = 0, columns = 0, nrinele = 0;
    inel = initializare_structura(inel, &rows, &columns, &nrinele);
    printf("rows = %d, columns = %d, nrinele = %d\n", rows, columns, nrinele);
    afisare_matrice(inel, rows, columns, nrinele);
    inel = adaugare_inel(inel, &rows, &columns, &nrinele);
    printf("rows = %d, columns = %d, nrinele = %d\n", rows, columns, nrinele);
    afisare_matrice(inel, rows, columns, nrinele);
    inel = stergere_inel(inel, &rows, &columns, &nrinele);
    return 0;
}
