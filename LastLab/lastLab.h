//
// Created by lilla on 11/01/17.
//

#ifndef LASTLAB_LASTLAB_H
#define LASTLAB_LASTLAB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
    struct NODE **next;
}NODE;

NODE **createTrie();
char **readFile();
void addWord(char *word, NODE **root);
void addFile(char **listOfStrings, NODE** root);
int searchCompleteWord(char *word, NODE **root);
int printListOfStrings(char **listOfStrings);
int nrOfWords(char **listOfStrings);

#endif //LASTLAB_LASTLAB_H
