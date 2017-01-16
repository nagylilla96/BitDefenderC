//
// Created by lilla on 14/01/17.
//

#include <Vector.h>
#include "tester.h"

MyNode *getNode(int i, FILE *f) {
    int integer;
    float real;
    MyNode *node = malloc(sizeof(MyNode));
    fscanf(f, "%d;%f", &integer, &real);
    node->integer = integer;
    node->real = real;
    return node;
}

void printFunc(first* one, int index, FILE *f) {
    fprintf(f, "index = %d\n", index);
    MyNode **vector = (MyNode**) one->pointer;
    fprintf(f, "integer = %d\n", vector[index]->integer);
    fprintf(f, "real = %f\n", vector[index]->real);
    fprintf(f, "\n");
}

void printAllFunc(first* one, FILE *f) {
    int i;
    MyNode **node = (MyNode **) one->pointer;
    for (i = 0; i < one->nrOfElements; i++) {
        if (one->pointer == NULL) {
            fprintf(f, "Double pointer is null\n");
        }
        printFunc(one, i, f);
    }
}

void freeFunct(void *a) {
    return;
}

int cmpFunct(void *a, void *b) {
    MyNode *aa = (MyNode *) a;
    MyNode *bb = (MyNode *) b;
    if (aa->integer > bb->integer) {
        return 1;
    }
    else {
        if (aa->integer ==  bb->integer) {
            if (aa->real > bb->real) {
                return 1;
            }
            else {
                if (aa->real == bb->real) {
                    return 0;
                }
                else {
                    return -1;
                }
            }
        }
        else {
            return -1;
        }
    }
}

void freeNode(void *a){
    return;
}


void runTester(char *nameIN, char *nameOut) {

    size = 50;
    first **arrayOfArrays = malloc(sizeof(first*) * 26);
    printf("RunTester\n");
    int index = 0, elements, value1, value2, i;
    FILE *f = fopen(nameIN, "r");
    FILE *h = fopen(nameIN, "r");
    FILE *g = fopen(nameOut, "w");
    char *instruction;
    char *token, *token1;
    while (fgets(instruction, 100, f) != NULL) {
        printf("%s", instruction);
        token = strtok(instruction, " ");
        if (token != NULL) {
            switch (commandNr(token)) {
                case 0:
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1 && arrayOfArrays[(int) *token - 65] == NULL) {
                        arrayOfArrays[(int) *token - 65] = CreateVector(size);
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 1:
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        fscanf(f, "%d", &elements);
                        if (elements > 0) {
                            AddVectorItems(elements, arrayOfArrays[index], &size, getNode, f);
                        } else {
                            error(10, g, token);
                        }
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 2:
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        fscanf(f, "%d", &elements);
                        if (elements >= 0) {
                            PutVectorItem(elements, arrayOfArrays[index], &size, getNode(0, f));
                        } else {
                            error(4, g, token);
                        }
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 3:
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        fscanf(f, "%d", &elements);
                        if (elements >= 0) {
                            if (elements < arrayOfArrays[index]->nrOfElements) {
                                GetVectorItem(elements, arrayOfArrays[index], printFunc, g);
                            }
                            else {
                                error(7, g, token);
                            }
                        } else {
                            error(4, g, token);
                        }
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 4:
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        int returned = SearchVectorItem(arrayOfArrays[index], getNode(0, f), cmpFunct, printFunc, g);
                        if (returned == 0) {
                            error(3, g, token);
                        } else {
                            error(4, g, token);
                        }
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 5:
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        fscanf(f, "%d", &elements);
                        if (elements >= 0) {
                            DeleteVectorItem(arrayOfArrays[index], elements, freeNode);
                        }
                        else {
                            error(4, g, token);
                        }
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 6:
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                            SortVector(arrayOfArrays[index], cmpFunct);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 7:
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
                        arrayOfArrays[index2] = CreateVector(size * 2);
                        arrayOfArrays[index2] = MergeVectors(arrayOfArrays[index], arrayOfArrays[index1], arrayOfArrays[index2], cmpFunct);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 8:
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1 && arrayOfArrays[(int) *token - 65] != NULL){
                        index = (int) *token - 65;
                        DeleteVector(arrayOfArrays[index], size, freeFunct);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 9:
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        PrintVector(arrayOfArrays[index], printAllFunc, g);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                default:
                    break;
            }
        }
    }
    fclose(f);
    fclose(g);
}

void error(int errorCode, FILE *f, char *command) {
    switch(errorCode) {
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

int commandNr(char *command) {
    if (strcmp(command, "CreateVector") == 0) return 0;
    if (strcmp(command, "AddVectorItems") == 0) return 1;
    if (strcmp(command, "PutVectorItem") == 0) return 2;
    if (strcmp(command, "GetVectorItem") == 0) return 3;
    if (strcmp(command, "SearchVectorItem") == 0) return 4;
    if (strcmp(command, "DeleteVectorItem") == 0) return 5;
    if (strcmp(command, "SortVector") == 0) return 6;
    if (strcmp(command, "MergeVectors") == 0) return 7;
    if (strcmp(command, "DeleteVector") == 0) return 8;
    if (strcmp(command, "PrintVector") == 0) return 9;
    return 10;
}