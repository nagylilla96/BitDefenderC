//
// Created by lilla on 03/01/17.
//

#include "lab8e3.h"

first* CreateArraySequence(int size) {
    return CreateVector((size_t) size);
}

void ADD(int index, int element, first* list, int *size, void(* newItem)(int index, int element, first *list, size_t size)) {
    AddVectorItems(1, list, (size_t*) size, newItem);
}
