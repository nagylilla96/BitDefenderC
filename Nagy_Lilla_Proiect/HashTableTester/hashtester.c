//
// Created by lilla on 20/01/17.
//

#include "hashtester.h"
#include "HashTable.h"

ELEMENT *createElement(int key,int  value){ //create a new element and return it
    ELEMENT *element = calloc(1, sizeof(ELEMENT));
    element->key = key;
    element->value = value;
    return element;
}

int hashFunction(void *key, int size) { // a hash function
    return ((int)key*23455 % size);
}
int cmpFunct(void *a, void *b) { //compares two structures
    ELEMENT *aa = (ELEMENT*) a;
    ELEMENT *bb = (ELEMENT*) b;
    if (aa->key > bb->key) {
        return 1;
    }
    else {
        if (aa->key == bb->key) {
            if (aa->value > bb->value) {
                return 1;
            }
            else {
                if (aa->value == bb->value) {
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

void printElement(void *a, FILE *f) { // prints a structure
    ELEMENT *element = (ELEMENT*) a;
    fprintf(f, "key: %d\n", element->key);
    fprintf(f, "value: %d\n", element->value);
}

void deleteFunct(void *a) { //delete function doesn't have to free anything
    return;
}

void *getKey(HASHTABLE *hashtable, void *a) { // get the key of a structure
    int i;
    ELEMENT *element = (ELEMENT *) a;
    HASHNODE *last = NULL;
    for (i = 0; i < hashtable->size; i++) {
        if (hashtable->hashTable[i] != NULL) {
            if (hashtable->hashTable[i]->element != NULL) {
                last = hashtable->hashTable[i];
                if (cmpFunct(last->element, element) == 0) {
                    element = last->element;
                    return element->key;
                }
                while (last->next != NULL) {
                    last = last->next;
                    if (cmpFunct(last->element, element) == 0) {
                        element = last->element;
                        return element->key;
                    }
                }
            }
        }
    }
    return 0;
}

void *getValue(HASHTABLE *hashtable, void *a){ // get the value of a structure
    int i;
    ELEMENT *element = (ELEMENT *) a;
    HASHNODE *last = NULL;
    for (i = 0; i < hashtable->size; i++) {
        if (hashtable->hashTable[i] != NULL) {
            if (hashtable->hashTable[i]->element != NULL) {
                last = hashtable->hashTable[i];
                if (cmpFunct(last->element, element) == 0) {
                    element = last->element;
                    return element->value;
                }
                while (last->next != NULL) {
                    last = last->next;
                    if (cmpFunct(last->element, element) == 0) {
                        element = last->element;
                        return element->value;
                    }
                }
            }
        }
    }
    return NULL;
}


void runTester(char *nameIN, char *nameOut) { //run the tester
    int size = 50; // initial size of the hashtable
    int key, value;
    HASHTABLE **arrayOfTables = calloc(26, sizeof(HASHTABLE*)); // alocate space for an array of hashtables
    printf("RunTester\n");
    int index = 0, elements;
    FILE *f = fopen(nameIN, "r");
    FILE *g = fopen(nameOut, "w");
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
                case 0://creates a list to the arrayOfTables starting from A to Z, depending on the set's name
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1 && arrayOfTables[(int) *token - 65] == NULL) {
                        arrayOfTables[(int) *token - 65] = CreateHashTable(size, NULL);
                        if (arrayOfTables[(int) *token - 65] == NULL) {
                            printf("Create was not successful\n");
                        };
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 1: // prints the hashtable's elements
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        if (arrayOfTables[index]->hashTable == NULL ) {
                            printf("hashtable pointer is null!\n");
                            break;
                        }
                        PrintHashTable(arrayOfTables[index], printElement, g);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 2: //adds a key-value pair to the hashtable
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        fscanf(f, "%d;%d", &key, &value);
                        AddHashTableItem(arrayOfTables[index], key, value, createElement, cmpFunct);

                    } else {
                        error(1, g, token);
                    }
                    break;
                case 3: //delete a key-value pair from the hashtable
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1){
                        index = (int) *token - 65;
                        fscanf(f, "%d;%d", &key, &value);
                        if (elements >= 0) {
                            DeleteHashTableItem(arrayOfTables[index], key, value, createElement, cmpFunct);
                        }
                        else {
                            error(4, g, token);
                        }
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 4: // searches for a key-value pair
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1) {
                        index = (int) *token - 65;
                        fscanf(f, "%d;%d", &key, &value);
                        int returned = SearchHashTableItem(arrayOfTables[index], key, value, createElement, cmpFunct);
                        if (returned == 0) {
                            error(3, g, token);
                        } else {
                            printf("Element %d;%d found\n", key, value);
                        }
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 5: // rehashes the table using a different hashfunction (we don't give it as a parameter
                    token = strtok(NULL, " "); // because we're not that smart)
                    token1 = strtok(NULL, " ");
                    token1[strlen(token1) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1
                        && token1 != NULL && strlen(token1) == 1){
                        index = (int) *token - 65;
                        int index1 = (int) *token1 - 65;
                        arrayOfTables[index1] = RehashTable(arrayOfTables[index], hashFunction, getKey, getValue,
                                                            createElement, cmpFunct, printElement, deleteFunct);
                    }
                    else {
                        error(1, g, token);
                    }
                    break;
                case 6: // deletes hashtable completely
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if (token != NULL && strlen(token) == 1 && arrayOfTables[(int) *token - 65] != NULL){
                        index = (int) *token - 65;
                        DeleteHashTable(arrayOfTables[index], deleteFunct);
                    }
                    else {
                        error(1, g, token);
                    }
                    arrayOfTables[index] = NULL;
                    break;
                default:
                    break;
            }
        }
    }
    fclose(f);
    fclose(g);
    free(arrayOfTables);
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
    if (strcmp(command, "CreateHashTable") == 0) return 0;
    if (strcmp(command, "PrintHashTable") == 0) return 1;
    if (strcmp(command, "AddHashTableItem") == 0) return 2;
    if (strcmp(command, "DeleteHashTableItem") == 0) return 3;
    if (strcmp(command, "SearchHashTableItem") == 0) return 4;
    if (strcmp(command, "ReHashTable") == 0) return 5;
    if (strcmp(command, "DeleteHashTable") == 0) return 6;
    return 7;
}