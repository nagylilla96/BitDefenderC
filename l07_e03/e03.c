//
// Created by lilla on 13/12/16.
//

#include "e03.h"

void new_student(stud *student, int nrOfStud, curs *course, int nrOfCurs) { //add a new student
    char nume[200], nrMatricol[20];
    int i;
    if (nrOfStud + 1 >= size) {
        size += size;
        student = realloc(student, sizeof(student) * (size)); //if there are over 50 entries, reallocate space
    }
    printf("Nume: ");
    getchar();
    fgets(nume, 200, stdin);
    student[nrOfStud].nume = malloc(sizeof(char) * strlen(nume));
    strcpy(student[nrOfStud].nume, nume);
    printf("Numar matricol: "); //read values
    fgets(nrMatricol, 20, stdin);
    student[nrOfStud].nrMatricol = malloc(sizeof(char) * strlen(nrMatricol));
    strcpy(student[nrOfStud].nrMatricol, nrMatricol);
    student[nrOfStud].course = malloc(sizeof(*course) * 50);
    for (i = 0; i < nrOfCurs; i++) { //every pointer to a course is null initially
        student[nrOfStud].course[i] = malloc(sizeof(course));
        student[nrOfStud].course[i] = NULL;
    }
}

int deleteStud(stud *student, int nrOfStud) { //delete a student by name
    char nume[200];
    int i = 0, j;
    printf("Nume: ");
    getchar();
    fgets(nume, 200, stdin);
    while (i < nrOfStud) {
        if (strcmp(nume, student[i].nume) == 0) //if the name is found
        {
            nrOfStud--; //the number of students is less
            for (j = i; j < nrOfStud; j++) //and we delete the structure from the array
            {
                student[j] = student[j + 1];
            }
            return 1;
        }
        i++;
    }
    return 0;
}

int findStudName(stud *student, int nrOfStud) { //find student by name
    char nume[200];
    int i = 0, j;
    printf("Nume: ");
    getchar();
    fgets(nume, 200, stdin);
    while (i < nrOfStud) {
        if (strcmp(nume, student[i].nume) == 0) { //if name is found
            printf("Nume: %s", student[i].nume); //print the student's name and number
            printf("Numar matricol: %s", student[i].nrMatricol);
            return 1;
        }
        i++;
    }
    return 0;
}

int findNrMatricol(stud *student, int nrOfStud, curs *course, int nrOfCurs) { //find student by number
    char nrMatricol[20];
    int i = 0, j;
    printf("Numar matricol: ");
    getchar();
    fgets(nrMatricol, 20, stdin);
    while (i < nrOfStud) {
        if (strcmp(nrMatricol, student[i].nrMatricol) == 0) { //if student is found
            printf("Nume: %s", student[i].nume); //print student's name and number
            printf("Numar matricol: %s", student[i].nrMatricol);
            printf("Cursurile pe care le urmeaza: "); //and the courses they follor
            for (j = 0; j < nrOfCurs; j++) {
                if (student[i].course[j] != NULL) {
                    printf("%s ", student[i].course[j]->nume);
                }
            }
            return 1;
        }
        i++;
    }

    return 0;
}

int modifyStud(stud *student, int nrOfStud) { //modify a student's data by name
    char nume[200], nrMatricol[20];
    int i = 0, j;
    printf("Nume: ");
    getchar();
    fgets(nume, 200, stdin);
    while (i < nrOfStud) {
        if (strcmp(nume, student[i].nume) == 0) { //if student is found
            printf("Nume: %s", student[i].nume);
            printf("Numar matricol: %s", student[i].nrMatricol);
            printf("Noul nume: "); //the user can change the name
            getchar();
            fgets(nume, 200, stdin);
            strcpy(student[i].nume, nume);
            printf("Noul numar matricol: "); // and the number
            getchar();
            fgets(nrMatricol, 20, stdin);
            strcpy(student[i].nrMatricol, nrMatricol);
            return 1;
        }
        i++;
    }
    return 0;
}

void sortByStudName(stud *student, int nrOfStud) { //sort students by name
    int i, j, n = nrOfStud - 1;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (strcmp(student[j].nume, student[j + 1].nume) > 0) { //if they are not in alphabetical order
                stud temp = student[j]; //we change the structure's orders
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    showStud(student, nrOfStud);
}

void sortByStudNr(stud *student, int nrOfStud) { //sort students by number
    int i, j, n = nrOfStud - 1;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (strcmp(student[j].nrMatricol, student[j + 1].nrMatricol) > 0) { // if the numbers are not in the right order
                stud temp = student[j]; // we change the structure element's orders
                student[j] = student[j + 1]; //note: I considered that nr matricol is always 10 digits long (so the length
                student[j + 1] = temp; // doesn't differ, otherwise the comparison wouldn't be correct)
            }
        }
    }
    showStud(student, nrOfStud);
}

void showStud(stud *student, int nrOfStud) { // show all students
    int i;
    for (i = 0; i < nrOfStud; i++) {
        printf("Nume: %s", student[i].nume);
        printf("Numar matricol: %s", student[i].nrMatricol);
        printf("\n");
    }
}

