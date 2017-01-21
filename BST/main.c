#include "BST.h"

typedef struct{
    int data;
}ELEMENT;

int cmpFunct(void *a, void *b) {
    ELEMENT *aa = (ELEMENT*) a;
    ELEMENT *bb = (ELEMENT*) b;
    if (aa->data > bb->data) {
        return 1;
    }
    else {
        if (aa->data == bb->data) {
            return 0;
        }
        else {
            return -1;
        }
    }
}

void printData(void *a, FILE *f) {
    ELEMENT *node = (ELEMENT*) a;
    fprintf(f, "%d", node->data);
}

int myRand(int max) {
    int x = (int) random();
    while (x > max) {
        x = x / 13;
    }
    return x;
}

int main() {
    ELEMENT **elements = calloc(100, sizeof(ELEMENT*));
    TREE *bst = CreateBST();
    BST *root = bst->root;
    BST *node = NULL;
    for (int i = 0; i < 100; i++) {
        elements[i]  = calloc(1, sizeof(ELEMENT));
        if (i < 10) {
            elements[i]->data = myRand(9);
            root = AddBSTItem(root, elements[i], cmpFunct);
            node = root;
        }
    }
    PreorderBST(root, printData, stdout);
    printf("\n");
    node = root;
    PrintBST(node, 0, printData, stdout);
    return 0;
}