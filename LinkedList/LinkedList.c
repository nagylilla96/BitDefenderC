//
// Created by lilla on 06/01/17.
//

#include <printf.h>
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

NODE *CreateNode(void* element) {
    NODE *node = malloc(sizeof(NODE));
    if (node) {
        node->element = element;
        node->next = NULL;
    }
    else {
        printf("CreateNode failed\n");
    }
    return node;
}

int AddLinkedListItem(LIST *list, void* element) {
    NODE *node = CreateNode(element);
    if (list) {
        if (list->nrOfElements == 0) {
            list->first = node;
            list->last = node;
        }
        else {
            list->last->next = node;
            list->last = node;
        }
        list->nrOfElements++;
        return 1;
    }
    return 0;
}

void PrintLinkedList(LIST* list, void(*printFuct)(void *a)) {
    NODE *node = list->first;
    if (node == NULL) {
        printf("First node is null");
        return;
    }
    while (node != NULL) {
        printFuct(node->element);
        node = node->next;
    }
}

NODE *GetLinkedListItem(LIST* list, int index) {
    int i;
    NODE *node = list->first;
    for (i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

void PutLinkedListItem(LIST* list, void* element, int index) {
    NODE *node = GetLinkedListItem(list, index - 1);
    NODE* newNode = CreateNode(element);
    newNode->next = node->next;
    node->next = newNode;
    list->nrOfElements ++;
}

NODE *DeleteLinkedListItem(LIST* list, int index) {
    NODE *prevNode = GetLinkedListItem(list, index - 1);
    NODE *node = GetLinkedListItem(list, index);
    prevNode->next = node->next;
    node->next = NULL;
    list->nrOfElements --;
    return node;
}

NODE *SearchLinkedListItem(LIST* list, void* searched, int (*cmpFunct)(void *a, void *b), void (*printFunct) (void* a)) {
    NODE* node = list->first;
    while (node->next != NULL) {
        if (cmpFunct(node->element, searched) == 0)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void SortLinkedList(LIST* list, int (*cmpFunct)(void *a, void *b), void (*swap) (void *a, void *b)) {
    int swapped;
    NODE *node;
    NODE *lastNode = NULL;
    if (node == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        swapped = 0;
        node = list->first;
        while (node->next != lastNode) {
            if (cmpFunct(node->element, node->next->element) > 0) {
                swap(node, node->next);
                swapped = 1;
            }
            node = node->next;
        }
        lastNode = node;
    }
    while (swapped);
}