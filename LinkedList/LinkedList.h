//
// Created by lilla on 06/01/17.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* first;
    void* last;
    int nrOfElements;
}LIST;

LIST *CreateLinkedList();
int AddLinkedListItem(LIST *list, void* node, void(*setNextNode)(void* currentNode, void *nextNode));

#endif //LINKEDLIST_LINKEDLIST_H
