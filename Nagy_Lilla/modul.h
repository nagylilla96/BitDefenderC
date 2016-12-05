#ifndef MODUL_H
#define MODUL_H
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

int **initializare_structura(int **inel, int *rows, int *columns, int *nrinele);
void afisare_matrice(int **a, int rows, int columns, int nrinele);
int **adaugare_inel(int **a, int *rows, int *columns, int *nrinele);
int **stergere_inel(int **a, int *rows, int *columns, int *nrinele);

#endif
