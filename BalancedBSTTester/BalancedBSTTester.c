//
// Created by lilla on 22/01/17.
//

#include "BalancedBSTTester.h"

int cmpFunct(void *a, void *b) {
    ELEMENT *aa = (ELEMENT*) a;
    ELEMENT *bb = (ELEMENT*) b;
    if (aa->data > bb->data) {
        return 1;
    }
    else {
        if (aa->data == bb->data) {
            return 0;
        }
        else {
            return -1;
        }
    }
}

void printData(void *a, FILE *f) {
    ELEMENT *node = (ELEMENT*) a;
    fprintf(f, "%d", node->data);
}


void runTester(char *nameIN, char *nameOut) { //run the tester

    int size = 50;
    BalancedTree **arrayOfTrees = calloc(26, sizeof(BalancedTree*));
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
    ELEMENT **element = calloc(100, sizeof(ELEMENT*));
    for (int i = 0; i < 100; i++) {
        element[i]  = calloc(1, sizeof(ELEMENT));
    }
    int elementIndex = 0;
    while (fgets(instruction, 100, f) != NULL) {
        printf("%s", instruction);
        token = strtok(instruction, " ");
        if (token != NULL) {
            switch (commandNr(token)) {
                case 0://creates a list to the arrayOfArrays starting from A to Z, depending on the set's name
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if(arrayOfTrees[(int) *token - 65] != NULL){
                        printf("WHat the fuck\n");
                    }
                    if (token != NULL && strlen(token) == 1 && arrayOfTrees[(int) *token - 65] == NULL) {
                        arrayOfTrees[(int) *token - 65] = CreateBalancedBST();
                        if (arrayOfTrees[(int) *token - 65] == NULL) {
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
                        if (arrayOfTrees[index]->root == NULL ) {
                            fprintf(g, "Tree is empty\n");
                            break;
                        }
                        fprintf(g,"\n..........\n");
                        PrintBalancedBST(arrayOfTrees[index]->root, 0, printData, g);
                        fprintf(g,"\n..........\n");
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 2: // prints a vector
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        if (arrayOfTrees[index]->root == NULL ) {
                            fprintf(g, "Tree is empty!\n");
                            break;
                        }
                        fprintf(g, "\n");
                        PreorderBalancedBST(arrayOfTrees[index]->root, printData, g);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 3: // prints a vector
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        if (arrayOfTrees[index]->root == NULL ) {
                            fprintf(g, "Tree is empty!\n");
                            break;
                        }
                        fprintf(g, "\n");
                        InorderBalancedBST(arrayOfTrees[index]->root, printData, g);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 4: // prints a vector
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        if (arrayOfTrees[index]->root == NULL ) {
                            fprintf(g, "Tree is empty!\n");
                            break;
                        }
                        fprintf(g, "\n");
                        PostorderBalancedBST(arrayOfTrees[index]->root, printData, g);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 5: //adds some items (elements number of items) to a certain vector (based on the set's name),
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        fscanf(f, "%d", &elements);
                        element[elementIndex]->data = elements;
                        printf("Element %d\n", element[elementIndex]->data);
                        arrayOfTrees[index]->root = AddBalancedBSTItem(arrayOfTrees[index]->root, element[elementIndex], cmpFunct);
                        elementIndex++;
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 6: // gets a vector item with a certain index (again using the variable elements)
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        fscanf(f, "%d", &element[elementIndex]->data);
                        if (SearchBalancedBSTItem(arrayOfTrees[index]->root, element[elementIndex], cmpFunct) == NULL) {
                            fprintf(g, "\nElement %d not found!\n", element[elementIndex]->data);
                        }
                        else {
                            fprintf(g, "\nElement %d found!\n", element[elementIndex]->data);
                        }
                        elementIndex++;
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 7: // deletes a vector item based on its index (again, noted by elements) (I'm so sorry)
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        fscanf(f, "%d", &element[elementIndex]->data);
                        if (SearchBalancedBSTItem(arrayOfTrees[index]->root, element[elementIndex], cmpFunct) != NULL){
                            arrayOfTrees[index]->root = DeleteBalancedBSTItem(arrayOfTrees[index]->root, element[elementIndex], cmpFunct);
                        }
                        else{
                            printf("\nElement %d not found!\n", element[elementIndex]->data);
                        }
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 8: // creates a new arraylist, which will get the value returned by the merge function
                    token = strtok(NULL, " ");
                    token1 = strtok(NULL, " ");
                    token1[strlen(token1) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1
                        && token1 != NULL && strlen(token1) == 1){
                        index = (int) *token - 65;
                        int index1 = (int) *token1 - 65;
                        int index2 = index1 + 1;
                        while (arrayOfTrees[index2] != NULL) {
                            index2++;
                        }
                        arrayOfTrees[index2] = CreateBalancedBST();
                        arrayOfTrees[index2]->root = MergeBalancedBSTs(arrayOfTrees[index]->root, arrayOfTrees[index1]->root, cmpFunct);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 9: // sorts the vector based on the given compare function
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        fprintf(g, "\nHeight of the tree: %d\n", HeightBalancedBST(arrayOfTrees[index]->root));
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 10: // deletes a vector completely
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1 && arrayOfTrees[(int) *token - 65] != NULL){
                        index = (int) *token - 65;
                        DeleteBalancedBST(arrayOfTrees[index], cmpFunct);
                    }
                    else {
                        error(1, g, token);
                    }
                    arrayOfTrees[index] = NULL;
                    break;
                default:
                    break;
            }
        }
    }
    fclose(f);
    fclose(g);
    free(arrayOfTrees);
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
    if (strcmp(command, "CreateBalancedBST") == 0) return 0;
    if (strcmp(command, "PrintBalancedBST") == 0) return 1;
    if (strcmp(command, "PreorderBalancedBST") == 0) return 2;
    if (strcmp(command, "InorderBalancedBST") == 0) return 3;
    if (strcmp(command, "PostorderBalancedBST") == 0) return 4;
    if (strcmp(command, "AddBalancedBSTItem") == 0) return 5;
    if (strcmp(command, "SearchBalancedBSTItem") == 0) return 6;
    if (strcmp(command, "DeleteBalancedBSTItem") == 0) return 7;
    if (strcmp(command, "MergeBalancedBSTs") == 0) return 8;
    if (strcmp(command, "HeightBalancedBST") == 0) return 9;
    if (strcmp(command, "DeleteBalancedBST") == 0) return 10;
    return 11;
}