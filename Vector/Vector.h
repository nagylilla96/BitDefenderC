//
// Created by lilla on 19/12/16.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t size;

typedef struct {
    void **pointer;
    int nrOfElements;
} first;

void** allocateVect(size_t size);
first *CreateVector(size_t size);
void new_entry(first* one, void* newNode, size_t *size);
void PrintVector(first* one, void(*printAllFunc)(first*));
int findName(first *one, void* node, int(*cmpFunc)(void* a, void* b), void(*printFunc)(first* one, int index));
void AddVectorItems(int nrOfItems, first* one, size_t *size, void(*newItem)(char *nume, char *prenume, char *adresa, char *telefon, first *one, size_t size));

#endif //VECTOR_VECTOR_H
