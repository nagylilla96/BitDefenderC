//
// Created by lilla on 19/12/16.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int size;

typedef struct {
    char *nume;
    char *prenume;
    char *adresa;
    char *telefon;
} pb, stud;

typedef struct {
    void *pointer;
    int nrOfElements;
} first;

void CreateVector(void** vector, first* one, size_t size);
void new_entry(void** vector, first* one, void* newNode, size_t *size);
void showAll(pb *phonebook, int nrOfElements);
int deleteReg(pb *phonebook, int nrOfElements);
int findName(pb *phonebook, int nrOfElements);
int findPhone(pb *phonebook, int nrOfElements);
int findFamily(pb *phonebook, int nrOfElements);
void sortByName(pb *phonebook, int nrOfElements);

#endif //VECTOR_VECTOR_H
