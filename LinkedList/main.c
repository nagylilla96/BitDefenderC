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

int main() {
    ELEMENT *element;
    LIST *list = CreateLinkedList();
    element = createElement(0);
    AddLinkedListItem(list, element);
    element = createElement(1);
    AddLinkedListItem(list, element);
    element = createElement(2);
    AddLinkedListItem(list, element);
    PrintLinkedList(list, printFunct);
    element = createElement(3);
    PutLinkedListItem(list, element, 1);
    PrintLinkedList(list, printFunct);
    printFunct(GetLinkedListItem(list, 1)->element);
    return 0;
}