//
// Created by lilla on 03/01/17.
//

#ifndef LAB08EX03_LAB8E3_H
#define LAB08EX03_LAB8E3_H
#include "Vector.h"

typedef struct {
    int index;
    int element;
} node;

first* CreateArraySequence(int size);
void ADD(first* list, int *size, node*(*getNode)(int i, first* list));
node* REMOVE(int index, first *list, int(*cmpFunct)(void *a, void *b));
node* GET(int index, first *list, int(*cmpFunc)(void *a, void *b));
int SEARCH(int element, first *list, int(*cmpFunct)(void *a, void *b));


#endif //LAB08EX03_LAB8E3_H
