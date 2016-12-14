//
// Created by lilla on 14/12/16.
//

#include "e12.h"

int main() {
    FILE *f, *g;
    int n, nrOfEx = 0;
    f = fopen("expresii.txt", "r");
    if (f == NULL) {
        printf("File not found\n");
    }
    printf("n = ");
    scanf("%d", &n);
    LINE *block = malloc(sizeof(block) * n * 14);
    nrOfEx = readFile(f, n, block);
    sortStruct(block, nrOfEx);
    g = fopen("rezultate.dat", "wb");
    if (g == NULL) {
        printf("Error, file not found\n");
    }
    writeResults(g, block, nrOfEx);
    fclose(f);
    fclose(g);
}