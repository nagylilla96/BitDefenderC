//
// Created by lilla on 11/01/17.
//

#include "lastLab.h"

NODE **createTrie() {

    int i;
    NODE **list = malloc(sizeof(NODE)*100);
    for (i = 0; i < 26; i++) {
        list[i] = malloc(sizeof(NODE)*26);
        list[i]->next = NULL;
    }
    return list;
}

char **readFile() {
    FILE *f;
    int size = 100, i;
    char *word = malloc(sizeof(char) * 100);
    f = fopen("in.txt", "r");
    char **listOfString = malloc(sizeof(char*) * size);
    for (i = 0; i < size; i++) {
        listOfString[i] = malloc(sizeof(char) * 100);
    }
    i = 0;
    if (f == NULL){
        printf("File doesn't exist\n");
        return NULL;
    }
    while (fgets(word, 100, f) != NULL) {
        strcpy(listOfString[i], word);
        i++;
    }
    fclose(f);
    return listOfString;
}

void addWord(char *word, NODE **root) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (root[word[i] - 97]->next == NULL) {
            root[word[i] - 97]->next = createTrie();

            if (root[word[i] - 97]->next == NULL) {
                printf("Root is null!\n");
            }
        }
        root[word[i] - 97] = (NODE *) root[word[i] - 97] -> next;
    }
}

int printListOfStrings(char **listOfStrings) {
    int i = 0;
    while (strlen(listOfStrings[i]) != 0) {
        listOfStrings[i][strlen(listOfStrings[i]) - 1] = '\0';
//        printf("%s\n", listOfStrings[i]);
        i++;
    }
    return i - 1;
}

void addFile(char **listOfStrings, NODE** root) {
    int i = 0;
    while (strlen(listOfStrings[i]) != 0) {
        addWord(listOfStrings[i], root);
        i++;
    }
}

int searchCompleteWord(char *word, NODE **root) {
    printf("SearchCompleteWord entered\n");
    int i = 0;
    while (i < strlen(word)) {
        printf("%c", root[word[i]]);
        if (root[word[i] - 97]->next == NULL) {
            return 0;
        }
        root[word[i] - 97] = (NODE *) root[word[i] - 97] -> next;
        i++;
    }
    return 1;
}

int nrOfWords(char **listOfStrings) {
    return printListOfStrings(listOfStrings);
}



