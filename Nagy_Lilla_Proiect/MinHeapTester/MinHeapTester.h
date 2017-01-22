//
// Created by lilla on 20/01/17.
//

#ifndef MINHEAPTESTER_MINHEAPTESTER_H
#define MINHEAPTESTER_MINHEAPTESTER_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <MinHeap.h>

typedef struct {
    int number;
}ELEMENT;

void *createNode(int number);
void *getNode(int i, FILE *f);
void printFunc(first* one, int index, FILE *f);
void anotherPrintFunc(first *one, int index, FILE *f);
void printAllFunc(first* one, FILE *f);
int cmpFunct(void *a, void *b);
void freeNode(void *a);
void runTester(char *nameIN, char *nameOut);
void error(int errorCode, FILE *f, char *command);
int commandNr(char *command);

#endif //MINHEAPTESTER_MINHEAPTESTER_H
