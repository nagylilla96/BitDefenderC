#include "LinkedList.h"

typedef struct {
    int index;
}ELEMENT;

void printFunct(void *a) {

    ELEMENT *aa = (ELEMENT*) a;
    printf("index = %d\n", aa->index);
}

ELEMENT *createElement(int index) {
    ELEMENT *element = malloc(sizeof(ELEMENT));
    element->index = index;
    return element;
}

void freeNode(void* a) {
    return;
}

int cmpFunct(void *a, void *b) {
    ELEMENT *aa = (ELEMENT*) a;
    ELEMENT *bb = (ELEMENT*) b;
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

void swap(void *a, void *b){
    NODE *aa = (NODE*) a;
    NODE *bb = (NODE*) b;
    ELEMENT *temp;
    temp = aa->element;
    aa->element = bb->element;
    bb->element = temp;
}

int main() {
    ELEMENT *element;
    LIST *list = CreateLinkedList();
    LIST *list1 = CreateLinkedList();
    LIST *list2;
    element = createElement(2);
    AddLinkedListItem(list, element);
    element = createElement(0);
    AddLinkedListItem(list, element);
    element = createElement(1);
    AddLinkedListItem(list, element);
    PrintLinkedList(list, printFunct);
    printf("\n");
    element = createElement(3);
    PutLinkedListItem(list, element, 1);
    PrintLinkedList(list, printFunct);
    printf("\n");
    printFunct(GetLinkedListItem(list, 1)->element);
    printf("\n");
    ELEMENT* toDelete = DeleteLinkedListItem(list, 1)->element;
    printFunct(toDelete);
    printf("\n");
    freeNode(toDelete);
    free(toDelete);
    PrintLinkedList(list, printFunct);
    printf("\n");
    element = createElement(0);
    if (SearchLinkedListItem(list, element, cmpFunct, printFunct) == NULL) {
        printf("Not found\n");
    }
    else {
        printFunct(SearchLinkedListItem(list, element, cmpFunct, printFunct)->element);
    }
    printf("\n");
    SortLinkedList(list, cmpFunct, swap);
    PrintLinkedList(list, printFunct);
    element = createElement(5);
    AddLinkedListItem(list1, element);
    element = createElement(2);
    AddLinkedListItem(list1, element);
    element = createElement(3);
    AddLinkedListItem(list1, element);
    printf("\n");
    PrintLinkedList(list1, printFunct);
    list2 = MergeLinkedLists(list, list1, cmpFunct, swap);
    printf("\n");
    PrintLinkedList(list2, printFunct);
    DeleteLinkedList(list);
    DeleteLinkedList(list1);
    DeleteLinkedList(list2);
    return 0;
}