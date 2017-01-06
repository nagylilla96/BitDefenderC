//
// Created by lilla on 03/01/17.
//

#include <Vector.h>
#include "lab8e3.h"

first* CreateArraySequence(int size) {
    return (first*) CreateVector((size_t) size);
}

void ADD(first* list, int *size, node*(*getNode)(int i, first* list)) {
    node *myNode = getNode(0, (first*) list);
    if (myNode == NULL) {
        printf("My node is null\n");
        return;
    }
    printf("Add entered\n");
    int i;
    if (list->nrOfElements + 1 >= *size) {
        *size *= 2;
        list->pointer = realloc(list->pointer, sizeof(list->pointer) * (*size)); // if the data amount exceeds the size, realloc space
    }
    if (list->nrOfElements == myNode->index) {
        list->pointer[list->nrOfElements]= malloc(sizeof(myNode));
        list->pointer[list->nrOfElements] = myNode;
    }
    else {
        for (i = list->nrOfElements; i > myNode->index; i--) {
            list->pointer[i] = list->pointer[i - 1];
            ((node*)list->pointer[i])->index ++;
        }
        list->pointer[myNode->index] = myNode;
    }
    list->nrOfElements++;
}

node* REMOVE(int index, first *list, int(*cmpFunct)(void *a, void *b)) {
    node *myNode = GET(index, list, cmpFunct);
    int i;
    for (i = index; i < list->nrOfElements; i++) {
        list->pointer[i] = list->pointer[i + 1];
        ((node*)list->pointer[i])->index --;
    }
    list->nrOfElements--;
    return myNode;
}

node* GET(int index, first *list, int(*cmpFunc)(void *a, void *b)) {
    node myNode;
    myNode.element = 0;
    myNode.index = index;
    return ReturnByIndex(list, &myNode, cmpFunc);
}

int SEARCH(int element, first *list, int(*cmpFunct)(void *a, void *b), int(*printFunct)()) {
    node myNode;
    myNode.index = 0;
    myNode.element = element;
    return SearchVectorItem(list, &myNode, cmpFunct, printFunct);
}
