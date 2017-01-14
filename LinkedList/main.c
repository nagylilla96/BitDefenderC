#include "LinkedList.h"

typedef struct {
    int index;
}ELEMENT;

void printFunct(void *a, FILE *f) {

    ELEMENT *aa = (ELEMENT*) a;
    fprintf(f, "index = %d\n", aa->index);
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
    PrintLinkedList(list, printFunct, stdout);
    fprintf(stdout, "\n");
    element = createElement(3);
    PutLinkedListItem(list, element, 1);
    PrintLinkedList(list, printFunct, stdout);
    fprintf(stdout, "\n");
    printFunct(GetLinkedListItem(list, 1)->element, stdout);
    fprintf(stdout, "\n");
    ELEMENT* toDelete = DeleteLinkedListItem(list, 1)->element;
    printFunct(toDelete, stdout);
    fprintf(stdout, "\n");
    freeNode(toDelete);
    free(toDelete);
    PrintLinkedList(list, printFunct, stdout);
    fprintf(stdout, "\n");
    element = createElement(0);
    if (SearchLinkedListItem(list, element, cmpFunct) == NULL) {
        fprintf(stdout, "Not found\n");
    }
    else {
        printFunct(SearchLinkedListItem(list, element, cmpFunct)->element, stdout);
    }
    fprintf(stdout, "\n");
    SortLinkedList(list, cmpFunct, swap);
    PrintLinkedList(list, printFunct, stdout);
    element = createElement(5);
    AddLinkedListItem(list1, element);
    element = createElement(2);
    AddLinkedListItem(list1, element);
    element = createElement(3);
    AddLinkedListItem(list1, element);
    fprintf(stdout, "\n");
    PrintLinkedList(list1, printFunct, stdout);
    list2 = MergeLinkedLists(list, list1, cmpFunct, swap);
    fprintf(stdout, "\n");
    PrintLinkedList(list2, printFunct, stdout);
    DeleteLinkedList(list);
    DeleteLinkedList(list1);
    DeleteLinkedList(list2);
    return 0;
}