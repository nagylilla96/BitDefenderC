//
// Created by lilla on 19/12/16.
//

#include "Vector.h"

void** allocateVect(int size) {
    void **vector =  malloc(size * sizeof(void**));
    int i;
    for (i = 0; i < size; i++) {
        vector[i] = malloc(sizeof(void*));
    }
    return vector;
}

first *CreateVector(int size) {
    first* array = (first*) calloc(1, sizeof(first*));
    array->pointer = allocateVect(size);
    array->nrOfElements = 0;
    array->size = size;
    return array;
}

int new_entry(first* one, void* newNode, int index) { // add a new entry
    int i;
    if (newNode == NULL) {
        return 0;
    }
    if (one->nrOfElements + 1 >= one->size) {
        one->size *= 2;
        one->pointer = realloc(one->pointer, sizeof(one->pointer) * (one->size)); // if the data amount exceeds the size, realloc space
    }
    if (one->nrOfElements == index) {
        one->pointer[one->nrOfElements]= malloc(sizeof(newNode));
        one->pointer[one->nrOfElements] = newNode;
        if (one->pointer[one->nrOfElements] == NULL) {
            return 0;
        }
        return 1;
    }
    for (i = one->nrOfElements; i > index; i--) {
        one->pointer[i] = one->pointer[i - 1];
    }
    one->pointer[index] = newNode;
    if (one->pointer[index] == NULL) {
        return 0;
    }
    one->nrOfElements++;
    return 1;
}

int AddVectorItems(int nrOfItems, first* one, void*(*getNode)(int i, FILE *f), FILE *f) {
    int i;
    for (i = 0; i < nrOfItems; i++) {
        if (!new_entry(one, getNode(i, f), one->nrOfElements)) {
            return 0;
        }
        one->nrOfElements++;
    }
    return 1;
}

int PutVectorItem(int index, first* one, void* newNode) {
    if (new_entry(one, newNode, index)) {
        one->nrOfElements++;
        return 1;
    };
    return 0;
}

int GetVectorItem(int index, first* one, void(*printFunc)(first* one, int index, FILE *f), FILE *f) {
    if (one->pointer[index] != NULL) {
        fprintf(f, "The vector item with index %d is:\n", index);
        printFunc(one, index, f);
        return 1;
    }
    return 0;
}

int DeleteVectorItem(first* one, int index, void (*freeNode)(void* a)) {
    int i;
    if (one->pointer[index] != NULL) {
        freeNode(one->pointer[index]);
        free(one->pointer[index]);
        for (i = index; i < one->nrOfElements; i++) {
            one->pointer[i] = one->pointer[i + 1];
        }
        one->nrOfElements--;
        return 1;
    }
    return 0;
}

int SearchVectorItem(first *one, void* node, int(*cmpFunc)(void* a, void* b), void(*printFunc)(first* one, int index, FILE *f), FILE *f) { // find name by nume and prenume
    int i = 0;
    while (i < one->nrOfElements)
    {
        if (cmpFunc(one->pointer[i], node) == 0) { // if nume and prenume found
            printFunc(one, i, f);
            fprintf(f, "Found at index %d\n", i);
            return i;
        }
        i++;
    }
    return -1;
}

void* ReturnByIndex(first *one, void* index, int(*cmpFunc)(void* a, void* b)) {
    int i = 0;
    while (i < one->nrOfElements)
    {
        if (cmpFunc(one->pointer[i], index) == 0) { // if nume and prenume found
            return one->pointer[i];
        }
        i++;
    }
    return NULL;
}

void SortVector(first *one, int(*cmpFunct)(void *a, void *b)) { // sort data by name
    int i, j, n = one->nrOfElements;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) { // using an interesting version of boolean sort that i found
            if (cmpFunct(one->pointer[j], one->pointer[j + 1]) > 0) {
                first *temp;
                temp = one->pointer[j];
                one->pointer[j] = one->pointer[j + 1];
                one->pointer[j + 1] = temp;
            }
        }
    }
}

first *MergeVectors(first *one, first *two, first *three, int(*cmpFunct)(void *a, void *b)) {
    SortVector(one, cmpFunct);
    SortVector(two, cmpFunct);
    int i = 0, j = 0, k = 0, m = one->nrOfElements, n = two->nrOfElements, p;
    while (i < m && j < n) {

        if (cmpFunct(one->pointer[i], two->pointer[j]) < 0) {
            three->pointer[k] = malloc(sizeof(one->pointer[i]));
            three->pointer[k] = one->pointer[i];
            three->nrOfElements++;
            i++;
        }
        else {
            three->pointer[k] = malloc(sizeof(two->pointer[j]));
            three->pointer[k] = two->pointer[j];
            three->nrOfElements++;
            j++;
        }
        k++;
    }
    if (i < m) {
        for (p = i; p < m; p++) {
            three->pointer[k] = malloc(sizeof(one->pointer[p]));
            three->pointer[k] = one->pointer[p];
            three->nrOfElements++;
            k++;
        }
    }
    else {
        for (p = j; p < n; p++) {
            three->pointer[k] = malloc(sizeof(two->pointer[p]));
            three->pointer[k] = two->pointer[p];
            three->nrOfElements++;
            k++;
        }
    }
    return three;
}

void PrintVector(first* one, void(*printAllFunc)(first* one, FILE *f), FILE *f) { // show all elements from the phone book
    printAllFunc(one, f);
}

void DeleteVector(first *one, void(*freeFunct)(void *a)) {
    int i;
    one->nrOfElements = 0;
    for (i = 0; i < one->size; i++) {
        freeFunct(one->pointer[i]);
    }
    free(one->pointer);
    free(one);
}
