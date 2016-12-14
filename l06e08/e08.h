#ifndef MODULE_H_MODULE
#define MODULE_H_MODULE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b);
void sortAlph(char **arrayOfStrings, int n);
void read(FILE *f);
void show(char **arrayOfStrings, int n);

#endif
