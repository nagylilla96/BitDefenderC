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

void PrintLinkedList(LIST* list, void(*printFuct)(void *a, FILE *f), FILE *f) {
    NODE *node = list->first;
    if (node == NULL) {
        fprintf(f, "First node is null");
        return;
    }
    while (node != NULL) {
        printFuct(node->element, f);
        node = node->next;
    }
}

NODE *GetLinkedListItem(LIST* list, int index) {
    int i;
    NODE *node = list->first;
    if (index == 0) {
        return list->first;
    }
    for (i = 0; i < index - 1; i++) {
        node = node->next;
    }
    return node;
}

void PutLinkedListItem(LIST* list, void* element, int index) {
    NODE *node = GetLinkedListItem(list, index);
    NODE* newNode = CreateNode(element);
    if (list->nrOfElements == 0) {
        list->first = node;
        list->last = node;
    }
    else {
        newNode->next = node->next;
        node->next = newNode;
    }
    if (index == 0) {
   	list->first = newNode;
	}
	if (index == list->nrOfElements) {
list->last = newNode;
}
    list->nrOfElements ++;
}

NODE *DeleteLinkedListItem(LIST* list, int index) {
    NODE *prevNode = GetLinkedListItem(list, index);
    NODE *node = GetLinkedListItem(list, index + 1);
    if (index == list->nrOfElements - 1) {
        list->last = prevNode;
    }
    if (index == 0) {
        list->first = node->next;
    }
    else {
        prevNode->next = node->next;
    }
    node->next = NULL;
    list->nrOfElements --;
    return node;
}

NODE *SearchLinkedListItem(LIST* list, void* searched, int (*cmpFunct)(void *a, void *b)) {
    NODE* node = list->first;
    while (node != NULL) {
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
    NODE *node = list->first;
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

LIST *MergeLinkedLists(LIST* listA, LIST* listB, int (*cmpFunct)(void *a, void *b), void (*swap) (void *a, void *b)) {
    SortLinkedList(listA, cmpFunct, swap);
    SortLinkedList(listB, cmpFunct, swap);
    LIST *listC = CreateLinkedList();
    NODE *nodeA = listA->first;
    NODE *nodeB = listB->first;
    while (nodeA != NULL && nodeB != NULL){
        if (cmpFunct(nodeA->element, nodeB->element) < 0) {
            AddLinkedListItem(listC, nodeA->element);
            nodeA = nodeA->next;
        }
        else {
            if (cmpFunct(nodeA->element, nodeB->element) > 0) {
                AddLinkedListItem(listC, nodeB->element);
                nodeB = nodeB->next;
            }
            else {
                AddLinkedListItem(listC, nodeA->element);
                nodeA = nodeA->next;
                nodeB = nodeB->next;
            }
        }
    }
    while (nodeA != NULL) {
        AddLinkedListItem(listC, nodeA->element);
        nodeA = nodeA->next;
    }
    while (nodeB != NULL) {
        AddLinkedListItem(listC, nodeB->element);
        nodeB = nodeB->next;
    }
    return listC;
}

void DeleteLinkedList(LIST *list) {
    NODE *node = list->first;
    while (node != NULL) {
        NODE *temp = node;
        free(temp->element);
        node = node->next;
        temp->next = NULL;
        free(temp);
    }
    free(list->first);
    free(list->last);
    free(list);
}
