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

    NODE **anotherRoot = root;
    if (anotherRoot == NULL) {
        printf("AnotherRoot is null\n");
    }

    for (i = 0; i < strlen(word); i++) {
        if (anotherRoot[word[i] - 97]->next == NULL) {
            anotherRoot[word[i] - 97]->next = createTrie();
            if (anotherRoot[word[i] - 97]->next == NULL) {
                printf("Root is null!\n");
            }
        }
        anotherRoot[word[i] - 97] = anotherRoot[word[i] - 97] -> next;
    }
    printf("Addword entered\n");
}

void addFile(char **listOfStrings, NODE** root) {
    int i = 0;

    while (strlen(listOfStrings[i]) != 0) {
        printf("Addfile entered\n");
        addWord(listOfStrings[i], root);
        i++;
    }

}

int searchCompleteWord(char *word, NODE **root) {
    int i = 0, found = 1;
    while (i < strlen(word)) {
        if (root[word[i] - 97]->next == NULL) {
            return 0;
        }
        root[word[i] - 97] = root[word[i] - 97] -> next;
        i++;
    }
    return 1;
}



