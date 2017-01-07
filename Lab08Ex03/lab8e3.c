//
// Created by lilla on 03/01/17.
//

#include <LinkedList.h>
#include "lab8e3.h"

first* CreateArraySequence(int size) {
    return (first*) CreateVector((size_t) size);
}

void ADDArray(first* list, int *size, MyNode*(*getNode)(int i, first* list)) {
    MyNode *myNode = getNode(0, (first*) list);
    if (myNode == NULL) {
        printf("My node is null\n");
        return;
    }
    int i;
    if (list->nrOfElements + 1 >= *size) {
        *size *= 2;
        list->pointer = realloc(list->pointer, sizeof(list->pointer) * (*size)); // if the data amount exceeds the size, realloc space
    }
    if (list->nrOfElements == myNode->index) {
        list->pointer[list->nrOfElements]= malloc(sizeof(myNode));
        list->pointer[list->nrOfElements] = myNode;
    }
    else {
        for (i = list->nrOfElements; i > myNode->index; i--) {
            list->pointer[i] = list->pointer[i - 1];
            ((MyNode*)list->pointer[i])->index ++;
        }
        list->pointer[myNode->index] = myNode;
    }
    list->nrOfElements++;
}

MyNode* REMOVEArray(int index, first *list, int(*cmpFunct)(void *a, void *b)) {
    MyNode *myNode = GETArray(index, list, cmpFunct);
    int i;
    for (i = index; i < list->nrOfElements; i++) {
        list->pointer[i] = list->pointer[i + 1];
        ((MyNode*)list->pointer[i])->index --;
    }
    list->nrOfElements--;
    return myNode;
}

MyNode* GETArray(int index, first *list, int(*cmpFunc)(void *a, void *b)) {
    MyNode myNode;
    myNode.element = 0;
    myNode.index = index;
    return ReturnByIndex(list, &myNode, cmpFunc);
}

int SEARCHArray(int element, first *list, int(*cmpFunct)(void *a, void *b), int(*printFunct)()) {
    MyNode myNode;
    myNode.index = 0;
    myNode.element = element;
    return SearchVectorItem(list, &myNode, cmpFunct, printFunct);
}

void ADDList(LIST* list, MyNode* element, int index) {
    NODE* newNode = CreateNode(element);
    MyNode *myNode;
    if (list->nrOfElements == 0) {
        list->first = newNode;
        list->last = newNode;
    }
    else {
        if (index == list->nrOfElements) {
            list->last = newNode;
        }
        NODE *node = GetLinkedListItem(list, index - 1);
        newNode->next = node->next;
        node->next = newNode;
    }
    list->nrOfElements ++;
    while (newNode->next != NULL) {
        myNode = newNode->next->element;
        myNode->index ++;
        newNode = newNode->next;
    }
}

MyNode *REMOVEList(LIST *list, int index) {
    NODE *node = GetLinkedListItem(list, index);
    NODE *ptr = node;
    MyNode *myNode;
    if (node == NULL) {
        printf("Node is null\n");
    }
    if (index == 0) {
        list->first = node->next;
        ptr = list->first;
    }
    else {
        NODE *prevNode = GetLinkedListItem(list, index - 1);
        if (index == list->nrOfElements - 1) {
            list->last = prevNode;
            prevNode->next = NULL;
        }
        else {
            prevNode->next = node->next;
            ptr = node->next;
        }
    }
    node->next = NULL;
    list->nrOfElements --;
    while (ptr != NULL) {
        myNode = ptr->element;
        myNode->index --;
        ptr = ptr->next;
    }
    return node->element;
}

MyNode *GETList(LIST *list, int index) {
    return GetLinkedListItem(list, index)->element;
}

int SEARCHList(LIST *list, MyNode *element, int (*cmpFunctEl)(void *a, void *b), void(*printListFunct)(void *a)) {
    if (SearchLinkedListItem(list, element, cmpFunctEl, printListFunct) == NULL) {
        return -1;
    }
    MyNode *myNode = SearchLinkedListItem(list, element, cmpFunctEl, printListFunct)->element;
    return myNode->index;
}