//
// Created by lilla on 20/01/17.
//

#include "MinHeap.h"
#include "Vector.h"

//We use vectors for the heap, therefore many of my vector library's elements are used.
//basically it's a vector, but implemented in such a way that it can also be displayed in tree structure

MINHEAP *CreateHeap(int size) { // create a heap (allocate, initialize and return)
    MINHEAP *minheap = calloc(1, sizeof(MINHEAP));
    minheap->vector = CreateVector(size);
    minheap->size = size;
    minheap->nrOfElements = 0;
    return minheap;
}

int isHeapOK(MINHEAP *minheap, int (*cmpFunct)(void *a, void *b)) {// checks if heap is in the right order
    int i;
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

MINHEAP *correctHeapBottomUp(MINHEAP *minheap, int(*cmpFunct)(void *a, void *b)) {//correct the heap bottom up
    int i = minheap->nrOfElements - 1; // from children jump to parents based on formula
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

MINHEAP *correctHeapTopDown(MINHEAP *minheap, int index, int(*cmpFunct)(void *a, void *b)) { // correct the heap
    int i = index; // top down -> from parents jump to children based on formula
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
    if (AddVectorItems(1, minheap->vector, getNode, f)) { // add a new item to the heap and correct it bottom up
        minheap->nrOfElements++;
        minheap = correctHeapBottomUp(minheap, cmpFunct);
        return 1;
    };
    return 0;
}

void *GetHeapMin(MINHEAP *minheap) { // get the heap's smallest value
    return minheap->vector->pointer[0];
}

int DeleteHeapMin(MINHEAP *minheap, void (*freeNode), int(*cmpFunct)(void *a, void *b)) { // delete the smallest item
    HEAPNODE *node = NULL; //from the heap and correct it top down
    minheap->vector->pointer[0] = minheap->vector->pointer[minheap->nrOfElements - 1];
    minheap->vector->pointer[minheap->nrOfElements - 1] = NULL;
    minheap->nrOfElements--;
    minheap->vector->nrOfElements--;
    minheap = correctHeapTopDown(minheap, 0, cmpFunct);
    return 1;
}

int DeleteHeapItem(MINHEAP *minheap, void *element, void(*freeNode), int(cmpFunct)(void *a, void *b),
                   void(*printFunc)(first* one, int index, FILE *f), FILE *f) { // delete an item from the heap
    int index = SearchVectorItem(minheap->vector, element, cmpFunct, printFunc, f); // and correct it top down
    HEAPNODE *node = NULL;
    minheap->vector->pointer[index] = minheap->vector->pointer[minheap->nrOfElements - 1];
    minheap->vector->pointer[minheap->nrOfElements - 1] = NULL;
    minheap->nrOfElements--;
    minheap->vector->nrOfElements--;
    minheap = correctHeapTopDown(minheap, index, cmpFunct);
    return 1;
}

MINHEAP *MergeMinHeaps(MINHEAP *minheap1, MINHEAP *minheap2,int(*cmpFunct)(void *a, void *b)){
    MINHEAP *resultHeap = CreateHeap(minheap1->size + minheap2->size); // merge heaps
    resultHeap->vector = MergeVectors(minheap1->vector, minheap2->vector, resultHeap->vector, cmpFunct);
    return resultHeap;
}

void PrintHeap(MINHEAP *minheap, void(*printAllFunct)(first *one, FILE *f), FILE *f) {
    PrintVector(minheap->vector, printAllFunct, f); //print a heap's all elements
}

void PrettyPrint(MINHEAP *minheap, int index, int level, void(*anotherPrintFunc)(first* one, int index, FILE *f), FILE *f){
    if (index >= minheap->vector->nrOfElements) { // print a heap in tree form
        return;
    }
    PrettyPrint(minheap, 2 * index + 2, level + 1, anotherPrintFunc, f);
    for (int i = 0; i < level; i++){
        fprintf(f, "   ");
    }
    anotherPrintFunc(minheap->vector, index, f);
    fprintf(f, "\n");
    PrettyPrint(minheap, 2 * index + 1, level + 1, anotherPrintFunc, f);
}

void DeleteHeap(MINHEAP *minheap, void(*freeFunction)(void *a)) { // delete a heap completely
    DeleteVector(minheap->vector, freeFunction);
    free(minheap);
}