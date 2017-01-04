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
    PutVectorItem(myNode->index, list, (size_t*) size, myNode);
}

node* REMOVE(int index, first *list, int(*cmpFunct)(void *a, void *b)) {
    node *myNode = GET(index, list, cmpFunct);
    DeleteVectorItem(list, index);
    return myNode;
}

node* GET(int index, first *list, int(*cmpFunc)(void *a, void *b)) {
    node myNode;
    myNode.element = 0;
    myNode.index = index;
    return ReturnByIndex(list, &myNode, cmpFunc);
}

int SEARCH(int element, first *list, int(*cmpFunct)(void *a, void *b)) {
    node myNode;
    myNode.index = 0;
    myNode.element = element;
    return SearchVectorItem(list, &myNode, cmpFunct, NULL);
}
