//
// Created by lilla on 21/01/17.
//

#ifndef BALANCEDBST_BALANCEDBST_H
#define BALANCEDBST_BALANCEDBST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct balanced{
    void *element;
    struct balanced *left;
    struct balanced *right;
}BalancedBST;

typedef struct {
    struct balanced *root;
}BalancedTree;

BalancedTree *CreateBalancedBST();
BalancedBST *createNode(void *element);
BalancedBST *AddBalancedBSTItem(BalancedBST *node, void *element, int (*cmpFunct)(void *a, void *b));
void PreorderBalancedBST(BalancedBST *node, void(*printData)(void *a, FILE *f), FILE *f);
void InorderBalancedBST(BalancedBST *node, void(*printData)(void *a, FILE *f), FILE *f);
void PostorderBalancedBST(BalancedBST *node, void(*printData)(void *a, FILE *f), FILE *f);
void PrintBalancedBST(BalancedBST *node, int level, void(*printData)(void *a, FILE *f), FILE *f);
BalancedBST *SearchBalancedBSTItem(BalancedBST *node, void *element, int(*cmpFunct)(void *a, void *b));
BalancedBST *findMin(BalancedBST *node, int(*cmpFunct)(void *a, void *b));
BalancedBST *findMax(BalancedBST *node, int(*cmpFunct)(void *a, void *b));
int nodeHeight(BalancedBST *node);
BalancedBST *DeleteBalancedBSTItem(BalancedBST *node, void *element, int(*cmpFunct)(void *a, void *b));
BalancedBST *MergeBalancedBSTs(BalancedBST *root1, BalancedBST *root2, int(*cmpFunct)(void *a, void *b));
int HeightBalancedBST(BalancedBST *node);
void DeleteBalancedBST(BalancedTree *bst, int(*cmpFunct)(void *a, void *b));


#endif //BALANCEDBST_BALANCEDBST_H
