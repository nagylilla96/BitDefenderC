#ifndef MODULE_H_MODULE
#define MODULE_H_MODULE
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int **read(int **a, int n);
void write(int **a, int n);
void sumaLinii(int **a, int n);
void sumaColoane(int **a, int n);
void sumaMainDiagonal(int **a, int n);
void sumaSecondaryDiagonal(int **a, int n);

#endif
