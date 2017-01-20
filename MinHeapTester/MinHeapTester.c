//
// Created by lilla on 20/01/17.
//

#include <MinHeap.h>
#include "MinHeapTester.h"

void *createNode(int number) {
    ELEMENT *myNode = (ELEMENT*) malloc(sizeof(ELEMENT));
    myNode->number = number;
    return myNode;
}

void *getNode(int i, FILE *f) {
    int number;
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

void runTester(char *nameIN, char *nameOut) { //run the tester

    int size = 50;
    MINHEAP **arrayOfArrays = calloc(26, sizeof(MINHEAP*));
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
                case 0://creates a list to the arrayOfArrays starting from A to Z, depending on the set's name
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if(arrayOfArrays[(int) *token - 65] != NULL){
                        printf("WHat the fuck\n");
                    }
                    if (token != NULL && strlen(token) == 1 && arrayOfArrays[(int) *token - 65] == NULL) {
                        arrayOfArrays[(int) *token - 65] = CreateHeap(size);
                        if (arrayOfArrays[(int) *token - 65] == NULL) {
                            printf("Create was not successful\n");
                        };
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 1: // prints a vector
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        if (arrayOfArrays[index]->vector == NULL ) {
                            printf("array pointer is null!\n");
                            break;
                        }
                        PrettyPrint(arrayOfArrays[index], 0, 0, anotherPrintFunc, g);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 2:// puts an item to the arrayvector based on the given index (which is called elements because
                    token = strtok(NULL, " "); // I didn't want to declare a new variable
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        if (!AddHeapItem(arrayOfArrays[index], getNode, f, cmpFunct)){
                            error(3, g, token);
                        }
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 3: // searches a vector item based on integer and real number
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        ELEMENT *returned = GetHeapMin(arrayOfArrays[index]);
                        fprintf(g, "The smallest element is: %d\n", returned->number);
                        if (returned->number == NULL) {
                            error(3, g, token);
                        }
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 4: // deletes a vector item based on its index (again, noted by elements) (I'm so sorry)
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        DeleteHeapMin(arrayOfArrays[index], freeNode, cmpFunct);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 5: // sorts the vector based on the given compare function
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        HEAPNODE *node = getNode(0, f);
                        if (node == NULL){
                            printf("Node is null\n");
                        }
                        DeleteHeapItem(arrayOfArrays[index], node, freeNode, cmpFunct, printFunc, g);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 6: // creates a new arraylist, which will get the value returned by the merge function
                    token = strtok(NULL, " ");
                    token1 = strtok(NULL, " ");
                    token1[strlen(token1) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1
                        && token1 != NULL && strlen(token1) == 1){
                        index = (int) *token - 65;
                        int index1 = (int) *token1 - 65;
                        int index2 = index1 + 1;
                        while (arrayOfArrays[index2] != NULL) {
                            index2++;
                        }
                        arrayOfArrays[index2] = MergeMinHeaps(arrayOfArrays[index], arrayOfArrays[index1], cmpFunct);
                        if (arrayOfArrays[index2] == NULL) {
                            printf("Array is null\n");
                        }
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 7: // deletes a vector completely
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1      && arrayOfArrays[(int) *token - 65] != NULL){
                        index = (int) *token - 65;
                        DeleteHeap(arrayOfArrays[index], freeNode);
                    }
                    else {
                        error(1, g, token);
                    }
                    arrayOfArrays[index] = NULL;
                    break;
                default:
                    break;
            }
        }
    }
    fclose(f);
    fclose(g);
    free(arrayOfArrays);
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