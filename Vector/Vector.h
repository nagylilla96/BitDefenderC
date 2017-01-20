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
int new_entry(first* one, void* newNode, size_t *size, int index);
void PrintVector(first* one, void(*printAllFunc)(first* one, FILE *f), FILE *f);
int SearchVectorItem(first *one, void* node, int(*cmpFunc)(void* a, void* b), void(*printFunc)(first* one, int index, FILE *f), FILE *f);
void* ReturnByIndex(first *one, void* index, int(*cmpFunc)(void* a, void* b));
int AddVectorItems(int nrOfItems, first* one, size_t *size, void*(*getNode)(int i, FILE *f), FILE *f);
int PutVectorItem(int index, first* one, size_t *size, void* newNode);
int GetVectorItem(int index, first* one, void(*printFunc)(first* one, int index, FILE *f), FILE *f);
int DeleteVectorItem(first* one, int index, void (*freeNode)(void* a));
void SortVector(first *one, int(*cmpFunc)(void *a, void *b));
first *MergeVectors(first *one, first *two, first *three, int(*cmpFunct)(void *a, void *b));
void DeleteVector(first *one, size_t size, void(*freeFunct)(void *a));

#endif //VECTOR_VECTOR_H
