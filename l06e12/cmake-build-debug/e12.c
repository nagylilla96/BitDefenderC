//
// Created by lilla on 14/12/16.
//

#include "e12.h"

int evaluateExpression(char *expression, LINE *block) {
    int i, x = 0, result = 0, nextIsMinus = 0;
    char *number;
    number = malloc(sizeof(char) * 30);
    for (i = 0; i < strlen(expression); i++) {
        if (expression[i] == '+') {
            if (nextIsMinus == 0) {
                result += atoi(number);
            }
            else {
                result -= atoi(number);
            }
            x = 0;
            memset(number, '\0', 30);
            nextIsMinus = 0;
        }
        else {
            if (expression[i] == '-') {
                if (nextIsMinus == 0) {
                    result += atoi(number);
                }
                else {
                    result -= atoi(number);
                }
                memset(number, '\0', 30);
                nextIsMinus = 1;
                x = 0;
            }
            else {
                number[x] = expression[i];
                x++;
            }
        }
    }
    if (nextIsMinus) {
        result -= atoi(number);
    }
    else {
        result += atoi(number);
    }
    return result;
}

void populateStruct(char *line, LINE *block, int *nrOfEx) {
    int i, x = 0;
    char *expression;
    expression = malloc(sizeof(char) * 200);
    for (i = 0; i < strlen(line); i++) {
        if (line[i] != ';') {
            expression[x] = line[i];
            x++;
        }
        else {
            printf("expression = %s\n", expression);
            block[*nrOfEx].expression = malloc(sizeof(char) * 200);
            strcpy(block[*nrOfEx].expression, expression);
            block[*nrOfEx].result = evaluateExpression(expression, block);
            x = 0;
            memset(expression, '\0', 200);
            (*nrOfEx)++;
        }
    }
}

int readFile(FILE *f, int n, LINE *block) {
    int i, nrOfEx = 0;
    char *line;
    line = malloc(sizeof(char) * 1000);
    for (i = 0; i < n; i++) {
        fscanf(f, "%s", line);
        printf("%s\n", line);
        populateStruct(line, block, &nrOfEx);
    }
    return nrOfEx;
}

void sortStruct(LINE *block, int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (block[j].result > block[j + 1].result) { // if the numbers are not in the right order
                LINE temp = block[j]; // we change the structure element's orders
                block[j] = block[j + 1]; //note: I considered that nr matricol is always 10 digits long (so the length
                block[j + 1] = temp; // doesn't differ, otherwise the comparison wouldn't be correct)
            }
        }
    }
    showResults(block);
}

void showResults(LINE *block) {
    int i = 0;
    while (block[i].expression != NULL) {
        printf("\nexpression: %s\n", block[i].expression);
        printf("result: %d\n", block[i].result);
        i++;
    }
}

void writeResults(FILE *f, LINE *block, int n) {
    rewind(f);
    fwrite(block, sizeof(block), n, f);
}