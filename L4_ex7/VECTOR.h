#ifndef MODULE_H_VECTOR
#define MODULE_H_VECTOR
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *read(int n);
void write(int *a, int n);
int *insert(int *a, int k, int x, int n);
int *myDelete(int *a, int k, int n);
int minFunc(int *a, int n);
int maxFunc(int *a, int n);
void majoritar(int *a, int n);
void intercalare(int *a, int *b, int sizeA, int sizeB);

#endif
