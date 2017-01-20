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
//TODO print
//TODO add
//TODO get
//TODO deleteMin
//TODO deleteMax
//TODO merge
//TODO delete


#endif //MINHEAP_MINHEAP_H
