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
    struct bst *root;
}TREE;

TREE *CreateBST();
BST *createNode(void *element);
BST *AddBSTItem(BST *node, void *element, int (*cmpFunct)(void *a, void *b));
void PreorderBST(BST *node, void(*printData)(void *a, FILE *f), FILE *f);
void InorderBST(BST *node, void(*printData)(void *a, FILE *f), FILE *f);
void PostorderBST(BST *node, void(*printData)(void *a, FILE *f), FILE *f);
void PrintBST(BST *node, int level, void(*printData)(void *a, FILE *f), FILE *f);
BST *SearchBSTItem(BST *node, void *element, int(*cmpFunct)(void *a, void *b));
BST *findMin(BST *node, int(*cmpFunct)(void *a, void *b));
BST *findMax(BST *node, int(*cmpFunct)(void *a, void *b));
BST *DeleteBSTItem(BST *node, void *element, int(*cmpFunct)(void *a, void *b));
BST *MergeBSTs(BST *root1, BST *root2, int(*cmpFunct)(void *a, void *b));
int HeightBST(BST *node);
void DeleteBST(TREE *bst, int(*cmpFunct)(void *a, void *b));

#endif //BST_BST_H
