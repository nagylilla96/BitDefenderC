//
// Created by lilla on 19/01/17.
//

#include "HashTable.h"

//I used my LinkedList library for the hashtable, where every element of the array points to a linked list

int implicitHashFunction(void *key, int size) { // this is out implicit hash function that can be overwritten
    return ((int) key % size);
}

HASHTABLE *CreateHashTable(int size, int(*hashFunction)(void *key, int size)) { //create a hashtable
    int i;
    if (size < 1) {
        return NULL;
    }
    HASHTABLE *hashtable = calloc(1, sizeof(HASHTABLE)); //allocate space for it
    hashtable->size = size; // initialize it
    hashtable->hashTable = calloc(size, sizeof(HASHNODE*));
    for (i = 0; i < size; i++){
        hashtable->hashTable[i] = NULL;
    }
    if (hashFunction == NULL) { //add hashfunction to it (as a structure element)
        hashtable->hashFunction = implicitHashFunction;
    }
    else
    {
        hashtable->hashFunction = hashFunction;
    }
    hashtable->nrOfElements = 0;
    return hashtable; //finally, return it
}

HASHNODE *CreateHashNode(void* element) { // create a hashnode (allocate, initialize, return_)
    HASHNODE *node = calloc(1, sizeof(HASHNODE));
    node->element = element;
    node->next = NULL;
    node->linkedList = NULL;
    return node;
}

int isPrime(int number) { //check if a number is prime or not
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

int findPrime(int size) { // find the next prime for 2 * size
    size *= 2;
    while (!isPrime(size)){
        size++;
    }
    return size;
}

void redimensionTable(HASHTABLE *hashtable) { // redimension the hashtable to a size around two times bigger (also a prime)
    int i;
    HASHNODE **newHashTable =  calloc(findPrime(hashtable->size), sizeof(HASHNODE*));
    HASHNODE *last = NULL;
    for (i = 0; i < hashtable->size; i++) {
        if (hashtable->hashTable[i]!= NULL) {
            last = hashtable->hashTable[i];
            newHashTable[i] = last;
            while (last->next != NULL) {
                last = last->next;
                newHashTable[i]->next = last;
            }
        }
    }
    hashtable->hashTable = newHashTable;
    hashtable->size = findPrime(hashtable->size);
}

void PrintHashTable(HASHTABLE *hashtable, void(*printElement)(void* a, FILE *f), FILE *f) {
    int i; // print all elements of a hashtable
    HASHNODE *last = NULL;
    for (i = 0; i < hashtable->size; i++) {
        if (hashtable->hashTable[i] != NULL) {
            if (hashtable->hashTable[i]->element != NULL) {
                printElement(hashtable->hashTable[i]->element, f);
                fprintf(f, "\n");
                last = hashtable->hashTable[i];
                if (last == NULL) {
                    printf("last is null\n");
                }
                while (last->next != NULL) {
                    last = last->next;
                    fprintf(f, "\t");
                    printElement(last->element, f);

                }
            }
        }
    }
}


int AddHashTableItem(HASHTABLE *hashtable, void *key, void *value, void*(*createElement)(void *, void *),
                     int (*cmpFunct)(void *a, void *b)){
    int index = hashtable->hashFunction(key, hashtable->size); // add a new hashtable item
    int factor = ((hashtable->size * 3) / 4);
    void *element = createElement(key, value);
    if (element == NULL) {
        printf("Element is null\n");
    }
    HASHNODE* node = CreateHashNode(element);
    HASHNODE *last = NULL;
    if (hashtable->nrOfElements >= factor ){
        redimensionTable(hashtable);
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

int SearchHashTableItem(HASHTABLE *hashtable, void *key, void *value, void*(*createElement)(void *key, void *value),
                        int (*cmpFunct)(void *a, void *b)) {// search for a hashtable item
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

int DeleteHashTableItem(HASHTABLE *hashtable, void *key, void *value, void*(*createElement)(void *key, void *value),
                        int (*cmpFunct)(void *a, void *b)) { // delete a hashtable item
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

HASHTABLE *RehashTable(HASHTABLE *hashtable, int(*hashFunction)(void *key, void *value),
                       void*(*getKey)(HASHTABLE *hashtable, void *a), void*(getValue)(HASHTABLE *hashtable, void *a),
                       void*(*createElement)(void *, void *), int (*cmpFunct)(void *a, void *b), void (*printFunct) (void *a),
                       void(*deleteFunct)(void *a)) {
    //I will suppose it should have the same size
    //rehash the table into another one with a different hash function (and return it, of course)
    int i;
    if (hashFunction == NULL) {
        return NULL;
    }
    HASHTABLE *newHashTable = CreateHashTable(hashtable->size, hashFunction);
    HASHNODE *last = NULL;
    for (i = 0; i < hashtable->size; i++) {
        if (hashtable->hashTable[i]!= NULL) {
            last = hashtable->hashTable[i];
            AddHashTableItem(newHashTable, getKey(hashtable, last->element), getValue(hashtable, last->element), createElement,
                             cmpFunct);
            while (last->next != NULL) {
                last = last->next;
                AddHashTableItem(newHashTable, getKey(hashtable, last->element), getValue(hashtable, last->element), createElement,
                                 cmpFunct);
            }
        }
    }
    DeleteHashTable(hashtable, deleteFunct);
    return newHashTable;
}

void DeleteHashTable(HASHTABLE *hashtable, void(*deleteFunct)(void *a)) { // delete a hashtable completely
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
}



