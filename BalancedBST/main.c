#include "BalancedBST.h"

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

int main() {
    ELEMENT **elements = calloc(100, sizeof(ELEMENT*));
    BalancedTree *bst = CreateBalancedBST();
    BalancedBST *minVal = findMin(bst->root, cmpFunct);
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
        bst->root = AddBalancedBSTItem(bst->root, elements[i], cmpFunct);
        printf("\n.....\n");
        PrintBalancedBST(bst->root, 0, printData, stdout);
        printf("\n.....\n");
        balance(bst->root);
        PrintBalancedBST(bst->root, 0, printData, stdout);
        printf("\n.....\n");
    }
    PreorderBalancedBST(bst->root, printData, stdout);
    printf("\n");
    InorderBalancedBST(bst->root, printData, stdout);
    printf("\n");
    PostorderBalancedBST(bst->root, printData, stdout);
    printf("\n");
    PrintBalancedBST(bst->root, 0, printData, stdout);
    printf("Height of the three: %d\n", HeightBalancedBST(bst->root));
    elements[10]->data = 3;
    BalancedBST *found = SearchBalancedBSTItem(bst->root, elements[10], cmpFunct);
    if (found == NULL){
        printf("\nElement %d not found!\n", elements[10]->data);
    }
    else {
        printf("\nElement %d found!\n", elements[10]->data);
        printf("The height of this element is %d\n", nodeHeight(found));
    }
    BalancedBST *minVal1 = findMin(bst->root, cmpFunct);
    if (minVal1 == NULL) {
        printf("\nMin value not found\n");
    }
    else {
        printf("\nMin value is: %d\n", ((ELEMENT*)minVal1->element)->data);
    }
    BalancedBST *maxVal = findMax(bst->root, cmpFunct);
    if (maxVal == NULL) {
        printf("Min value not found\n");
    }
    else {
        printf("Min value is: %d\n", ((ELEMENT*)maxVal->element)->data);
    }
    elements[11]->data = 6;
    if (SearchBalancedBSTItem(bst->root, elements[11], cmpFunct) != NULL){
        bst->root = DeleteBalancedBSTItem(bst->root, elements[11], cmpFunct);
        balance(bst->root);
        PrintBalancedBST(bst->root, 0, printData, stdout);
        printf("\nHeight of the three: %d\n", HeightBalancedBST(bst->root));
        printf("\n.................\n");
    }
    else{
        printf("Element %d not found!\n", elements[11]->data);
    }
    BalancedTree *bst1 = CreateBalancedBST();
    elements[13]->data = 2;
    elements[14]->data = 4;
    elements[15]->data = 9;
    elements[16]->data = 3;
    elements[17]->data = 6;
    elements[18]->data = 8;
    elements[19]->data = 0;
    for (int i = 13; i < 20; i++) {
        bst1->root = AddBalancedBSTItem(bst1->root, elements[i], cmpFunct);
        balance(bst1->root);
    }
    PreorderBalancedBST(bst1->root, printData, stdout);
    printf("\n..................\n");
    PrintBalancedBST(bst1->root, 0, printData, stdout);
    printf("\nHeight of the three: %d\n", HeightBalancedBST(bst->root));
    printf("\n..................\n");
    BalancedTree *bst2 = CreateBalancedBST();
    bst2->root = MergeBalancedBSTs(bst->root, bst1->root, cmpFunct);
    balance(bst2->root);
    PrintBalancedBST(bst2->root, 0, printData, stdout);
    printf("\nHeight of the three: %d\n", HeightBalancedBST(bst->root));
    BalancedTree *bst3 = CreateBalancedBST();
    bst3->root = MergeBalancedBSTs(bst1->root, bst->root, cmpFunct);
    DeleteBalancedBST(bst, cmpFunct);
    DeleteBalancedBST(bst1, cmpFunct);
    DeleteBalancedBST(bst2, cmpFunct);
    return 0;
}