//
// Created by lilla on 06/01/17.
//

#include "LinkedList.h"

LIST *CreateLinkedList() {
    LIST *list = malloc(sizeof(LIST));
    if (list) {
        list->nrOfElements = 0;
        list->first = NULL;
        list->last = NULL;
    }
    else {
        printf("CreateLinkedList failed\n");
    }
    return list;
}

int AddLinkedListItem(LIST *list, void* node) {
    if (list) {
        if (list->nrOfElements == 0) {
            list->first = node;
            list->last = node;
        }
        else {
            list->last->next;
            list->last = node;
        }
        list->nrOfElements++;
        return 1;
    }
    return 0;
}