//
// Created by lilla on 20/01/17.
//

#include "BST.h"

TREE *CreateBST() {
    TREE *bst = calloc(1, sizeof(TREE));
    bst->nrOfElements = 0;
    bst->root = 0;
    return bst;
}

BST *createNode(void *element) {
    BST *node = calloc(1, sizeof(BST));
    node->left = NULL;
    node->right = NULL;
    node->element = element;
    return node;
}

BST *AddBSTItem(BST *node, void *element, int (*cmpFunct)(void *a, void *b)) {
   if (node == NULL){
       return createNode(element);
   }
    else {
       if (cmpFunct(element, node->element) < 0) {
           node->left = AddBSTItem(node->left, element, cmpFunct);
       }
       else { //allows duplicates
           node->right = AddBSTItem(node->right, element, cmpFunct);
       }
       return node;
   }
}

void PreorderBST(BST *node, void(*printData)(void *a, FILE *f), FILE *f) {
    if (node == NULL) {
        return;
    }
    printData(node->element, f);
    PreorderBST(node->left, printData, f);
    PreorderBST(node->right, printData, f);
}

void PrintBST(BST *node, int level, void(*printData)(void *a, FILE *f), FILE *f){
    if (node == NULL) {
        return;
    }
    PrintBST(node->right, level + 1, printData, f);
    for (int i = 0; i < level; i++){
        fprintf(f, "   ");
    }
    printData(node->element, f);
    fprintf(f, "\n");
    PrintBST(node->left, level + 1, printData, f);
}

