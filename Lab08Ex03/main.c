#include <LinkedList.h>
#include "lab8e3.h"

MyNode *createNode(int index, int element) {
    MyNode *myNode = (MyNode*) malloc(sizeof(MyNode));
    myNode->index = index;
    myNode->element = element;
    return myNode;
}

MyNode *getNode(int i, first *list) {
    int index, element;
    printf("Index: ");
    scanf("%d", &index);
    if (index > list->nrOfElements) {
        printf("You can't add this here!\n");
        return NULL;
    }
    printf("Element: ");
    scanf("%d", &element);
    return createNode(index, element);
}

int cmpFunctInd(void *a, void *b) {
    MyNode *aa = (MyNode *) a;
    MyNode *bb = (MyNode *) b;
    if (aa->index > bb->index) {
        return 1;
    }
    else {
        if (aa->index == bb->index) {
            return 0;
        }
        else {
            return -1;
        }
    }
}

int cmpFunctEl(void *a, void *b) {
    MyNode *aa = (MyNode *) a;
    MyNode *bb = (MyNode *) b;
    if (aa->element > bb->element) {
        return 1;
    }
    else {
        if (aa->element == bb->element) {
            return 0;
        }
        else {
            return -1;
        }
    }
}

MyNode *createElement(int index, int value) {
    MyNode *node = malloc(sizeof(MyNode));
    node->index = index;
    node->element = value;
    return node;
}

int printFuct() {
    return 1;
}

void printListFunct(void *a) {
    MyNode *aa = (MyNode*) a;
    printf("index = %d\n", aa->index);
    printf("element = %d\n", aa->element);
}

int main() {
    int size = 50;
    int answer, index, element;
    MyNode *node;
    printf("Do you want an 1. Array or a 2. List?\n");
    scanf("%d", &answer);
    if (answer == 1) {
        first *list = CreateArraySequence(size);
        if (list == NULL) {
            printf("Array hasn't been created\n");
        }
        printf("What do you want to do?\n1. ADD\n2. REMOVE\n3. GET\n");
        printf("4. SEARCH\n5. EXIT\nPlease write the number!\n");
        while (scanf("%d", &answer) >= 0) {
            switch (answer) {
                case 1:
                    ADDArray(list, &size, getNode);
                    break;
                case 2:
                    printf("Which index do you want to delete?\n");
                    scanf("%d", &index);
                    if (index >= list->nrOfElements) {
                        printf("There are less than %d elements!\n", index);
                        break;
                    }
                    REMOVEArray(index, list, cmpFunctInd);
                    break;
                case 3:
                    printf("Which index do you want to get?\n");
                    scanf("%d", &index);
                    if (index >= list->nrOfElements) {
                        printf("The index is not correct!\n");
                        break;
                    }
                    MyNode *x = GETArray(index, list, cmpFunctInd);
                    if (x == NULL) {
                        printf("Index not found\n");
                        break;
                    }
                    printf("Index: %d\n", x->index);
                    printf("Element: %d\n", x->element);
                    break;
                case 4:
                    printf("What element are you looking for?\n");
                    scanf("%d", &index);
                    SEARCHArray(index, list, cmpFunctEl, printFuct);
                    break;
                case 5:
                    return 0;
                default:
                    break;
            }
            printf("What do you want to do?\n1. ADD\n2. REMOVE\n3. GET\n");
            printf("4. SEARCH\n5. EXIT\nPlease write the number!\n");
        }
    }
    else {
        if (answer == 2) {
            LIST *list = CreateLinkedList();
            if (list == NULL) {
                printf("List hasn't been created!\n");
            }
                printf("What do you want to do?\n1. ADD\n2. REMOVE\n3. GET\n");
                printf("4. SEARCH\n5. EXIT\nPlease write the number!\n");
                while (scanf("%d", &answer) >= 0) {
                    switch (answer) {
                        case 1:
                            printf("At what index do you wish to add?\n");
                            scanf("%d", &index);
                            if (index > list->nrOfElements) {
                                printf("You can't add this here!\n");
                            }
                            printf("What element do you want to add?\n");
                            scanf("%d", &element);
                            node = createElement(index, element);
                            ADDList(list, node, index);
                            break;
                        case 2:
                            printf("Which index do you want to delete?\n");
                            scanf("%d", &index);
                            if (index >= list->nrOfElements) {
                                printf("There are less than %d elements!\n", index);
                                break;
                            }
                            REMOVEList(list, index);
                            break;
                        case 3:
                            printf("Which index do you want to get?\n");
                            scanf("%d", &index);
                            if (index >= list->nrOfElements) {
                                printf("The index is not correct!\n");
                                break;
                            }
                            MyNode *x = GETList(list, index);
                            if (x == NULL) {
                                printf("Index not found\n");
                                break;
                            }
                            printf("Index: %d\n", x->index);
                            printf("Element: %d\n", x->element);
                            break;
                        case 4:
                            printf("What element are you looking for?\n");
                            scanf("%d", &index);
                            node = createElement(0, index);
                            SEARCHList(list, node, cmpFunctEl, printListFunct);
                            break;
                        case 5:
                            return 0;
                        default:
                            break;
                    }
                    printf("What do you want to do?\n1. ADD\n2. REMOVE\n3. GET\n");
                    printf("4. SEARCH\n5. EXIT\nPlease write the number!\n");
                }
            }
        else {
            printf("Number not valid\n");
        }
    }
    return 0;
}