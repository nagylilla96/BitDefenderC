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

#endif
