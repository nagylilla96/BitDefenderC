#include "HashTable.h"

typedef struct {
    int key;
    char *value;
}ELEMENT;

ELEMENT *createElement(int key, char* value){ // allocate space for an element, initialize and return it
    ELEMENT *element = calloc(1, sizeof(ELEMENT));
    element->key = key;
    element->value = calloc(100, sizeof(char));
    strcpy(element->value, value);
    return element;
}

int hashFunction(void *key, int size) { //hash function (for a certain key returns an index based on table's size)
    return ((int)key*23455 % size);
}

int cmpFunct(void *a, void *b) { // compares two structures
    ELEMENT *aa = (ELEMENT*) a;
    ELEMENT *bb = (ELEMENT*) b;
    if (aa->key > bb->key) {
        return 1;
    }
    else {
        if (aa->key == bb->key) {
            if (strcmp(aa->value, bb->value) > 0) {
                return 1;
            }
            else {
                if (strcmp(aa->value, bb->value) == 0) {
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

void printElement(void *a, FILE *f) { // prints one structure's data
    ELEMENT *element = (ELEMENT*) a;
    fprintf(f, "key: %d\n", element->key);
    fprintf(f, "value: %s\n", element->value);
}

void deleteFunct(void *a) { // frees an element
    ELEMENT *element = (ELEMENT* ) a;
    free(element->value);
}

void *getKey(HASHTABLE *hashtable, void *a) { // gets the key of an element
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

void *getValue(HASHTABLE *hashtable, void *a){ // gets the calue of an element
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

int main() {
    HASHTABLE *hashtable = CreateHashTable(2, NULL);
    HASHTABLE *newHashTable;
    AddHashTableItem(hashtable, 1, "Lilla", createElement, cmpFunct);
    AddHashTableItem(hashtable, 1, "Balint", createElement, cmpFunct);
    AddHashTableItem(hashtable, 1, "David", createElement, cmpFunct);
    printf("%d\n", SearchHashTableItem(hashtable, 1, "Lilla",createElement,cmpFunct));
    printf("%d\n", SearchHashTableItem(hashtable, 1, "Balint",createElement,cmpFunct));
    printf("%d\n", SearchHashTableItem(hashtable, 2, "Lilla",createElement,cmpFunct));
    DeleteHashTableItem(hashtable, 1, "Lilla", createElement, cmpFunct);
    PrintHashTable(hashtable, printElement, stdout);
    newHashTable = RehashTable(hashtable, hashFunction, getKey, getValue, createElement, cmpFunct, printElement, deleteFunct);
    PrintHashTable(newHashTable, printElement, stdout);
    DeleteHashTable(newHashTable, deleteFunct);

    return 0;
}