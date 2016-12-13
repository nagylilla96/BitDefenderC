//
// Created by lilla on 13/12/16.
//

#ifndef L07_E03_E03_H
#define L07_E03_E03_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size;
int size2;

typedef struct {
    int id;
    char *nume;
} curs;

typedef struct {
    char *nume;
    char *nrMatricol;
    curs **course;
} stud;

void new_student(stud *student, int nrOfStud, curs *course, int nrOfCurs);
int deleteStud(stud *student, int nrOfStud);
int findStudName(stud *student, int nrOfStud);
int findNrMatricol(stud *student, int nrOfStud, curs *course, int nrOfCurs);
int modifyStud(stud *student, int nrOfStud);
void sortByStudName(stud *student, int nrOfStud);
void sortByStudNr(stud *student, int nrOfStud);
void showStud(stud *student, int nrOfStud);
void new_course(curs *course, int nrOfCurs, stud *student, int nrOfStud);
int deleteCurs(curs *course, int nrOfCurs, stud *student, int nrOfStud);
int modifyCurs(curs *course, int nrOfCurs);
int findID(stud *student, int nrOfStud, curs *course, int nrOfCurs);
void showCurs(curs *course, int nrOfCurs);
void addStudToCurs(stud *student, curs *course, int nrOfStud, int nrOfCurs);
int removeStudFromCurs(stud *student, curs *course, int nrOfStud, int nrOfCurs);

#endif //L07_E03_E03_H
