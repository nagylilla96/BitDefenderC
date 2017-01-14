//
// Created by lilla on 14/01/17.
//

#include "tester.h"


void runTester(char **file) {
    FILE *f;
    f = fopen(file, "r");

    fclose(f);
}