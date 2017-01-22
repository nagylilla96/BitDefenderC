//
// Created by lilla on 21/01/17.
//

#include "BalancedBST.h"

BalancedTree *CreateBalancedBST() { //create and return a new balanced binary search tree
    BalancedTree *bst = calloc(1, sizeof(BalancedTree));
    bst->root = NULL;
    return bst;
}

BalancedBST *createNode(void *element) { //create a new node and return it + allocate space to it
    BalancedBST *node = calloc(1, sizeof(BalancedBST));
    node->left = NULL;
    node->right = NULL;
    node->element = element;
    return node;
}

BalancedBST *AddBalancedBSTItem(BalancedBST *node, void *element, int (*cmpFunct)(void *a, void *b)) { //add a new intem
    if (node == NULL) // if node is null, list is empty -> create new root
        return createNode(element);
    if (cmpFunct(element, node->element) < 0) //if the element is smaller than its parent, add it to its left
        node->left = AddBalancedBSTItem(node->left, element, cmpFunct);
    else node->right = AddBalancedBSTItem(node->right, element, cmpFunct); // otherwise add it to its right

    int balance = balanceFactor(node); // gets the balance factor of a node
    if (balance > 1 && cmpFunct(element, node->left->element) < 0){  // right rotate
        return rightRotate(node);
    }
    if (balance < -1 && cmpFunct(element, node->right->element) > 0) { // left rotate
        return leftRotate(node);
    }
    if (balance > 1 && cmpFunct(element, node->left->element) > 0) { // left right rotate
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && cmpFunct(element, node->right->element) < 0) { // right left rotate
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node; //return node

}

void PreorderBalancedBST(BalancedBST *node, void(*printData)(void *a, FILE *f), FILE *f) { //print nodes in priorder
    if (node == NULL) {
        return;
    }
    printData(node->element, f);
    PreorderBalancedBST(node->left, printData, f);
    PreorderBalancedBST(node->right, printData, f);
}

void InorderBalancedBST(BalancedBST *node, void(*printData)(void *a, FILE *f), FILE *f) { //print nodes inorder
    if (node == NULL){
        return;
    }
    InorderBalancedBST(node->left, printData, f);
    printData(node->element, f);
    InorderBalancedBST(node->right, printData, f);
}

void PostorderBalancedBST(BalancedBST *node, void(*printData)(void *a, FILE *f), FILE *f){ //print nodes postorder
    if (node == NULL){
        return;
    }
    PostorderBalancedBST(node->left, printData, f);
    PostorderBalancedBST(node->right, printData, f);
    printData(node->element, f);
}

void PrintBalancedBST(BalancedBST *node, int level, void(*printData)(void *a, FILE *f), FILE *f){ // print BST in tree form
    if (node == NULL) {
        return;
    }
    PrintBalancedBST(node->right, level + 1, printData, f);
    for (int i = 0; i < level; i++){
        fprintf(f, "   "); // print spaces based on the level
    }
    printData(node->element, f);
    fprintf(f, "\n");
    PrintBalancedBST(node->left, level + 1, printData, f);
}

BalancedBST *SearchBalancedBSTItem(BalancedBST *node, void *element, int(*cmpFunct)(void *a, void *b)) { // search a BST node
    if (node == NULL){
        return NULL; // if root is null, return null
    }
    if (cmpFunct(node->element, element) == 0) { // if the node is found return it
        return node;
    }
    if (cmpFunct(node->element, element) > 0) {// if the node is smaller than out current node, go left
        return SearchBalancedBSTItem(node->left, element, cmpFunct);
    }
    return SearchBalancedBSTItem(node->right, element, cmpFunct); // else go right (If nothing goes left... go right?)
}

BalancedBST *findMin(BalancedBST *node, int(*cmpFunct)(void *a, void *b)){ // find the smallest node of the tree
    if (node == NULL) {
        return NULL; // if empty, return null..
    }
    if (node->left == NULL) { // we always go left, if we can't, we return the node
        return node;    //no, we don't need a compare function for this, but I realised it too late, so we have it
    }
    return findMin(node->left, cmpFunct);
}

BalancedBST *findMax(BalancedBST *node, int(*cmpFunct)(void *a, void *b)) { //find the biggest node of the tree
    if (node == NULL){ //same principle, but we go right
        return NULL;
    }
    if (node->right == NULL) {
        return node;
    }
    return findMax(node->right, cmpFunct);
}

int nodeHeight(BalancedBST *node) { //get a certain node's height
    int left = 0;
    int right = 0;
    if (node == NULL){
        return 0;
    }
    if (node->left) { // if we can go left, go left
        left = nodeHeight(node->left);
    }
    if (node->right) { // if we can go right, go right
        left = nodeHeight(node->right);
    }
    if (right > left){ // if right is bigger, we increment it
        right++;
        return right;
    }
    left++; // otherwise we increment left and return it
    return left;
}

int balanceFactor(BalancedBST *node) { // find a node's balance factor based on the difference of left and right
    if (node == NULL) { //children heights
        return 0;
    }
    return (nodeHeight(node->left) - nodeHeight(node->right));
}

BalancedBST *rightRotate(BalancedBST *node) { // rotate a node right
    BalancedBST *x = node->left;
    BalancedBST *y = x->right;

    x->right = node;
    node->left = y;

    return x;
}

BalancedBST *leftRotate(BalancedBST *node) { //rotate a node left
    BalancedBST *x = node->right;
    BalancedBST *y = x->left;

    x->left = node;
    node->right = y;

    return x;
}

BalancedBST *DeleteBalancedBSTItem(BalancedBST *node, void *element, int(*cmpFunct)(void *a, void *b)) {
    BalancedBST *temp; // delete a node
    if (node == NULL) {
        return NULL; // tree is empty...
    }
    if (cmpFunct(element, node->element) < 0) { // if element is smaller than the node's element
        node->left = DeleteBalancedBSTItem(node->left, element, cmpFunct); //go left
    }
    else {
        if (cmpFunct(element, node->element) > 0) {
            node->right = DeleteBalancedBSTItem(node->right, element, cmpFunct); // else go right
        }
        else {
            if (node->right && node->left) { // we found it! it has two children
                temp = findMin(node->right, cmpFunct);
                node->element = temp->element;
                node->right = DeleteBalancedBSTItem(node->right, temp->element, cmpFunct); // delete it! (recursion)
            }
            else {
                temp = node;
                if (node->left == NULL){ // left is null
                    node = node->right; // so we take right
                }
                else {
                    if (node->right == NULL){ // we take left
                        node = node->left;
                    }
                }
                free(temp); //free temp
            }
        }
    }
    if (node == NULL){
        return node; // tree is empty...
    }
    int balance = balanceFactor(node); // get balance factor
    if (balance > 1 && balanceFactor(node->left) >= 0){ // right rotate
        return rightRotate(node);
    }
    if (balance > 1 && balanceFactor(node->left) < 0) {// left right rotate
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && balanceFactor(node->right) <= 0){ // left rotate
        return leftRotate(node);
    }
    if (balance < -1 && balanceFactor(node->right) > 0) { // right left rotate
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

BalancedBST *copyTree(BalancedBST *node) { //take a tree (by root) and return a copy of it
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
    BalancedBST *root3 = copyTree(root1); // create copies of the threes
    BalancedBST *root4 = copyTree(root2); // and then merge them
    BalancedBST *min = findMin(root4, cmpFunct); // always delete the smallest element of the second three
    while (min != NULL){ // and add it to the first
        root3 = AddBalancedBSTItem(root3, min->element, cmpFunct);
        root4 = DeleteBalancedBSTItem(root4, min->element, cmpFunct);
        min = findMin(root4, cmpFunct);
    }
    free(root4);
    return root3;
}

int HeightBalancedBST(BalancedBST *node){ // return the height of the tree
    if (node == NULL){
        return 0;
    }
    int left = HeightBalancedBST(node->right); // we go left
    int right = HeightBalancedBST(node->left); // and right
    if (left > right) {
        return (left + 1); // and always return the biggest value
    }
    return (right + 1);
}

void DeleteBalancedBST(BalancedTree *bst, int(*cmpFunct)(void *a, void *b)) { //delete the tree
    while (findMin(bst->root, cmpFunct) != NULL) { //each element, and then free the tree pointer
        bst->root = DeleteBalancedBSTItem(bst->root, bst->root->element, cmpFunct);
    }
    free(bst);
}