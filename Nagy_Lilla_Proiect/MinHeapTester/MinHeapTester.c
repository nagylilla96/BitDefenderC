//
// Created by lilla on 20/01/17.
//

#include <MinHeap.h>
#include "MinHeapTester.h"

void *createNode(int number) { // creates a new node (allocate, initialize, return)
    ELEMENT *myNode = (ELEMENT*) malloc(sizeof(ELEMENT));
    myNode->number = number;
    return myNode;
}

void *getNode(int i, FILE *f) { // reads and creates a node
    int number;
    fscanf(f, "%d", &number);
    return createNode(number);
}

void printFunc(first* one, int index, FILE *f) { // prints a node
    fprintf(f, "index = %d\n", index);
    ELEMENT **myNode = (ELEMENT**) one->pointer;
    fprintf(f, "number = %d\n", myNode[index]->number);
}

void anotherPrintFunc(first *one, int index, FILE *f) { // prints one element of a node
    ELEMENT **myNode = (ELEMENT**) one->pointer;
    fprintf(f, "%d", myNode[index]->number);
}

void printAllFunc(first* one, FILE *f) { // prints all elements
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

void freeNode(void *a) { // free node (not needed)
    return;
}

void runTester(char *nameIN, char *nameOut) { //run the tester
    int size = 50; // we allocate a minheap of size 50
    MINHEAP **arrayOfHeaps = calloc(26, sizeof(MINHEAP*)); // we allocate an array of heaps
    printf("RunTester\n");
    int index = 0, elements;
    FILE *f = fopen(nameIN, "r");
    FILE *g = fopen(nameOut, "w");
    printf("%s\n", nameIN);
    if (f == NULL) {
        printf("input file is null\n");
    }
    if (g == NULL) {
        printf("output file is null\n");
    }
    char *instruction = malloc(sizeof(char) * 100);
    char *token, *token1;
    while (fgets(instruction, 100, f) != NULL) {
        printf("%s", instruction);
        token = strtok(instruction, " ");
        if (token != NULL) {
            switch (commandNr(token)) {
                case 0://creates a heap to the arrayOfHeaps starting from A to Z, depending on the set's name
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if(arrayOfHeaps[(int) *token - 65] != NULL){
                        printf("WHat the fuck\n");
                    }
                    if (token != NULL && strlen(token) == 1 && arrayOfHeaps[(int) *token - 65] == NULL) {
                        arrayOfHeaps[(int) *token - 65] = CreateHeap(size);
                        if (arrayOfHeaps[(int) *token - 65] == NULL) {
                            printf("Create was not successful\n");
                        };
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 1: // prints a heap
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        if (arrayOfHeaps[index]->vector == NULL ) {
                            printf("array pointer is null!\n");
                            break;
                        }
                        PrettyPrint(arrayOfHeaps[index], 0, 0, anotherPrintFunc, g);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 2:// adds a node to the heap
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        if (!AddHeapItem(arrayOfHeaps[index], getNode, f, cmpFunct)){
                            error(3, g, token);
                        }
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 3: // returns the smallest element of the heap
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        ELEMENT *returned = GetHeapMin(arrayOfHeaps[index]);
                        fprintf(g, "The smallest element is: %d\n", returned->number);
                        if (returned->number == NULL) {
                            error(3, g, token);
                        }
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 4: // deletes the smallest element of the heap
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        DeleteHeapMin(arrayOfHeaps[index], freeNode, cmpFunct);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 5: // deletes a heap element
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        HEAPNODE *node = getNode(0, f);
                        if (node == NULL){
                            printf("Node is null\n");
                        }
                        DeleteHeapItem(arrayOfHeaps[index], node, freeNode, cmpFunct, printFunc, g);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 6: // merges two heaps into a third one
                    token = strtok(NULL, " ");
                    token1 = strtok(NULL, " ");
                    token1[strlen(token1) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1
                        && token1 != NULL && strlen(token1) == 1){
                        index = (int) *token - 65;
                        int index1 = (int) *token1 - 65;
                        int index2 = index1 + 1;
                        while (arrayOfHeaps[index2] != NULL) {
                            index2++;
                        }
                        arrayOfHeaps[index2] = MergeMinHeaps(arrayOfHeaps[index], arrayOfHeaps[index1], cmpFunct);
                        if (arrayOfHeaps[index2] == NULL) {
                            printf("Array is null\n");
                        }
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 7: // deletes a heap completely
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1 && arrayOfHeaps[(int) *token - 65] != NULL){
                        index = (int) *token - 65;
                        DeleteHeap(arrayOfHeaps[index], freeNode);
                    }
                    else {
                        error(1, g, token);
                    }
                    arrayOfHeaps[index] = NULL;
                    break;
                default:
                    break;
            }
        }
    }
    fclose(f);
    fclose(g);
    free(arrayOfHeaps);
    free(instruction);
}

void error(int errorCode, FILE *f, char *command) {
    switch(errorCode) { // based on the error code, returns an error
        case 0:
            fprintf(f, "Error: Illegal operation. Data structure does not exist\n");
            break;
        case 1:
            fprintf(f, "Error: Unrecognized command: %s\n", command);
            break;
        case 2:
            fprintf(f, "Error: Type mismatch\n");
            break;
        case 3:
            fprintf(f, "Error: Missing value\n");
            break;
        case 4:
            fprintf(f, "Error: Index out of bounds\n");
            break;
        case 5:
            fprintf(f, "Error: Unrecognized hash function\n");
            break;
        case 6:
            fprintf(f, "Error: Memory allocation failed\n");
            break;
        case 7:
            fprintf(f, "Error: Item not found\n");
            break;
        case 8:
            fprintf(f, "Printing: Structure is empty\n");
            break;
        case 9:
            fprintf(f, "Error: Instance unknown\n");
            break;
        case 10:
            fprintf(f, "Error: attempt to recreate an existing structure\n");
            break;
        default:
            fprintf(f, "Undefined error\n");
            break;
    }
}

int commandNr(char *command) { // based on a command, returns a number, which can later be used in the switch-case
    if (strcmp(command, "CreateHeap") == 0) return 0;
    if (strcmp(command, "PrintHeap") == 0) return 1;
    if (strcmp(command, "AddHeapItem") == 0) return 2;
    if (strcmp(command, "GetHeapMin") == 0) return 3;
    if (strcmp(command, "DeleteHeapMin") == 0) return 4;
    if (strcmp(command, "DeleteHeapItem") == 0) return 5;
    if (strcmp(command, "MergeMinHeaps") == 0) return 6;
    if (strcmp(command, "DeleteHeap") == 0) return 7;
    return 8;
}