void new_course(curs *course, int nrOfCurs, stud *student, int nrOfStud) { // add a new course
    char nume[200];
    int id, i, j;
    if (nrOfCurs + 1 >= size2) {
        size2 += size2;
        course = realloc(course, sizeof(course) * (size2));
        student[nrOfStud].course = realloc(student[nrOfStud].course, sizeof(*student[nrOfStud].course) * nrOfCurs);
    }
    printf("ID curs: ");
    scanf("%d", &id);
    course[nrOfCurs].id = id;
    printf("Nume curs: ");
    getchar();
    fgets(nume, 200, stdin);
    course[nrOfCurs].nume = malloc(sizeof(char) * strlen(nume));
    strcpy(course[nrOfCurs].nume, nume);
    for (i = 0; i < nrOfStud; i++) {
        student[i].course[nrOfCurs] = NULL; // we added a new couse, so every student's course with that id must be null
    }
}

int deleteCurs(curs *course, int nrOfCurs, stud *student, int nrOfStud) { // delete a course by id
    int id;
    int i = 0, j;
    printf("ID curs: ");
    scanf("%d", &id);
    while (i < nrOfCurs) {
        if (id == course[i].id) // if we find the course with the id
        {
            nrOfCurs--; //the number of courses decreases
            for (j = i; j < nrOfCurs; j++)
            {
                course[j] = course[j + 1]; //and we delete that structure from the array
            }
            return 1;
        }
        i++;
    }
    for (j = 0; j < nrOfStud; j++) {
        if (student[j].course[i]== &course[i]) {
            student[j].course[i] = NULL; //and at every student, that certain course will be null
        }
    }
    return 0;
}

int modifyCurs(curs *course, int nrOfCurs) { //modify a course data by is
    char nume[200];
    int i = 0, id;
    printf("ID curs: ");
    scanf("%d", &id);
    while (i < nrOfCurs) {
        if (id == course[i].id) { //if id is found
            printf("ID curs: %d", course[i].id);
            printf("Nume curs: %s", course[i].nume);
            printf("Noul ID: ");
            scanf("%d", &id);
            course[i].id = id;
            printf("Noul nume: "); // user can modify the data
            getchar();
            fgets(nume, 200, stdin);
            strcpy(course[i].nume, nume);
            return 1;
        }
        i++;
    }
    return 0;
}

int findID(stud *student, int nrOfStud, curs *course, int nrOfCurs) { //find the course by id
    int i = 0, j, id;
    printf("ID curs: ");
    scanf("%d", &id);
    while (i < nrOfCurs) {
        if (id == course[i].id) { // if course is found by id
            printf("ID curs: %d\n", course[i].id);
            printf("Nume curs: %s", course[i].nume);
            printf("Studentii care il urmeaza: ");
            for (j = 0; j < nrOfStud; j++) { // show all the students who follow that course + course details
                if (student[j].course[i] == &course[i]) {
                    printf("%s ", student[j].nume);
                }
            }
            return 1;
        }
        i++;
    }
    return 0;
}

void showCurs(curs *course, int nrOfCurs) { // show all courses
    int i;
    for (i = 0; i < nrOfCurs; i++) {
        printf("ID curs: %d\n", course[i].id);
        printf("Nume curs: %s", course[i].nume);
        printf("\n");
    }
}

void addStudToCurs(stud *student, curs *course, int nrOfStud, int nrOfCurs) { // add a student to a certain course
    char student_name[200];
    int id, found1 = 0, i = 0, found2 = 0, j = 0;
    getchar();
    printf("Nume student: ");   //by student name and course id
    fgets(student_name, 200, stdin);
    printf("ID curs: ");
    scanf("%d", &id);
    while(i < nrOfStud && !found1) {
        if (strcmp(student[i].nume, student_name) == 0) { //if student name is found
            found1 = 1;
            while (j < nrOfCurs && !found2) { //we look for course id
                if (course[j].id == id) {
                    found2 = 1;
                    student[i].course[j] = &course[j]; //and the student's certain couse will point to the
                }   //course with the requested is
                j++;
            }
        }
        i++;
    }
}

int removeStudFromCurs(stud *student, curs *course, int nrOfStud, int nrOfCurs) { //remove a student from a course
    char student_name[200]; // by student name and course id
    int id, found1 = 0, i = 0, j = 0;
    printf("Nume student: ");
    getchar();
    fgets(student_name, 200, stdin);
    printf("ID curs: ");
    scanf("%d", &id);
    while(i < nrOfStud && !found1) {
        if (strcmp(student[i].nume, student_name) == 0) { //if we find the student
            found1 = 1;
            while (j < nrOfCurs) {
                if (course[j].id == id) { // and the course with the certain id
                    student[i].course[j] = NULL; // the student's course will not point anywhere
                    return 1;
                }
                j++;
            }
        }
        i++;
    }
    return 0;
}