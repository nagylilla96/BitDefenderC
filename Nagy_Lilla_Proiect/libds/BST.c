//
// Created by lilla on 20/01/17.
//

#include "BST.h"

TREE *CreateBST() { // allocate space for a BST and return it
    TREE *bst = calloc(1, sizeof(TREE));
    bst->root = NULL;
    return bst;
}

BST *createNode(void *element) { //allocate space for a node, initialize and return it
    BST *node = calloc(1, sizeof(BST));
    node->left = NULL;
    node->right = NULL;
    node->element = element;
    return node;
}

BST *AddBSTItem(BST *node, void *element, int (*cmpFunct)(void *a, void *b)) { //add an item to the tree
    if (node == NULL){ // if empty, create node
        return createNode(element);
    }
    else {
        if (cmpFunct(element, node->element) < 0) { // if new element is smaller than other node, go left
            node->left = AddBSTItem(node->left, element, cmpFunct);
        }
        else { //allows duplicates
            node->right = AddBSTItem(node->right, element, cmpFunct); // else go right
        }
        return node; //and return node
    }
}

BST *copyTree(BST *node) { // get a tree and return its copy
    if (node == NULL) {
        return NULL;
    }
    BST *temp = calloc(1, sizeof(BST));
    temp->element = node->element;
    temp->left = copyTree(node->left);
    temp->right = copyTree(node->right);
    return temp;
}

void PreorderBST(BST *node, void(*printData)(void *a, FILE *f), FILE *f) { // print the nodes preorder
    if (node == NULL) {
        return;
    }
    printData(node->element, f);
    PreorderBST(node->left, printData, f);
    PreorderBST(node->right, printData, f);
}

void InorderBST(BST *node, void(*printData)(void *a, FILE *f), FILE *f) { // prints the nodes inorder
    if (node == NULL){
        return;
    }
    InorderBST(node->left, printData, f);
    printData(node->element, f);
    InorderBST(node->right, printData, f);
}

void PostorderBST(BST *node, void(*printData)(void *a, FILE *f), FILE *f){ // prints the nodes postorder
    if (node == NULL){
        return;
    }
    PostorderBST(node->left, printData, f);
    PostorderBST(node->right, printData, f);
    printData(node->element, f);
}

void PrintBST(BST *node, int level, void(*printData)(void *a, FILE *f), FILE *f){ // prints the tree in tree form
    if (node == NULL) {
        return;
    }
    PrintBST(node->right, level + 1, printData, f);
    for (int i = 0; i < level; i++){
        fprintf(f, "   "); // number of spaces: 3 * level
    }
    printData(node->element, f);
    fprintf(f, "\n");
    PrintBST(node->left, level + 1, printData, f);
}

BST *SearchBSTItem(BST *node, void *element, int(*cmpFunct)(void *a, void *b)) { // search a node
    if (node == NULL){
        return NULL; // if tree is empty, return null
    }
    if (cmpFunct(node->element, element) == 0) {
        return node; // if found, return node
    }
    if (cmpFunct(node->element, element) > 0) { // if node is bigger than searched one, go left
        return SearchBSTItem(node->left, element, cmpFunct);
    }
    return SearchBSTItem(node->right, element, cmpFunct); // else go right
}

BST *findMin(BST *node, int(*cmpFunct)(void *a, void *b)){ // find the smallest node by going left
    if (node == NULL) {
        return NULL;
    }
    if (node->left == NULL) {
        return node;
    }
    return findMin(node->left, cmpFunct);
}

BST *findMax(BST *node, int(*cmpFunct)(void *a, void *b)) { // find the biggest node by going right
    if (node == NULL){
        return NULL;
    }
    if (node->right == NULL) {
        return node;
    }
    return findMax(node->right, cmpFunct);
}

BST *DeleteBSTItem(BST *node, void *element, int(*cmpFunct)(void *a, void *b)) { // delete an item
    BST *temp;
    if (node == NULL) {
        return NULL;
    }
    if (cmpFunct(element, node->element) < 0) { //if element < node->element, go left
        node->left = DeleteBSTItem(node->left, element, cmpFunct);
    }
    else {
        if (cmpFunct(element, node->element) > 0) { // else go right
            node->right = DeleteBSTItem(node->right, element, cmpFunct);
        }
        else {
            if (node->right && node->left) { //if we got it, and it has its both children, delete it, replace it with
                temp = findMin(node->right, cmpFunct); // its smallest node, and delete it
                node->element = temp->element;
                node->right = DeleteBSTItem(node->right, temp->element, cmpFunct);
            }
            else {
                temp = node; // if it has only a right child, go right
                if (node->left == NULL){
                    node = node->right;
                }
                else {
                    if (node->right == NULL){ // else go left
                        node = node->left;
                    }
                }
                free(temp); // free temp
            }
        }
    }
    return node; // return the node
}

BST *MergeBSTs(BST *root1, BST *root2, int(*cmpFunct)(void *a, void *b)){ // merge two nodes
    BST *root3 = copyTree(root1); //by copying them and putting all the elements from one into the other
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

int HeightBST(BST *node){ // return the height of the BST
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

void DeleteBST(TREE *bst, int(*cmpFunct)(void *a, void *b)) { //delete a BST completely
    while (findMin(bst->root, cmpFunct) != NULL) {
        bst->root = DeleteBSTItem(bst->root, bst->root->element, cmpFunct); //each element and then
    }
    free(bst); // the tree node
}