#include <Vector.h>
#include "lab8e3.h"

node *createNode(int index, int element) {
    node *myNode = (node*) malloc(sizeof(node));
    myNode->index = index;
    myNode->element = element;
    return myNode;
}

node *getNode(int i, first *list) {
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
    node *aa = (node *) a;
    node *bb = (node *) b;
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
    node *aa = (node *) a;
    node *bb = (node *) b;
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

int main() {
    int size = 50;
    first *list = CreateArraySequence(size);
    if (list == NULL) {
        printf("List hasn't been created\n");
    }
    int answer, index;
    printf("What do you want to do?\n1. ADD\n2. REMOVE\n3. GET\n");
    printf("4. SEARCH\n5. EXIT\nPlease write the number!\n");
    while (scanf("%d", &answer) >= 0) {
        switch (answer) {
            case 1:
                ADD(list, &size, getNode);
                break;
            case 2:
                printf("Which index do you want to delete?\n");
                scanf("%d", &index);
                if (index >= list->nrOfElements) {
                    printf("There are less than %d elements!\n", index);
                    break;
                }
                REMOVE(index, list, cmpFunctInd);
                break;
            case 3:
                printf("Which index do you want to get?\n");
                scanf("%d", &index);
                if (index >= list->nrOfElements) {
                    printf("The index is not correct!\n");
                    break;
                }
                node *x = GET(index, list, cmpFunctInd);
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
                SEARCH(index, list, cmpFunctEl);
                break;
            case 5:
                return 0;
            default:
                break;
        }
        printf("What do you want to do?\n1. ADD\n2. REMOVE\n3. GET\n");
        printf("4. SEARCH\n5. EXIT\nPlease write the number!\n");
    }
    return 0;
}