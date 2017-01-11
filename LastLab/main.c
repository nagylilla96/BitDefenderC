#include "lastLab.h"

int main() {

    NODE **root = createTrie();
    if (root == NULL) {
        printf("Root is null\n");
    }
    char **listOfStrings = readFile();
    if (listOfStrings == NULL) {
        printf("List of strings is null\n");
    }
    printListOfStrings(listOfStrings);
    addFile(listOfStrings, root);
    if (searchCompleteWord("create", root)) {
        printf("create found\n");
    }
    else {
        printf("Create not found\n");
    }
    printf("Nr of words is: %d\n", nrOfWords(listOfStrings));
    return 0;
}