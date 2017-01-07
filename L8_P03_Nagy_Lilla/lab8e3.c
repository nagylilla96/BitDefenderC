//
// Created by lilla on 03/01/17.
//

#include "lab8e3.h"

first* CreateArraySequence(int size) { // create an array by using the CreateVector function from Vector.h
    return CreateVector((size_t) size);
}

void ADDArray(first* list, int *size, MyNode*(*getNode)(int i, first* list)) { // add an element to the array
    MyNode *myNode = getNode(0, list);
    if (myNode == NULL) { // if the created node is null, we return
        printf("My node is null\n");
        return;
    }
    int i;
    if (list->nrOfElements + 1 >= *size) { //if allocated space is not enough, we reallocate
        *size *= 2;
        list->pointer = realloc(list->pointer, sizeof(list->pointer) * (*size)); // if the data amount exceeds the size, realloc space
    }
    if (list->nrOfElements == myNode->index) { // if the index is the last one from the array, we just add it
        list->pointer[list->nrOfElements]= malloc(sizeof(myNode));
        list->pointer[list->nrOfElements] = myNode;
    }
    else {
        for (i = list->nrOfElements; i > myNode->index; i--) { // else we make space for it (move every element after the one
            list->pointer[i] = list->pointer[i - 1]; // with the desired indec), add it, and arrange the indexes in a
            ((MyNode*)list->pointer[i])->index ++; // consecutive way
        }
        list->pointer[myNode->index] = myNode;
    }
    list->nrOfElements++;
}

MyNode* REMOVEArray(int index, first *list, int(*cmpFunct)(void *a, void *b)) { // remove a node from the array
    MyNode *myNode = GETArray(index, list, cmpFunct); // we get the desired node by using our own get function
    int i;
    for (i = index; i < list->nrOfElements; i++) {
        list->pointer[i] = list->pointer[i + 1]; // we move every item after it one place to the left
        ((MyNode*)list->pointer[i])->index --;
    }
    list->nrOfElements--;
    return myNode;
}

MyNode* GETArray(int index, first *list, int(*cmpFunc)(void *a, void *b)) { // get an array element by index
    MyNode myNode;
    myNode.element = 0;
    myNode.index = index; // create the element myNode with element = 0 (because it doesn't matter) and the desired index
    return ReturnByIndex(list, &myNode, cmpFunc); // return the node
}

int SEARCHArray(int element, first *list, int(*cmpFunct)(void *a, void *b), int(*printFunct)()) { // search the array for a
    MyNode myNode; // required element, make a myNode with index = 0 (it doesn't matter) and the desired element, and
    myNode.index = 0; // return it
    myNode.element = element;
    return SearchVectorItem(list, &myNode, cmpFunct, printFunct);
}

void ADDList(LIST* list, MyNode* element, int index) { // add a node to the list
    NODE* newNode = CreateNode(element); // create a node
    NODE *node = GetLinkedListItem(list, index);
    MyNode *myNode;
    if (list->nrOfElements == 0) { // if the list is empty, both the first and the last pointers will point to the new node
        list->first = newNode;
        list->last = newNode;
        newNode->next = NULL;
    }
    else {
        if (node == NULL) {
            printf("Node is null\n");
        }
        if (index == list->nrOfElements) { // if the index is the last one, the last pointer will point to the new node
            list->last->next = newNode; // we use for this the @node, which is the pointer to the previous element
            newNode->next = NULL;
            list->last = newNode;
        }
        else {
            newNode->next = node->next;
            node->next = newNode;
        }
    }
    list->nrOfElements ++; // we don't have to increase the index if there are two consecutive indexes or if it's the
    if (newNode == list->first) { // first element of the list
        newNode = newNode->next;
    }
    else {
        if (node != NULL) {
            MyNode *prevEl = node->element;
            MyNode *currEl = newNode->element;
            if (prevEl->index != currEl->index) {
                newNode = newNode->next;
            }
        }
    }
    while (newNode != NULL) {
        myNode = newNode->element; // we set the indexes so they will be consecutive
        myNode->index ++;
        newNode = newNode->next;
    }
}

MyNode *REMOVEList(LIST *list, int index) { // remove a node from the list
    NODE *node = GetLinkedListItem(list, index + 1); // get the item we need to remove
    NODE *ptr = node;
    MyNode *myNode;
    if (node == NULL) {
        printf("Node is null\n");
        return NULL;
    }
    if (index == 0) { // if it's the first node, the last pointer will point to the next node
        list->first = node->next;
        ptr = list->first;
    }
    else {
        NODE *prevNode = GetLinkedListItem(list, index); // else we get the previous node
        if (index == list->nrOfElements - 1) {
            list->last = prevNode;
            prevNode->next = NULL; // and if it's the last element, the it will be the last node
        }
        else {
            prevNode->next = node->next; // otherwise its next node will be the deleted node's next
            ptr = node->next;
     }
    }
    node->next = NULL;
    list->nrOfElements --;
    while (ptr != NULL) { // we set the indexes in a consecutive way
        myNode = ptr->element;
        myNode->index --;
        ptr = ptr->next;
    }
    return node->element;
}

MyNode *GETList(LIST *list, int index) { // we get the list element by using a LinkedList.h function
    return GetLinkedListItem(list, index + 1)->element;
}

int SEARCHList(LIST *list, MyNode *element, int (*cmpFunctEl)(void *a, void *b), void(*printListFunct)(void *a)) {
    if (SearchLinkedListItem(list, element, cmpFunctEl, printListFunct) == NULL) { // we search for a desired element
        return -1; // using the SearchLinkedListItem function from LinkedList.h
    }
    MyNode *myNode = SearchLinkedListItem(list, element, cmpFunctEl, printListFunct)->element;
    return myNode->index;
}