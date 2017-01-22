//
// Created by lilla on 20/01/17.
//

#ifndef HASHTABLETESTER_HASHTESTER_H
#define HASHTABLETESTER_HASHTESTER_H

#include <stdio.h>
#include <dirent.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "HashTable.h"

typedef struct {
    int key;
    int value;
}ELEMENT;

ELEMENT *createElement(int key, int value);
int hashFunction(void *key, int size);
int cmpFunct(void *a, void *b);
void printElement(void *a, FILE *f);
void deleteFunct(void *a);
void *getKey(HASHTABLE *hashtable, void *a);
void *getValue(HASHTABLE *hashtable, void *a);
void runTester(char *nameIN, char *nameOut);
void error(int errorCode, FILE *f, char *command);
int commandNr(char *command);

#endif //HASHTABLETESTER_HASHTESTER_H
