#include "LinkedList.h"

typedef struct node{
    struct node* next;
    int index;
}NODE;

NODE *CreateNode(int index) {
    NODE *node = malloc(sizeof(NODE));
    if (node) {
        node->index = index;
        node->next = NULL;
    }
    else {
        printf("CreateNode failed\n");
    }
    return node;
}

int main() {
    LIST *list = CreateLinkedList();
    NODE *node = CreateNode(1);
    AddLinkedListItem(list, node);
    printf("Hello, World!\n");
    return 0;
}