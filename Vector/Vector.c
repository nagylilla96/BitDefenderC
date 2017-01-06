//
// Created by lilla on 19/12/16.
//

#include "Vector.h"

void** allocateVect(size_t size) {
    void **vector =  malloc(size * sizeof(void**));
    int i;
    for (i = 0; i < size; i++) {
        vector[i] = malloc(sizeof(void*));
    }
    return vector;
}

first *CreateVector(size_t size) {
    first* array = (first*) malloc(sizeof(first*));
    array->pointer = allocateVect(size);
    array->nrOfElements = 0;
    return array;
}

void new_entry(first* one, void* newNode, size_t *size, int index) { // add a new entry
    int i;
    if (one->nrOfElements + 1 >= *size) {
        *size *= 2;
        one->pointer = realloc(one->pointer, sizeof(one->pointer) * (*size)); // if the data amount exceeds the size, realloc space
    }
    if (one->nrOfElements == index) {
        one->pointer[one->nrOfElements]= malloc(sizeof(newNode));
        one->pointer[one->nrOfElements] = newNode;
    }
    else {
        for (i = one->nrOfElements; i > index; i--) {
            one->pointer[i] = one->pointer[i - 1];
        }
        one->pointer[index] = newNode;
    }
    one->nrOfElements++;
}

void AddVectorItems(int nrOfItems, first* one, size_t *size, void*(*getNode)(int i)) {
    int i;
    for (i = 0; i < nrOfItems; i++) {
        new_entry(one, getNode(i), size, one->nrOfElements);
    }
}

void PutVectorItem(int index, first* one, size_t *size, void* newNode) {
    new_entry(one, newNode, size, index);
}

void GetVectorItem(int index, first* one, void(*printFunc)(first* one, int index)) {
    printf("The vector item with index %d is:\n", index);
    printFunc(one, index);
}

void DeleteVectorItem(first* one, int index) {
    int i;
    for (i = index; i < one->nrOfElements; i++) {
        one->pointer[i] = one->pointer[i + 1];
    }
    one->nrOfElements--;
}

int SearchVectorItem(first *one, void* node, int(*cmpFunc)(void* a, void* b), void(*printFunc)(first* one, int index)) { // find name by nume and prenume
    int i = 0;
    while (i < one->nrOfElements)
    {
        if (cmpFunc(one->pointer[i], node) == 0) { // if nume and prenume found
            printFunc(one, i);
            printf("Found at index %d\n", i);
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
    printf("three->nrOfElements = %d\n", three->nrOfElements);
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
    printf("three->nrOfElements = %d\n", three->nrOfElements);
    return three;
}

void PrintVector(first* one, void(*printAllFunc)(first* one)) { // show all elements from the phone book
    printAllFunc(one);
}

void DeleteVector(first *one, size_t size) {
    int i;
    one->nrOfElements = 0;
    for (i = 0; i < size; i++) {
        free(one->pointer[i]);
    }
    free(one->pointer);
    free(one);
}
