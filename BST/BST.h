//
// Created by lilla on 20/01/17.
//

#ifndef BST_BST_H
#define BST_BST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct bst{
    void *element;
    struct bst *left;
    struct bst *right;
}BST;

typedef struct {
    int nrOfElements;
    struct bst *root;
}TREE;

TREE *CreateBST();
BST *createNode(void *element);
BST *AddBSTItem(BST *node, void *element, int (*cmpFunct)(void *a, void *b));
void PreorderBST(BST *node, void(*printData)(void *a, FILE *f), FILE *f);
void PrintBST(BST *node, int level, void(*printData)(void *a, FILE *f), FILE *f);


#endif //BST_BST_H
