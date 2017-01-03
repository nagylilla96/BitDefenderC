//
// Created by lilla on 03/01/17.
//

#include "lab8e3.h"

first* CreateArraySequence(int size) {
    return CreateVector((size_t) size);
}

void ADD(int index, int element, first* list, int *size, void*(*getNode)(int i)) {
    AddVectorItems(1, list, (size_t*) size, getNode(0));
}

void REMOVE(int index, first *list) {
    DeleteVectorItem(list, index);
}

void GET
