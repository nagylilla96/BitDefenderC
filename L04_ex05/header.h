#ifndef MODULE_H_HEADER
#define MODULE_H_HEADER
#include <stdio.h>
#include <stdlib.h>

void allocate(int *a, int sizeA);
int compare(const void *a, const void *b);
void afisare(int *a, int*b, int sizeA, int sizeB);
void uniune(int *a, int *b, int sizeA, int sizeB);
void intersectie(int *a, int *b, int sizeA, int sizeB);
void diferenta(int *a, int *b, int sizeA, int sizeB);

#endif
