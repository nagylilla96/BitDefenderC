//
// Created by lilla on 20/01/17.
//

#include "hashtester.h"
#include "HashTable.h"

ELEMENT *createElement(int key,int  value){

    ELEMENT *element = calloc(1, sizeof(ELEMENT));
    element->key = key;
    element->value = value;
    return element;
}

int hashFunction(void *key, int size) {
    return ((int)key*23455 % size);
}
int cmpFunct(void *a, void *b) {
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

void printElement(void *a, FILE *f) {
    ELEMENT *element = (ELEMENT*) a;
    fprintf(f, "key: %d\n", element->key);
    fprintf(f, "value: %d\n", element->value);
}

void deleteFunct(void *a) {
    return;
}

void *getKey(HASHTABLE *hashtable, void *a) {
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

void *getValue(HASHTABLE *hashtable, void *a){
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

    int size = 50;
    int key, value;
    HASHTABLE **arrayOfTables = calloc(26, sizeof(HASHTABLE*));
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
                case 0://creates a list to the arrayOfArrays starting from A to Z, depending on the set's name
                    token = strtok(NULL, " ");
                    token[strlen(token) - 1] = '\0';
                    if(arrayOfTables[(int) *token - 65] != NULL){
                        printf("WHat the fuck\n");
                    }
                    if (token != NULL && strlen(token) == 1 && arrayOfTables[(int) *token - 65] == NULL) {
                        arrayOfTables[(int) *token - 65] = CreateHashTable(size, NULL);
                        if (arrayOfTables[(int) *token - 65] == NULL) {
                            printf("Create was not successful\n");
                        };
                    } else {
                        error(1, g, token);
                    }
                    break;
                case 1:
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
                case 2: //adds some items (elements number of items) to a certain vector (based on the set's name),
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
                case 3:
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
                case 4: // searches a vector item based on integer and real number
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
                case 5: // deletes a vector item based on its index (again, noted by elements) (I'm so sorry)
                    token = strtok(NULL, " ");
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
                case 6: // sorts the vector based on the given compare function
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