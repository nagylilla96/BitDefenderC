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

node *getNode(int i) {
    int index, element;
    printf("Index: ");
    scanf("%d", &index);
    printf("Element: ");
    scanf("%d", &element);
    return createNode(index, element);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}