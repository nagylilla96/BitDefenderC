//
// Created by lilla on 03/01/17.
//

#ifndef LAB08EX03_LAB8E3_H
#define LAB08EX03_LAB8E3_H
#include "Vector.h"

typedef struct {
    int *list;
    int nr;
} first;

first* CreateArraySequence(int size);
void ADD(int index, int element, first* list, int *size, void*(*getNode)(int i));
void REMOVE(int index, first *list);


#endif //LAB08EX03_LAB8E3_H
