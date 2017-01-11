//
// Created by lilla on 11/01/17.
//

#ifndef LASTLAB_LASTLAB_H
#define LASTLAB_LASTLAB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    struct node *next;
}NODE;

NODE **createTrie();
char **readFile();
void addWord(char *word, NODE **root);
void addFile(char **listOfStrings, NODE** root);
int searchCompleteWord(char *word, NODE **root);

#endif //LASTLAB_LASTLAB_H
