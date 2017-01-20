//
// Created by lilla on 20/01/17.
//

#include "MinHeap.h"
#include "Vector.h"

MINHEAP *CreateHeap(int size) {
    MINHEAP *minheap = calloc(1, sizeof(MINHEAP));
    minheap->vector = CreateVector(size);
    minheap->size = size;
    minheap->nrOfElements = 0;
}

int isHeapOK(MINHEAP *minheap, int (*cmpFunct)(void *a, void *b)) {
    int i = minheap->nrOfElements - 1;

    for (i = minheap->nrOfElements - 1; i >= 0; i--) {
        if (i == 0){
            return 1;
        }
        if (cmpFunct(minheap->vector->pointer[i], minheap->vector->pointer[(i - 1) / 2])< 0){
            return 0;
        }
    }
    return 1;
}

MINHEAP *correctHeapBottomUp(MINHEAP *minheap, int(*cmpFunct)(void *a, void *b)) {
    int i = minheap->nrOfElements - 1;
    HEAPNODE *heapnode = NULL;
    while (!isHeapOK(minheap, cmpFunct)){
        if (cmpFunct(minheap->vector->pointer[i], minheap->vector->pointer[(i - 1) / 2]) < 0 ) {
            heapnode = minheap->vector->pointer[i];
            minheap->vector->pointer[i] = minheap->vector->pointer[(i - 1) / 2];
            minheap->vector->pointer[(i - 1) / 2] = heapnode;
        }
        i = (i - 1) / 2;
    }
    return minheap;
}

MINHEAP *correctHeapTopDown(MINHEAP *minheap, int(*cmpFunct)(void *a, void *b)) {
    int i = 0;
    HEAPNODE *child1 = NULL, *child2 = NULL, *heapnode = NULL, *parent = NULL;
    while (!isHeapOK(minheap, cmpFunct)) {
        child1 = NULL;
        child2 = NULL;
        parent = minheap->vector->pointer[i];
        if (minheap->nrOfElements > 2 * i + 2) {
            child1 = minheap->vector->pointer[2 * i + 1];
            child2 = minheap->vector->pointer[2 * i + 2];
        }
        if (child1 != NULL && child2 == NULL) {
            if (cmpFunct(parent, child2) > 0){
                heapnode = parent;
                parent = child2;
                child2 = heapnode;
                i = 2 * i + 2;
            }
        }
        if (child1 != NULL && child2 != NULL ) {
            if (!(cmpFunct(parent, child1) < 0 && cmpFunct(parent, child2) < 0)){
                if (cmpFunct(child1, child2) < 0) {
                    heapnode = minheap->vector->pointer[i];
                    minheap->vector->pointer[i] = minheap->vector->pointer[2 * i + 1];
                    minheap->vector->pointer[2 * i + 1] = heapnode;
                    i = 2 * i + 1;
                }
                else {
                    heapnode = minheap->vector->pointer[i];
                    minheap->vector->pointer[i] = minheap->vector->pointer[2 * i + 2];
                    minheap->vector->pointer[2 * i + 2] = heapnode;
                    i = 2 * i + 2;
                }
            }
        }
    }
    return minheap;
}

int AddHeapItem(MINHEAP *minheap, void*(*getNode)(int i, FILE *f), FILE *f, int(*cmpFunct)(void *a, void *b)) {
    if (AddVectorItems(1, minheap->vector, getNode, f)) {
        minheap->nrOfElements++;
        minheap = correctHeapBottomUp(minheap, cmpFunct);
        return 1;
    };
    return 0;
}

void *GetHeapMin(MINHEAP *minheap) {
    return minheap->vector->pointer[0];
}

int DeleteHeapMin(MINHEAP *minheap, void (*freeNode), int(*cmpFunct)(void *a, void *b)) {
    HEAPNODE *node = NULL;
    minheap->vector->pointer[0] = minheap->vector->pointer[minheap->nrOfElements - 1];
    minheap->vector->pointer[minheap->nrOfElements - 1] = NULL;
    minheap->nrOfElements--;
    minheap->vector->nrOfElements--;
    minheap = correctHeapTopDown(minheap, cmpFunct);
    return 1;
}

int DeleteHeapItem(MINHEAP *minheap, void *element, void(*freeNode), int(cmpFunct)(void *a, void *b), void(*printFunc)(first* one, int index, FILE *f), FILE *f) {
    int index = SearchVectorItem(minheap->vector, element, cmpFunct, printFunc, f);
    if (DeleteVectorItem(minheap->vector, index, freeNode)){
        minheap->nrOfElements--;
        minheap->vector->nrOfElements--;
        minheap = correctHeapTopDown(minheap, cmpFunct);

        return 1;
    }
    return 0;
}

MINHEAP *MergeMinHeaps(MINHEAP *minheap1, MINHEAP *minheap2,int(*cmpFunct)(void *a, void *b)){
    MINHEAP *resultHeap = CreateHeap(minheap1->size + minheap2->size);
    resultHeap->vector = MergeVectors(minheap1->vector, minheap2->vector, resultHeap->vector, cmpFunct);
    return resultHeap;
}

void PrintHeap(MINHEAP *minheap, void(*printAllFunct)(first *one, FILE *f), FILE *f) {
    PrintVector(minheap->vector, printAllFunct, f);
}

void DeleteHeap(MINHEAP *minheap, void(*freeFunction)(void *a)) {
    DeleteVector(minheap->vector, freeFunction);
    free(minheap);
}