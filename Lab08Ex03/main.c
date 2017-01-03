#include <stdio.h>
#include <Vector.h>
#include "lab8e3.h"

typedef struct {
    int index;
    int element;
} node;

node *createNode(int index, int element) {
    node *myNode = (node*) malloc(sizeof(node));
    myNode->index = index;
    myNode->element = element;
    return myNode;
}

void newItem(int index, int element, first *list, size_t size) {
    node *myNode = createNode(index, element);
    new_entry(list, myNode, &size, list->nrOfElements);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}