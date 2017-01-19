//
// Created by lilla on 19/01/17.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node {
    void* element;
    struct node *next;
}NODE;

typedef struct{
    int size;
    struct node **hashTable;
    int(*hashFunction)(void* key, int size);
    int nrOfElements;
}HASHTABLE;

HASHTABLE *CreateHashTable(int size, int(*hashFunction)(void *key, int size));
//TODO print 4
//TODO add 1
//TODO delete item 2
//TODO search 3
//TODO rehash 6
//TODO delete table 5

#endif //HASHTABLE_HASHTABLE_H
