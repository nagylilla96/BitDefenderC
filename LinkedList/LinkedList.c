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

void PutLinkedListItem(LIST* list, void* element, int index) {
    int i;
    NODE *node = list->first;
    NODE* newNode = CreateNode(element);
    for (i = 0; i < index - 1; i++) {
        node = node->next;
    }
    newNode->next = node->next;
    node->next = newNode;
}

NODE *GetLinkedListItem(LIST* list, int index) {
    int i;
    NODE *node = list->first;
    for (i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}