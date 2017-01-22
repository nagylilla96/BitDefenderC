//
// Created by lilla on 21/01/17.
//

#include "BalancedBST.h"

BalancedTree *CreateBalancedBST() {
    BalancedTree *bst = calloc(1, sizeof(BalancedTree));
    bst->root = NULL;
    return bst;
}

BalancedBST *createNode(void *element) {
    BalancedBST *node = calloc(1, sizeof(BalancedBST));
    node->left = NULL;
    node->right = NULL;
    node->element = element;
    return node;
}

BalancedBST *AddBalancedBSTItem(BalancedBST *node, void *element, int (*cmpFunct)(void *a, void *b)) {
    if (node == NULL)
        return createNode(element);
    if (cmpFunct(element, node->element) < 0)
        node->left = AddBalancedBSTItem(node->left, element, cmpFunct);
    else node->right = AddBalancedBSTItem(node->right, element, cmpFunct);

    int balance = balanceFactor(node);
    if (balance > 1 && cmpFunct(element, node->left->element) < 0){
        return rightRotate(node);
    }
    if (balance < -1 && cmpFunct(element, node->right->element) > 0) {
        return leftRotate(node);
    }
    if (balance > 1 && cmpFunct(element, node->left->element) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && cmpFunct(element, node->right->element) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;

}

void PreorderBalancedBST(BalancedBST *node, void(*printData)(void *a, FILE *f), FILE *f) {
    if (node == NULL) {
        return;
    }
    printData(node->element, f);
    PreorderBalancedBST(node->left, printData, f);
    PreorderBalancedBST(node->right, printData, f);
}

void InorderBalancedBST(BalancedBST *node, void(*printData)(void *a, FILE *f), FILE *f) {
    if (node == NULL){
        return;
    }
    InorderBalancedBST(node->left, printData, f);
    printData(node->element, f);
    InorderBalancedBST(node->right, printData, f);
}

void PostorderBalancedBST(BalancedBST *node, void(*printData)(void *a, FILE *f), FILE *f){
    if (node == NULL){
        return;
    }
    PostorderBalancedBST(node->left, printData, f);
    PostorderBalancedBST(node->right, printData, f);
    printData(node->element, f);
}

void PrintBalancedBST(BalancedBST *node, int level, void(*printData)(void *a, FILE *f), FILE *f){
    if (node == NULL) {
        return;
    }
    PrintBalancedBST(node->right, level + 1, printData, f);
    for (int i = 0; i < level; i++){
        fprintf(f, "   ");
    }
    printData(node->element, f);
    fprintf(f, "\n");
    PrintBalancedBST(node->left, level + 1, printData, f);
}

BalancedBST *SearchBalancedBSTItem(BalancedBST *node, void *element, int(*cmpFunct)(void *a, void *b)) {
    if (node == NULL){
        return NULL;
    }
    if (cmpFunct(node->element, element) == 0) {
        return node;
    }
    if (cmpFunct(node->element, element) > 0) {
        return SearchBalancedBSTItem(node->left, element, cmpFunct);
    }
    return SearchBalancedBSTItem(node->right, element, cmpFunct);
}

BalancedBST *findMin(BalancedBST *node, int(*cmpFunct)(void *a, void *b)){
    if (node == NULL) {
        return NULL;
    }
    if (node->left == NULL) {
        return node;
    }
    return findMin(node->left, cmpFunct);
}

BalancedBST *findMax(BalancedBST *node, int(*cmpFunct)(void *a, void *b)) {
    if (node == NULL){
        return NULL;
    }
    if (node->right == NULL) {
        return node;
    }
    return findMax(node->right, cmpFunct);
}

int nodeHeight(BalancedBST *node) {
    int left = 0;
    int right = 0;
    if (node == NULL){
        return 0;
    }
    if (node->left) {
        left = nodeHeight(node->left);
    }
    if (node->right) {
        left = nodeHeight(node->right);
    }
    if (right > left){
        right++;
        return right;
    }
    left++;
    return left;
}

int balanceFactor(BalancedBST *node) {
    if (node == NULL) {
        return 0;
    }
    return (nodeHeight(node->left) - nodeHeight(node->right));
}

BalancedBST *rightRotate(BalancedBST *node) {
    BalancedBST *x = node->left;
    BalancedBST *y = x->right;

    x->right = node;
    node->left = y;

    return x;
}

BalancedBST *leftRotate(BalancedBST *node) {
    BalancedBST *x = node->right;
    BalancedBST *y = x->left;

    x->left = node;
    node->right = y;

    return x;
}

//BalancedBST *balanceNode(BalancedBST *node) {
//    BalancedBST *temp = NULL;
//    int balance;
//    if (node->left) {
//        node->left = balanceNode(node->left);
//    }
//    if (node->right) {
//        node->right = balanceNode(node->right);
//    }
//    balance = balanceFactor(node);
//    if (balance >= 2) {
//        if (balanceFactor(node->left) <= -1) {
//            temp = rotateLeftRight(node);
//        }
//        else {
//            temp = rotateLeftLeft(node);
//        }
//    }
//    else {
//        if (balance <= -2){
//            if (balanceFactor(node->right) >= 1){
//                temp = rotateRightLeft(node);
//            }
//            else {
//                temp = rotateRightRight(node);
//            }
//        }
//        else {
//            temp = node;
//        }
//    }
//    return temp;
//}

//void balance(BalancedBST *root) {
//    BalancedBST *node;
//    node = balanceNode(root);
//    if (node != root) {
//        root = node;
//    }
//}

BalancedBST *DeleteBalancedBSTItem(BalancedBST *node, void *element, int(*cmpFunct)(void *a, void *b)) {
    BalancedBST *temp;
    if (node == NULL) {
        return NULL;
    }
    if (cmpFunct(element, node->element) < 0) {
        node->left = DeleteBalancedBSTItem(node->left, element, cmpFunct);
    }
    else {
        if (cmpFunct(element, node->element) > 0) {
            node->right = DeleteBalancedBSTItem(node->right, element, cmpFunct);
        }
        else {
            if (node->right && node->left) {
                temp = findMin(node->right, cmpFunct);
                node->element = temp->element;
                node->right = DeleteBalancedBSTItem(node->right, temp->element, cmpFunct);
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
    if (node == NULL){
        return node;
    }
    int balance = balanceFactor(node);
    if (balance > 1 && balanceFactor(node->left) >= 0){
        return rightRotate(node);
    }
    if (balance > 1 && balanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && balanceFactor(node->right) <= 0){
        return leftRotate(node);
    }
    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

BalancedBST *copyTree(BalancedBST *node) {
    if (node == NULL) {
        return NULL;
    }
    BalancedBST *temp = calloc(1, sizeof(BalancedBST));
    temp->element = node->element;
    temp->left = copyTree(node->left);
    temp->right = copyTree(node->right);
    return temp;
}

BalancedBST *MergeBalancedBSTs(BalancedBST *root1, BalancedBST *root2, int(*cmpFunct)(void *a, void *b)){
    BalancedBST *root3 = copyTree(root1);
    BalancedBST *root4 = copyTree(root2);
    BalancedBST *min = findMin(root4, cmpFunct);
    while (min != NULL){
        root3 = AddBalancedBSTItem(root3, min->element, cmpFunct);
        root4 = DeleteBalancedBSTItem(root4, min->element, cmpFunct);
        min = findMin(root4, cmpFunct);
    }
    free(root4);
    return root3;
}

int HeightBalancedBST(BalancedBST *node){
    if (node == NULL){
        return 0;
    }
    int left = HeightBalancedBST(node->right);
    int right = HeightBalancedBST(node->left);
    if (left > right) {
        return (left + 1);
    }
    return (right + 1);
}

void DeleteBalancedBST(BalancedTree *bst, int(*cmpFunct)(void *a, void *b)) {
    while (findMin(bst->root, cmpFunct) != NULL) {
        bst->root = DeleteBalancedBSTItem(bst->root, bst->root->element, cmpFunct);
    }
    free(bst);
}