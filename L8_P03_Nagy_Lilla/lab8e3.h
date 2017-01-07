//
// Created by lilla on 03/01/17.
//

#ifndef LAB08EX03_LAB8E3_H
#define LAB08EX03_LAB8E3_H
#include "Vector.h"
#include "LinkedList.h"

typedef struct {
    int index;
    int element;
} MyNode;

first* CreateArraySequence(int size);
void ADDArray(first* list, int *size, MyNode*(*getNode)(int i, first* list));
MyNode* REMOVEArray(int index, first *list, int(*cmpFunct)(void *a, void *b));
MyNode* GETArray(int index, first *list, int(*cmpFunc)(void *a, void *b));
int SEARCHArray(int element, first *list, int(*cmpFunct)(void *a, void *b), int(*printFunct)());
void ADDList(LIST* list, MyNode* element, int index);
MyNode *REMOVEList(LIST *list, int index);
MyNode *GETList(LIST *list, int index);
int SEARCHList(LIST *list, MyNode *element, int (*cmpFunctEl)(void *a, void *b), void(*printListFunct)(void *a));

#endif //LAB08EX03_LAB8E3_H
