#include "BST.h"

typedef struct{
    int data;
}ELEMENT;

int cmpFunct(void *a, void *b) { // a function that compares two elements' data
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

void printData(void *a, FILE *f) { // a function that prints one element
    ELEMENT *node = (ELEMENT*) a;
    fprintf(f, "%d", node->data);
}

int main() {
    ELEMENT **elements = calloc(100, sizeof(ELEMENT*));
    TREE *bst = CreateBST();
    BST *minVal = findMin(bst->root, cmpFunct);
    if (minVal == NULL) {
        printf("\nMin value not found\n");
    }
    else {
        printf("\nMin value is: %d\n", ((ELEMENT*)minVal->element)->data);
    }
    for (int i = 0; i < 100; i++) {
        elements[i]  = calloc(1, sizeof(ELEMENT));
    }
    elements[0]->data = 5;
    elements[1]->data = 3;
    elements[2]->data = 2;
    elements[3]->data = 7;
    elements[4]->data = 9;
    elements[5]->data = 1;
    elements[6]->data = 8;
    elements[7]->data = 4;
    elements[8]->data = 2;
    elements[9]->data = 0;
    for (int i = 0; i < 10; i++) {
        bst->root = AddBSTItem(bst->root, elements[i], cmpFunct);
    }
    PreorderBST(bst->root, printData, stdout);
    printf("\n");
    InorderBST(bst->root, printData, stdout);
    printf("\n");
    PostorderBST(bst->root, printData, stdout);
    printf("\n");
    PrintBST(bst->root, 0, printData, stdout);
    printf("Height of the three: %d\n", HeightBST(bst->root));
    elements[10]->data = 6;
    BST *found = SearchBSTItem(bst->root, elements[10], cmpFunct);
    if (found == NULL){
        printf("\nElement %d not found!\n", elements[10]->data);
    }
    else {
        printf("\nElement %d found!\n", elements[10]->data);
    }
    BST *minVal1 = findMin(bst->root, cmpFunct);
    if (minVal1 == NULL) {
        printf("\nMin value not found\n");
    }
    else {
        printf("\nMin value is: %d\n", ((ELEMENT*)minVal1->element)->data);
    }
    BST *maxVal = findMax(bst->root, cmpFunct);
    if (maxVal == NULL) {
        printf("Min value not found\n");
    }
    else {
        printf("Min value is: %d\n", ((ELEMENT*)maxVal->element)->data);
    }
    elements[11]->data = 6;
    if (SearchBSTItem(bst->root, elements[11], cmpFunct) != NULL){
        DeleteBSTItem(bst->root, elements[11], cmpFunct);
        PrintBST(bst->root, 0, printData, stdout);
        printf("\nHeight of the three: %d\n", HeightBST(bst->root));
        printf("\n.................\n");
    }
    else{
        printf("Element %d not found!\n", elements[11]->data);
    }
    TREE *bst1 = CreateBST();
    elements[13]->data = 2;
    elements[14]->data = 4;
    elements[15]->data = 9;
    elements[16]->data = 3;
    elements[17]->data = 6;
    elements[18]->data = 8;
    elements[19]->data = 0;
    for (int i = 13; i < 20; i++) {
        bst1->root = AddBSTItem(bst1->root, elements[i], cmpFunct);
    }
    PreorderBST(bst1->root, printData, stdout);
    printf("\n..................\n");
    PrintBST(bst1->root, 0, printData, stdout);
    printf("\nHeight of the three: %d\n", HeightBST(bst->root));
    printf("\n..................\n");
    TREE *bst2 = CreateBST();
    bst2->root = MergeBSTs(bst->root, bst1->root, cmpFunct);
    printf("tree0\n");
    PrintBST(bst->root, 0, printData, stdout);
    printf("mergedTree\n");
    PrintBST(bst2->root, 0, printData, stdout);
    printf("\nHeight of the three: %d\n", HeightBST(bst->root));
    printf("three1\n");
    PrintBST(bst1->root, 0, printData, stdout);
    printf("three0\n");
    PrintBST(bst->root, 0, printData, stdout);
    DeleteBST(bst, cmpFunct);
    DeleteBST(bst1, cmpFunct);
    DeleteBST(bst2, cmpFunct);
    return 0;
}