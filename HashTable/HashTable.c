//
// Created by lilla on 19/01/17.
//

#include "HashTable.h"
#include "LinkedList.h"

int implicitHashFunction(void *key, int size) {
    return ((int) key % size);
}

HASHTABLE *CreateHashTable(int size, int(*hashFunction)(void *key, int size)) {
    int i;
    if (size < 1) {
        return NULL;
    }
    HASHTABLE *hashtable = calloc(1, sizeof(HASHTABLE));
    hashtable->hashTable = calloc(size, sizeof(HASHTABLE*));
    for (i = 0; i < size; i++){
        hashtable->hashTable[i] = NULL;
    }
    hashtable->size = size;
    if (hashFunction == NULL) {
        hashtable->hashFunction = implicitHashFunction;
    }
    else
    {
        hashtable->hashFunction = hashFunction;
    }
    return hashtable;
}

NODE *CreateNode(void* element) {
    NODE *node = calloc(1, sizeof(NODE));
    node->element = element;
    node->next = NULL;
    return node;
}

int isPrime(int number) {
    int i;
    if (number < 2) {
        return 0;
    }
    for (i = 2; i < sqrt(number); i++){
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int findPrime(int size) {
    while (!isPrime(size)){
        size++;
    }
    return size;
}

HASHTABLE *redimensionTable(HASHTABLE *hashtable) {
}

int AddHashTableItem(HASHTABLE *hashtable, void *key, void *value, void*(*createElement)(void *, void *), int cmpFunct(void *a, void *b)){
    int index = hashtable->hashFunction(key, hashtable->size);
    NODE* node = CreateNode(createElement(key, value));
    NODE *last = NULL;
    if (hashtable->nrOfElements >= (float) (hashtable->size * 3) / 4) {
        //TODO resize table
    }
    if (hashtable->hashTable[index] == NULL) {
        hashtable->hashTable[index] = node;
        return 1;
    }
    LIST *list = CreateLinkedList();
    last = hashtable->hashTable[index];
    if (!AddLinkedListItem(list, node)) {
        printf("Element could not be added to linked list\n");
        return 0;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = SearchLinkedListItem(list, node, cmpFunct);
    return 1;
}




