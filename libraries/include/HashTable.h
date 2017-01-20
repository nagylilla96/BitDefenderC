//
// Created by lilla on 19/01/17.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LinkedList.h"

typedef struct hashnode {
    void* element;
    struct hashnode *next;
    LIST *linkedList;
}HASHNODE;

typedef struct{
    int size;
    struct hashnode **hashTable;
    int(*hashFunction)(void* key, int size);
    int nrOfElements;
}HASHTABLE;

int implicitHashFunction(void *key, int size);
HASHNODE *CreateHashNode(void* element);
HASHTABLE *CreateHashTable(int size, int(*hashFunction)(void *key, int size));
int isPrime(int number);
int findPrime(int size);
void redimensionTable(HASHTABLE *hashtable);
void PrintHashTable(HASHTABLE *hashtable, void(*printElement)(void* a, FILE *f), FILE *f);
int AddHashTableItem(HASHTABLE *hashtable, void *key, void *value, void*(*createElement)(void *, void *),
                     int (*cmpFunct)(void *a, void *b));
int DeleteHashTableItem(HASHTABLE *hashtable, void *key, void *value, void*(*createElement)(void *key, void *value), int (*cmpFunct)(void *a, void *b));
int SearchHashTableItem(HASHTABLE *hashtable, void *key, void *value, void*(*createElement)(void *key, void *value), int (*cmpFunct)(void *a, void *b));
void DeleteHashTable(HASHTABLE *hashtable, void(*deleteFunct)(void *a));
HASHTABLE *RehashTable(HASHTABLE *hashtable, int(*hashFunction)(void *key, void *value),
                       void*(*getKey)(HASHTABLE *hashtable, void *a), void*(getValue)(HASHTABLE *hashtable, void *a),
                       void*(*createElement)(void *, void *), int (*cmpFunct)(void *a, void *b), void (*printFunct) (void *a),
                       void(*deleteFunct)(void *a));
//TODO print 4
//TODO add 1
//TODO delete item 2
//TODO search 3
//TODO rehash 6
//TODO delete table 5

#endif //HASHTABLE_HASHTABLE_H
