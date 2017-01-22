//
// Created by lilla on 16/01/17.
//

#ifndef LINKEDLISTTESTER_TESTER_H
#define LINKEDLISTTESTER_TESTER_H

#include "LinkedList.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>


typedef struct {
    int integer;
    float real;
}ELEMENT;

void printFunct(void *a, FILE *f);
ELEMENT *createElement(int integer, float real);
void freeNode(void* a);
int cmpFunct(void *a, void *b);
void swap(void *a, void *b);
void runTester(char *nameIN, char *nameOut);
void error(int errorCode, FILE *f, char *command);
int commandNr(char *command);


#endif //LINKEDLISTTESTER_TESTER_H
