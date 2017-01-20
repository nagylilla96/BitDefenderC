#include "MinHeap.h"

typedef struct {
    int number;
}ELEMENT;

ELEMENT *createNode(int number) {
    ELEMENT *myNode = (HEAPNODE*) malloc(sizeof(HEAPNODE));
    myNode->number = number;
    return myNode;
}

ELEMENT *getNode(int i, FILE *f) {
    int number;
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
    ELEMENT **myNode = (ELEMENT **) one->pointer;
    fprintf(f, "Print func entered\n");
    for (i = 0; i < one->nrOfElements; i++) {
        if (one->pointer == NULL) {
            fprintf(f, "Double pointer is null\n");
        }
        if (phonebook[i]->nume == NULL) {
            fprintf(f, "phonebook nume is null\n");
        }
        printFunc(one, i, f);
    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}