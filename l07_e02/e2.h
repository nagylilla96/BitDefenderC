#ifndef MODULE_H_MODULE
#define MODULE_H_MODULE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int size;

typedef struct {
    char *nume;
    char *prenume;
    char *adresa;
    char *telefon;
} pb;

void new_entry(pb *phonebook, int nrOfElements);
void showAll(pb *phonebook, int nrOfElements);
int deleteReg(pb *phonebook, int nrOfElements);
int findName(pb *phonebook, int nrOfElements);
int findPhone(pb *phonebook, int nrOfElements);
int findFamily(pb *phonebook, int nrOfElements);
pb *sortByName(pb *phonebook, int nrOfElements);

#endif
