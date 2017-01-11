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
    addFile(listOfStrings, root);
    searchCompleteWord("create", root);
    return 0;
}