//
// Created by lilla on 19/01/17.
//

#include "HashTable.h"

int implicitHashFunction(void *key, int size) {
    return ((int) key % size);
}

HASHTABLE *CreateHashTable(int size, int(*hashFunction)(void *key, int size)) {
    int i;
    if (size < 1) {
        return NULL;
    }
    HASHTABLE *hashtable = calloc(1, sizeof(HASHTABLE));
    hashtable->size = size;
    hashtable->hashTable = calloc(size, sizeof(HASHNODE*));
    for (i = 0; i < size; i++){
        hashtable->hashTable[i] = NULL;
    }
    if (hashFunction == NULL) {
        hashtable->hashFunction = implicitHashFunction;
    }
    else
    {
        hashtable->hashFunction = hashFunction;
    }
    hashtable->nrOfElements = 0;
    return hashtable;
}

HASHNODE *CreateHashNode(void* element) {
    HASHNODE *node = calloc(1, sizeof(HASHNODE));
    node->element = element;
    node->next = NULL;
    node->linkedList = NULL;
    return node;
}

int isPrime(int number) {
    int i;
    if (number < 2) {
        return 0;
    }
    for (i = 2; i <= sqrt(number); i++){
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int findPrime(int size) {
    size *= 2;
    while (!isPrime(size)){
        size++;
    }
    return size;
}

void redimensionTable(HASHTABLE *hashtable) {
//    printf("\n");
    int i;
    HASHNODE **newHashTable =  calloc(findPrime(hashtable->size), sizeof(HASHNODE*));
    HASHNODE *last = NULL;
    for (i = 0; i < hashtable->size; i++) {
        if (hashtable->hashTable[i]!= NULL) {
            last = hashtable->hashTable[i];
            newHashTable[i] = last;
//            if (last->next != NULL) {
//                newHashTable[i]->next = last->next;
//            }
            while (last->next != NULL) {
                last = last->next;
                newHashTable[i]->next = last;
            }
        }
    }
    hashtable->hashTable = newHashTable;
    hashtable->size = findPrime(hashtable->size);
//    free(newHashTable);
}

void PrintHashTable(HASHTABLE *hashtable, void(*printElement)(void* a)) {
    int i;
    HASHNODE *last = NULL;
    for (i = 0; i < hashtable->size; i++) {
        if (hashtable->hashTable[i] != NULL) {
            if (hashtable->hashTable[i]->element != NULL) {
                printElement(hashtable->hashTable[i]->element);
                printf("\n");
                last = hashtable->hashTable[i];
                if (last == NULL) {
                    printf("last is null\n");
                }
                while (last->next != NULL) {
                    last = last->next;
                    printf("\t");
                    printElement(last->element);

                }
            }
        }
    }
}


int AddHashTableItem(HASHTABLE *hashtable, void *key, void *value, void*(*createElement)(void *, void *), int (*cmpFunct)(void *a, void *b), void (*printFunct) (void *a)){
    int index = hashtable->hashFunction(key, hashtable->size);
    int factor = ((hashtable->size * 3) / 4);
    void *element = createElement(key, value);
    if (element == NULL) {
        printf("Element is null\n");
    }
    HASHNODE* node = CreateHashNode(element);
    HASHNODE *last = NULL;
    if (hashtable->nrOfElements >= factor ){
        redimensionTable(hashtable);
//        PrintHashTable(hashtable, printFunct);
    }
    if (hashtable->hashTable == NULL) {
        printf("hashtable is null\n");
    }
    if (hashtable->hashTable[index] == NULL) {
        hashtable->hashTable[index] = calloc(1,sizeof(HASHNODE));
        if (hashtable->hashTable[index]->element == NULL ) {
            hashtable->hashTable[index] = node;
            hashtable->nrOfElements++;
            return 1;
        }

    }
    LIST *list = CreateLinkedList();
    hashtable->hashTable[index]->linkedList = list;
    if (list == NULL) {
        printf("list is null\n");
    }
    last = hashtable->hashTable[index];
    if (!AddLinkedListItem(list, node->element)) {
        printf("Element could not be added to linked list\n");
        return 0;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = (HASHNODE*) SearchLinkedListItem(list, node->element, cmpFunct);
    hashtable->nrOfElements++;
    return 1;
}

int SearchHashTableItem(HASHTABLE *hashtable, void *key, void *value, void*(*createElement)(void *key, void *value), int (*cmpFunct)(void *a, void *b)) {
    int i;
    HASHNODE *searchedNode = CreateHashNode(createElement(key, value));
    HASHNODE *last = NULL;
    for (i = 0; i < hashtable->size; i++) {
        if (hashtable->hashTable[i] != NULL) {
            if (hashtable->hashTable[i]->element != NULL) {
                last = hashtable->hashTable[i];
                if (cmpFunct(last->element, searchedNode->element) == 0 ) {
                    return 1;
                }
                while (last->next != NULL) {
                    last = last->next;
                    if (cmpFunct(last->element, searchedNode) == 0 ) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int DeleteHashTableItem(HASHTABLE *hashtable, void *key, void *value, void*(*createElement)(void *key, void *value), int (*cmpFunct)(void *a, void *b)) {
    int i;
    HASHNODE *searchedNode = CreateHashNode(createElement(key, value));
    HASHNODE *last = NULL;
    HASHNODE *previous = NULL;
    for (i = 0; i < hashtable->size; i++) {
        if (hashtable->hashTable[i] != NULL) {
            if (hashtable->hashTable[i]->element != NULL) {
                last = hashtable->hashTable[i];
                if (cmpFunct(last->element, searchedNode->element) == 0 ) {
                    last->element = last->next->element;
                    last->next = last->next->next;
                    return 1;
                }
                while (last->next != NULL) {

                    previous = last;
                    last = last->next;

                    if (cmpFunct(last->element, searchedNode->element) == 0 ) {
                        previous->next = last->next;
                        last->next = NULL;
                        return 1;
                    }
                }
            }
        }
    }
    free(searchedNode);
    return 0;
}

void DeleteHashTable(HASHTABLE *hashtable, void(*deleteFunct)(void *a)) {
    int i;
    for (i = 0; i < hashtable->size; i++) {
        if (hashtable->hashTable[i] != NULL) {
            if (hashtable->hashTable[i]->linkedList != NULL) {
                DeleteLinkedList(hashtable->hashTable[i]->linkedList);

            }
            deleteFunct(hashtable->hashTable[i]->element);
            free(hashtable->hashTable[i]);
        }
    }
    free(hashtable->hashTable);
    free(hashtable);
    hashtable->hashTable = NULL;
}



