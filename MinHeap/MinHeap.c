//
// Created by lilla on 20/01/17.
//

#include "MinHeap.h"

MINHEAP *CreateHeap(int size) {
    MINHEAP *minheap = calloc(1, sizeof(MINHEAP));
    minheap->vector = CreateVector(size);
    minheap->size = size;
    minheap->nrOfElements = 0;

}

int AddHeapItem(MINHEAP *minheap, int size, void*(*getNode)(int i, FILE *f), FILE *f) {
    AddVectorItems(1, minheap->vector, size, getNode, f);
    minheap->nrOfElements++;
    return 1;
}

void PrintHeap()
