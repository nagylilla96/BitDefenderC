//
// Created by lilla on 20/01/17.
//

#ifndef MINHEAP_MINHEAP_H
#define MINHEAP_MINHEAP_H
#include <stdio.h>
#include "Vector.h"
#include <stdlib.h>

typedef struct {
    void *element;
}HEAPNODE;

typedef struct {
    int size;
    first *vector;
    int nrOfElements;
}MINHEAP;

MINHEAP *CreateHeap(int size);
void PrintHeap(MINHEAP *minheap, void(*printAllFunct)(first *one, FILE *f), FILE *f);
int AddHeapItem(MINHEAP *minheap, void*(*getNode)(int i, FILE *f), FILE *f, int(*cmpFunct)(void *a, void *b));
MINHEAP *correctHeapTopDown(MINHEAP *minheap, int index, int(*cmpFunct)(void *a, void *b));
int isHeapOK(MINHEAP *minheap, int (*cmpFunct)(void *a, void *b));
void *GetHeapMin(MINHEAP *minheap);
int DeleteHeapMin(MINHEAP *minheap, void (*freeNode), int(*cmpFunct)(void *a, void *b));
int DeleteHeapItem(MINHEAP *minheap, void *element, void(*freeNode), int(cmpFunct)(void *a, void *b), void(*printFunc)(first* one, int index, FILE *f), FILE *f);
MINHEAP *MergeMinHeaps(MINHEAP *minheap1, MINHEAP *minheap2,int(*cmpFunct)(void *a, void *b));
void DeleteHeap(MINHEAP *minheap, void(*freeFunction)(void *a));
void PrettyPrint(MINHEAP *minheap, int index, int level, void(*anotherPrintFunc)(first* one, int index, FILE *f), FILE *f);

#endif //MINHEAP_MINHEAP_H
