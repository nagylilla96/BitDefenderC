//
// Created by lilla on 21/01/17.
//

#ifndef BSTTESTER_BSTTESTER_H
#define BSTTESTER_BSTTESTER_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "BST.h"

typedef struct{
    int data;
}ELEMENT;

int cmpFunct(void *a, void *b);
void printData(void *a, FILE *f);
void runTester(char *nameIN, char *nameOut);
void error(int errorCode, FILE *f, char *command);
int commandNr(char *command);

#endif //BSTTESTER_BSTTESTER_H
