//
// Created by lilla on 13/12/16.
//

#ifndef L07_E03_E03_H
#define L07_E03_E03_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size;

typedef struct {
    char *nume;
    char *nrMatricol;
} stud;

typedef struct {
    int id;
    char *nume;
} curs;

void new_student(stud *student, int nrOfStud);
int deleteStud(stud *student, int nrOfStud);
int findStudName(stud *student, int nrOfStud);
int findNrMatricol(stud *student, int nrOfStud);
int modifyStud(stud *student, int nrOfStud);
void sortByStudName(stud *student, int nrOfStud);
void sortByStudNr(stud *student, int nrOfStud);
void showStud(stud *student, int nrOfStud);

#endif //L07_E03_E03_H
