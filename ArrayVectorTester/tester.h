//
// Created by lilla on 14/01/17.
//

#ifndef ARRAYVECTORTESTER_TESTER_H
#define ARRAYVECTORTESTER_TESTER_H

#include <stdio.h>
#include <dirent.h>
#include "Vector.h"

typedef struct {
    int integer;
    float real;
} MyNode;

MyNode *getNode(int i, FILE *f);
void printFunc(first* one, int index, FILE *f);
int cmpFunct(void *a, void *b);
void freeNode(void *a);
void runTester(char *nameIN, char *nameOut);
void error(int errorCode, FILE *f, char *command);
int commandNr(char *command);

#endif //ARRAYVECTORTESTER_TESTER_H
