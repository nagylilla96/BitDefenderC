//
// Created by lilla on 19/12/16.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t size;

typedef struct {
    char *nume;
    char *prenume;
    char *adresa;
    char *telefon;
} pb, stud;

typedef struct {
    void **pointer;
    int nrOfElements;
} first;

void CreateVector(first* one, size_t size);
void** allocateVect(first* one, size_t size);
void new_entry(first* one, void* newNode, size_t *size);
void PrintVector(first* one, void(*printFunc)(first *one));
int deleteReg(pb *phonebook, int nrOfElements);
int findName(first *one, void* node, int(*cmpFunc)(void* a, void* b), void(*printFunc)(first* one, int index));
int findPhone(pb *phonebook, int nrOfElements);
int findFamily(pb *phonebook, int nrOfElements);
void sortByName(pb *phonebook, int nrOfElements);

#endif //VECTOR_VECTOR_H
