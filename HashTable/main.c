#include "HashTable.h"

typedef struct {
    int key;
    char *value;
}ELEMENT;

ELEMENT *createElement(int key, char* value){
    value = calloc(100, sizeof(char));
    ELEMENT *element = calloc(1, sizeof(ELEMENT));
    element->key = key;
    element->value = value;
    return element;
}

int cmpFunct(void *a, void *b) {
    ELEMENT *aa = (ELEMENT*) a;
    ELEMENT *bb = (ELEMENT*) b;
    if (aa->key > bb->key) {
        return 1;
    }
    else {
        if (aa->key == bb->key) {
            if (strcmp(aa->value, bb->value) > 0) {
                return 1;
            }
            else {
                if (strcmp(aa->value, bb->value) == 0) {
                    return 0;
                }
                else {
                    return -1;
                }
            }
        }
        else {
            return -1;
        }
    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}