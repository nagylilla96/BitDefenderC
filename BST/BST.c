//
// Created by lilla on 20/01/17.
//

#include "BST.h"

TREE *CreateBST() {
    TREE *bst = calloc(1, sizeof(TREE));
    bst->root = NULL;
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

BST *copyTree(BST *node) {
    if (node == NULL) {
        return NULL;
    }
    BST *temp = calloc(1, sizeof(BST));
    temp->element = node->element;
    temp->left = copyTree(node->left);
    temp->right = copyTree(node->right);
    return temp;
}

void PreorderBST(BST *node, void(*printData)(void *a, FILE *f), FILE *f) {
    if (node == NULL) {
        return;
    }
    printData(node->element, f);
    PreorderBST(node->left, printData, f);
    PreorderBST(node->right, printData, f);
}

void InorderBST(BST *node, void(*printData)(void *a, FILE *f), FILE *f) {
    if (node == NULL){
        return;
    }
    InorderBST(node->left, printData, f);
    printData(node->element, f);
    InorderBST(node->right, printData, f);
}

void PostorderBST(BST *node, void(*printData)(void *a, FILE *f), FILE *f){
    if (node == NULL){
        return;
    }
    PostorderBST(node->left, printData, f);
    PostorderBST(node->right, printData, f);
    printData(node->element, f);
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

BST *SearchBSTItem(BST *node, void *element, int(*cmpFunct)(void *a, void *b)) {
    if (node == NULL){
        return NULL;
    }
    if (cmpFunct(node->element, element) == 0) {
        return node;
    }
    if (cmpFunct(node->element, element) > 0) {
        return SearchBSTItem(node->left, element, cmpFunct);
    }
    return SearchBSTItem(node->right, element, cmpFunct);
}

BST *findMin(BST *node, int(*cmpFunct)(void *a, void *b)){
    if (node == NULL) {
        return NULL;
    }
    if (node->left == NULL) {
        return node;
    }
    return findMin(node->left, cmpFunct);
}

BST *findMax(BST *node, int(*cmpFunct)(void *a, void *b)) {
    if (node == NULL){
        return NULL;
    }
    if (node->right == NULL) {
        return node;
    }
    return findMax(node->right, cmpFunct);
}

BST *DeleteBSTItem(BST *node, void *element, int(*cmpFunct)(void *a, void *b)) {
    BST *temp;
    if (node == NULL) {
        return NULL;
    }
    if (cmpFunct(element, node->element) < 0) {
        node->left = DeleteBSTItem(node->left, element, cmpFunct);
    }
    else {
        if (cmpFunct(element, node->element) > 0) {
            node->right = DeleteBSTItem(node->right, element, cmpFunct);
        }
        else {
            if (node->right && node->left) {
                temp = findMin(node->right, cmpFunct);
                node->element = temp->element;
                node->right = DeleteBSTItem(node->right, temp->element, cmpFunct);
            }
            else {
                temp = node;
                if (node->left == NULL){
                    node = node->right;
                }
                else {
                    if (node->right == NULL){
                        node = node->left;
                    }
                }
                free(temp);
            }
        }
    }
    return node;
}

BST *MergeBSTs(BST *root1, BST *root2, int(*cmpFunct)(void *a, void *b)){
    BST *root3 = copyTree(root1);
    BST *root4 = copyTree(root2);
    BST *min = findMin(root4, cmpFunct);
    while (min != NULL){
        root3 = AddBSTItem(root3, min->element, cmpFunct);
        root4 = DeleteBSTItem(root4, min->element, cmpFunct);
        min = findMin(root4, cmpFunct);
    }
    free(root4);
    return root3;
}

int HeightBST(BST *node){
    if (node == NULL){
        return 0;
    }
    int left = HeightBST(node->right);
    int right = HeightBST(node->left);
    if (left > right) {
        return (left + 1);
    }
    return (right + 1);
}

void DeleteBST(TREE *bst, int(*cmpFunct)(void *a, void *b)) {
    while (findMin(bst->root, cmpFunct) != NULL) {
        bst->root = DeleteBSTItem(bst->root, bst->root->element, cmpFunct);
    }
    free(bst);
}