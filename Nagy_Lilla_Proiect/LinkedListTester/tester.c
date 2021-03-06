//
// Created by lilla on 16/01/17.
//

#include <LinkedList.h>
#include "tester.h"

//DISCLAIMER: I have no idea why it doesn't work, all the testers have the same structure and all of them work
//with multiple files, except this one. This one only works with one input file. It's a special tester :)

void printFunct(void *a, FILE *f) { // a function that prints a structure
    ELEMENT *aa = (ELEMENT*) a;
    fprintf(f, "index = %d\n", aa->integer);
    fprintf(f, "index = %f\n", aa->real);
}

ELEMENT *createElement(int integer, float real) { // a function that creates and returns a new element
    ELEMENT *element = malloc(sizeof(ELEMENT*));
    element->integer = integer;
    element->real = real;
    return element;
}

int cmpFunct(void *a, void *b) { // compares two structures
    ELEMENT *aa = (ELEMENT*) a;
    ELEMENT *bb = (ELEMENT*) b;
    if (aa->integer > bb->integer) {
        return 1;
    }
    else {
        if (aa->integer == bb->integer) {
            if (aa->real > bb->real) {
                return 1;
            }
            else {
                if (aa->real == bb->real) {
                    return 0;
                }
                return -1;
            }
        }
        else {
            return -1;
        }
    }
}

void swap(void *a, void *b){ // swaps two structures
    NODE *aa = (NODE*) a;
    NODE *bb = (NODE*) b;
    ELEMENT *temp;
    temp = aa->element;
    aa->element = bb->element;
    bb->element = temp;
}

void runTester(char *nameIN, char *nameOut) { //run the tester
    LIST **arrayOfLists = calloc(26, sizeof(LIST*)); // create an array of lists
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
    int value1;
    float value2;
    char *instruction = calloc(100, sizeof(char));
    char *token, *token1;
    while (fgets(instruction, 100, f) != NULL) {
        printf("%s", instruction);
        token = strtok(instruction, " ");
        if (token != NULL) {
            switch (commandNr(token)) {
                case 0://creates a list to the arrayOfLists starting from A to Z, depending on the set's name
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if(arrayOfLists[(int) *token - 65] != NULL){
                        printf("WHat the fuck\n");
                    }
                    if (token != NULL && strlen(token) == 1 && arrayOfLists[(int) *token - 65] == NULL) {
                        arrayOfLists[(int) *token - 65] = CreateLinkedList();
                        if (arrayOfLists[(int) *token - 65] == NULL) {
                            printf("Create was not successful\n");
                        };
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 1: //adds an item to the linked list
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        fscanf(f, "%d;%f", &value1, &value2);
                        ELEMENT *element = createElement(value1, value2);
                        AddLinkedListItem(arrayOfLists[index], element);
                        error(10, g, token);
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 2:// puts an item to the list to an index (elements)
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        fscanf(f, "%d", &elements);
                        fscanf(f, "%d;%f", &value1, &value2);
                        ELEMENT *element = createElement(value1, value2);
                        if (elements >= 0) {
                            PutLinkedListItem(arrayOfLists[index], element, elements);
                        } else {
                            error(4, g, token);
                        }
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 3: // gets a list item with a certain index (again using the variable elements)
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        fscanf(f, "%d", &elements);
                        if (elements >= 0) {
                            if (elements < arrayOfLists[index]->nrOfElements) {
                                GetLinkedListItem(arrayOfLists[index], elements);
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
                case 4: // searches a vector item based on integer and real number
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        fscanf(f, "%d;%f", &value1, &value2);
                        ELEMENT *element = createElement(value1, value2);
                        NODE *node = SearchLinkedListItem(arrayOfLists[index], element, cmpFunct);
                        if (node == NULL) {
                            error(3, g, token);
                        }
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 5: // deletes a vector item based on its index (again, noted by elements) (I'm so sorry)
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        fscanf(f, "%d", &elements);
                        if (elements >= 0) {
                            DeleteLinkedListItem(arrayOfLists[index], elements);
                        }
                        else {
                            error(4, g, token);
                        }
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 6: // sorts the vector based on the given compare function
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        SortLinkedList(arrayOfLists[index], cmpFunct, swap);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 7: // merge two lists into a third one
                    token = strtok(NULL, " ");
                    token1 = strtok(NULL, " ");
                    token1[strlen(token1) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1
                        && token1 != NULL && strlen(token1) == 1){
                        index = (int) *token - 65;
                        int index1 = (int) *token1 - 65;
                        int index2 = index1 + 1;
                        while (arrayOfLists[index2] != NULL) {
                            index2++;
                        }
                        arrayOfLists[index2] = CreateLinkedList();
                        arrayOfLists[index2] = MergeLinkedLists(arrayOfLists[index], arrayOfLists[index1], cmpFunct, swap);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 8: // deletes a list completely
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1 && arrayOfLists[(int) *token - 65] != NULL){
                        index = (int) *token - 65;
                        DeleteLinkedList(arrayOfLists[index]);
                    }
                    else {
                        error(1, g, token);
                    }
                    arrayOfLists[index] = NULL;
                    break;
                case 9: // prints a list
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        if (arrayOfLists[index]->first == NULL ) {
                            printf("array pointer is null!\n");
                            break;
                        }
                        PrintLinkedList(arrayOfLists[index], printFunct, g);
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
    free(arrayOfLists);
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
    if (strcmp(command, "CreateLinkedList") == 0) return 0;//
    if (strcmp(command, "AddLinkedListItem") == 0) return 1;//
    if (strcmp(command, "PutLinkedListItem") == 0) return 2;//
    if (strcmp(command, "GetLinkedListItem") == 0) return 3;//
    if (strcmp(command, "SearchLinkedListItem") == 0) return 4;//
    if (strcmp(command, "DeleteLinkedListItem") == 0) return 5;//
    if (strcmp(command, "SortLinkedList") == 0) return 6;//
    if (strcmp(command, "MergeLinkedLists") == 0) return 7;//
    if (strcmp(command, "DeleteLinkedList") == 0) return 8;
    if (strcmp(command, "PrintLinkedList") == 0) return 9;
    return 10;
}
