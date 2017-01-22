//
// Created by lilla on 22/01/17.
//

#ifndef BALANCEDBSTTESTER_BALANCEDBSTTESTER_H
#define BALANCEDBSTTESTER_BALANCEDBSTTESTER_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "BalancedBST.h"

typedef struct{
    int data;
}ELEMENT;

int cmpFunct(void *a, void *b);
void printData(void *a, FILE *f);
void runTester(char *nameIN, char *nameOut);
void error(int errorCode, FILE *f, char *command);
int commandNr(char *command);

#endif //BALANCEDBSTTESTER_BALANCEDBSTTESTER_H
