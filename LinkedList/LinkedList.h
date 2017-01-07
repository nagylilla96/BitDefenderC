//
// Created by lilla on 06/01/17.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    void *element;
    struct node *next;
}NODE;

typedef struct {
    NODE *first;
    NODE *last;
    int nrOfElements;
}LIST;

LIST *CreateLinkedList();
NODE *CreateNode(void* element);
int AddLinkedListItem(LIST *list, void* element);
void PrintLinkedList(LIST* list, void(*printFuct)(void *a));
void PutLinkedListItem(LIST* list, void* newNode, int index);
NODE *GetLinkedListItem(LIST* list, int index);
NODE *DeleteLinkedListItem(LIST* list, int index);
NODE *SearchLinkedListItem(LIST* list, void* element, int (*cmpFunct)(void *a, void *b), void (*printFuct) (void* a));
void SortLinkedList(LIST* list, int (*cmpFunct)(void *a, void *b), void (*swap) (void *a, void *b));

#endif //LINKEDLIST_LINKEDLIST_H
