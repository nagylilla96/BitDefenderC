//
// Created by lilla on 14/12/16.
//

#ifndef L06E12_E12_H
#define L06E12_E12_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *expression;
    int result;
}LINE;

int readFile(FILE *f, int n, LINE *block);
void showResults(LINE *block);
void sortStruct(LINE *block, int n);
void writeResults(FILE *f, LINE *block, int n);

#endif //L06E12_E12_H
