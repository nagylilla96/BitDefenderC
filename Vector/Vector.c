//
// Created by lilla on 19/12/16.
//

#include "Vector.h"

void** allocateVect(size_t size) {
    void **vector =  malloc(size * sizeof(void**));
    int i;
    for (i = 0; i < size; i++) {
        vector[i] = malloc(sizeof(void*));
    }
    return vector;
}

first *CreateVector(size_t size) {
    first* array = (first*) malloc(sizeof(first*));
    printf("CreateVector entered\n");
    array->pointer = allocateVect(size);
    array->nrOfElements = 0;
    printf("nr of elements: %d\n", array->nrOfElements);
    return array;
}

void new_entry(first* one, void* newNode, size_t *size) { // add a new entry
    if (one->nrOfElements + 1 >= *size) {
        *size *= 2;
        one->pointer = realloc(one->pointer, sizeof(one->pointer) * (*size)); // if the data amount exceeds the size, realloc space
    }
    printf("NrOfElements = %d\n", one->nrOfElements);
    one->pointer[one->nrOfElements]= malloc(sizeof(newNode));
    one->pointer[one->nrOfElements] = newNode;
    one->nrOfElements++;
}

void AddVectorItems(int nrOfItems, first* one, size_t *size, void(*newItem)(char *nume, char *prenume, char *adresa, char *telefon, first *one, size_t size) ) {
    int i;
    char nume[100], prenume[100], adresa[500], telefon[10];
    for (i = 0; i < nrOfItems; i++) {
        printf("Nume: ");
        getchar();
        fgets(nume, 100, stdin);
        printf("Prenume: ");
        fgets(prenume, 100, stdin);
        printf("Adresa: ");
        fgets(adresa, 500, stdin);
        printf("Telefon: ");
        fgets(telefon, 10, stdin);
        newItem(nume, prenume, adresa, telefon, one, *size);
    }
}

//int deleteReg(pb *phonebook, int nrOfElements) { //delete an entry based by nume and prenume
//    char nume[100], prenume[100];
//    int i = 0, j;
//    printf("Nume: ");
//    getchar();
//    fgets(nume, 100, stdin);
//    printf("Prenume: ");
//    fgets(prenume, 100, stdin);
//    while (i < nrOfElements) {
//        if (strcmp(nume, phonebook[i].nume) == 0 && strcmp(prenume, phonebook[i].prenume) == 0) // if nume and prenume found
//        {
//            nrOfElements--;
//            for (j = i; j < nrOfElements; j++) // the structure from the array is deleted
//            {
//                phonebook[j] = phonebook[j + 1];
//            }
//            return 1;
//        }
//        i++;
//    }
//    return 0;
//}

int findName(first *one, void* node, int(*cmpFunc)(void* a, void* b), void(*printFunc)(first* one, int index)) { // find name by nume and prenume
    int i = 0;
    while (i < one->nrOfElements)
    {
        if (cmpFunc(one->pointer[i], node) == 0) { // if nume and prenume found
            printFunc(one, i);
            printf("Person found at index %d\n", i);
            return i;
        }
        i++;
    }
    return -1;
}

//int findPhone(pb *phonebook, int nrOfElements) { // find data by phone number
//    char telefon[10];
//    int i = 0;
//    printf("Telefon: ");
//    getchar();
//    fgets(telefon, 10, stdin);
//    while (i < nrOfElements) {
//        if (strcmp(telefon, phonebook[i].telefon) == 0) { // if phone number is found (which is a string by the way, because they
//            printf("Nume: %s", phonebook[i].nume); // can start with 0), the data is printed
//            printf("Prenume: %s", phonebook[i].prenume);
//            printf("Adresa: %s", phonebook[i].adresa);
//            printf("Telefon: %s", phonebook[i].telefon);
//            return i;
//        }
//        i++;
//    }
//    return 0;
//}
//
//int findFamily(pb *phonebook, int nrOfElements) { // find all people with a certain family name
//    char nume[100];
//    int i = 0, found = 0;
//    printf("Nume: ");
//    getchar();
//    fgets(nume, 100, stdin);
//    while (i < nrOfElements) {
//        if (strcmp(nume, phonebook[i].nume) == 0) { //if family name is found, list all people with that family name
//            printf("Nume: %s", phonebook[i].nume);
//            printf("Prenume: %s", phonebook[i].prenume);
//            printf("Adresa: %s", phonebook[i].adresa);
//            printf("Telefon: %s", phonebook[i].telefon);
//            printf("\n");
//            found = 1;
//        }
//        i++;
//    }
//    if (found == 0)
//    {
//        return 0;
//    }
//    return 1;
//}
//
//void sortByName(pb *phonebook, int nrOfElements) { // sort data by name
//    int i, j, n = nrOfElements - 1;
//    char fullName1[200], fullName2[200];
//    for (i = 1; i < n; i++) {
//        for (j = 0; j < n - i; j++) { // using an interesting version of boolean sort that i found
//            strcpy(fullName1, phonebook[j].nume); // i used full name, so comparison is easier (which is nume + prenume)
//            strcat(fullName1, phonebook[j].prenume);
//            strcpy(fullName2, phonebook[j+1].nume);
//            strcat(fullName2, phonebook[j+1].prenume);
//            if (strcmp(fullName1, fullName2) > 0) {
//                pb temp = phonebook[j];
//                phonebook[j] = phonebook[j + 1];
//                phonebook[j + 1] = temp;
//            }
//        }
//    }
////    showAll(phonebook, nrOfElements);
//}
//
//
void PrintVector(first* one, void(*printAllFunc)(first*)) { // show all elements from the phone book
    printAllFunc(one);
}