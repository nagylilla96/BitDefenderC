//
// Created by lilla on 13/12/16.
//

#include "e03.h"

void new_student(stud *student, int nrOfStud) {
    char nume[200], nrMatricol[20];
    if (nrOfStud + 1 >= size) {
        size += size;
        student = realloc(student, sizeof(student) * (size));
    }
    printf("Nume: ");
    getchar();
    fgets(nume, 200, stdin);
    student[nrOfStud].nume = malloc(sizeof(char) * strlen(nume));
    strcpy(student[nrOfStud].nume, nume);
    printf("Numar matricol: ");
    fgets(nrMatricol, 20, stdin);
    student[nrOfStud].nrMatricol = malloc(sizeof(char) * strlen(nrMatricol));
    strcpy(student[nrOfStud].nrMatricol, nrMatricol);
}

int deleteStud(stud *student, int nrOfStud) {
    char nume[200];
    int i = 0, j;
    printf("Nume: ");
    getchar();
    fgets(nume, 200, stdin);
    while (i < nrOfStud) {
        if (strcmp(nume, student[i].nume) == 0)
        {
            nrOfStud--;
            for (j = i; j < nrOfStud; j++)
            {
                student[j] = student[j + 1];
            }
            return 1;
        }
        i++;
    }
    return 0;
}

int findStudName(stud *student, int nrOfStud) {
    char nume[200];
    int i = 0;
    printf("Nume: ");
    getchar();
    fgets(nume, 200, stdin);
    while (i < nrOfStud) {
        if (strcmp(nume, student[i].nume) == 0) {
            printf("Nume: %s", student[i].nume);
            printf("Numar matricol: %s", student[i].nrMatricol);
            return 1;
        }
        i++;
    }
    return 0;
}

int findNrMatricol(stud *student, int nrOfStud) {
    char nrMatricol[20];
    int i = 0;
    printf("Numar matricol: ");
    getchar();
    fgets(nrMatricol, 20, stdin);
    while (i < nrOfStud) {
        if (strcmp(nrMatricol, student[i].nrMatricol) == 0) {
            printf("Nume: %s", student[i].nume);
            printf("Numar matricol: %s", student[i].nrMatricol);
            return 1;
        }
        i++;
    }
    return 0;
}

int modifyStud(stud *student, int nrOfStud) {
    char nume[200], nrMatricol[20];
    int i = 0, found = 0;
    printf("Nume: ");
    getchar();
    fgets(nume, 200, stdin);
    while (i < nrOfStud) {
        if (strcmp(nume, student[i].nume) == 0) {
            printf("Nume: %s", student[i].nume);
            printf("Numar matricol: %s", student[i].nrMatricol);
            printf("Noul nume: ");
            getchar();
            fgets(nume, 200, stdin);
            strcpy(student[i].nume, nume);
            printf("Noul numar matricol: ");
            getchar();
            fgets(nrMatricol, 20, stdin);
            strcpy(student[i].nrMatricol, nrMatricol);
            return 1;
        }
        i++;
    }
    return 0;
}

void sortByStudName(stud *student, int nrOfStud) {
    int i, j, n = nrOfStud - 1;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (strcmp(student[j].nume, student[j + 1].nume) > 0) {
                stud temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    showStud(student, nrOfStud);
}

void sortByStudNr(stud *student, int nrOfStud) {
    int i, j, n = nrOfStud - 1;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (strcmp(student[j].nrMatricol, student[j + 1].nrMatricol) > 0) {
                stud temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    showStud(student, nrOfStud);
}

void showStud(stud *student, int nrOfStud) {
    int i;
    for (i = 0; i < nrOfStud; i++) {
        printf("Nume: %s", student[i].nume);
        printf("Numar matricol: %s", student[i].nrMatricol);
        printf("\n");
    }
}