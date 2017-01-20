#include "MinHeap.h"
#include "Vector.h"

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

void anotherPrintFunc(first *one, int index, FILE *f) {
    ELEMENT **myNode = (ELEMENT**) one->pointer;
    fprintf(f, "%d", myNode[index]->number);
}

void printAllFunc(first* one, FILE *f) {
    int i;
    printf("nr of elements: %d\n", one->nrOfElements);
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
    MINHEAP *minheap1 = CreateHeap(50);
    MINHEAP *minheap2 = CreateHeap(50);
    MINHEAP *minheap3;
    int i;
    for (i = 0; i < 7; i++) {
        AddHeapItem(minheap1, getNode, stdin, cmpFunct);
    }
    PrettyPrint(minheap1, 0, 0, anotherPrintFunc, stdout);
    DeleteHeapMin(minheap1, freeNode, cmpFunct);
    PrintHeap(minheap1, printAllFunc, stdout);
    HEAPNODE *node = getNode(0, stdin);
    if (node == NULL){
        printf("Node is null\n");
    }

    DeleteHeapItem(minheap1, node, freeNode, cmpFunct, printFunc, stdout);
    PrintHeap(minheap1, printAllFunc, stdout);
    printf("Heapmin: \n");
    ELEMENT *myElement = GetHeapMin(minheap1);
    printf("number = %d\n", myElement->number);
    for (i = 0; i < 4; i++) {
        AddHeapItem(minheap2, getNode, stdin, cmpFunct);
        PrintHeap(minheap2, printAllFunc, stdout);
    }
    minheap3 = MergeMinHeaps(minheap1, minheap2, cmpFunct);
    PrettyPrint(minheap3, 0, 0, anotherPrintFunc, stdout);
    DeleteHeap(minheap1, freeNode);
    DeleteHeap(minheap2, freeNode);
    DeleteHeap(minheap3, freeNode);
    free(minheap1);
    free(minheap2);
    free(minheap3);
    return 0;
}