#include "MinHeap.h"

typedef struct {
    int number;
}ELEMENT;

void *createNode(int number) {
    ELEMENT *myNode = (ELEMENT*) malloc(sizeof(ELEMENT));
    myNode->number = number;
    return myNode;
}

void *getNode(int i, FILE *f) {
    int number;
    printf("number = ");
    fscanf(f, "%d", &number);
    return createNode(number);
}

void printFunc(first* one, int index, FILE *f) {
    fprintf(f, "index = %d\n", index);
    ELEMENT **myNode = (ELEMENT**) one->pointer;
    fprintf(f, "number = %d\n", myNode[index]->number);
}

void printAllFunc(first* one, FILE *f) {
    int i;
    for (i = 0; i < one->nrOfElements; i++) {
        printFunc(one, i, f);
    }
}

int cmpFunct(void *a, void *b) {//compares two elements
    ELEMENT *aa = (ELEMENT *) a;
    ELEMENT *bb = (ELEMENT *) b;
    if (aa->number > bb->number) {
        return 1;
    }
    if (aa->number == bb->number) {
        return 0;
    }
    return -1;
}

void freeNode(void *a) {
    return;
}

int main() {
    MINHEAP *minheap = CreateHeap(50);
    int i;
    for (i = 0; i < 7; i++) {
        AddHeapItem(minheap, getNode, stdin, cmpFunct);
        PrintHeap(minheap, printAllFunc, stdout);
    }
    DeleteHeapMin(minheap, freeNode, cmpFunct);
    PrintHeap(minheap, printAllFunc, stdout);
    HEAPNODE *node = getNode(0, stdin);
    if (node == NULL){
        printf("Node is null\n");
    }
    DeleteHeapItem(minheap, node, freeNode, cmpFunct, printFunc, stdout);
    PrintHeap(minheap, printAllFunc, stdout);
    return 0;
}