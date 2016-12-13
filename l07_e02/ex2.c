#include "e2.h"

void new_entry(pb *phonebook, int nrOfElements)
{
    char nume[100], prenume[100], adresa[500], telefon[10];
    if (nrOfElements + 1 >= size)
    {
        size += size;
        phonebook = realloc(phonebook, sizeof(phonebook) * (size));
    }
    printf("nr of el = %d\n", nrOfElements + 1);
    printf("Nume: ");
    gets(nume);
    phonebook[nrOfElements].nume = malloc(sizeof(char) * strlen(nume));
    strcpy(phonebook[nrOfElements].nume, nume);
    printf("Prenume: ");
    gets(prenume);
    phonebook[nrOfElements].prenume = malloc(sizeof(char) * strlen(prenume));
    strcpy(phonebook[nrOfElements].prenume, prenume);
    printf("Adresa: ");
    gets(adresa);
    phonebook[nrOfElements].adresa = malloc(sizeof(char) * strlen(adresa));
    strcpy(phonebook[nrOfElements].adresa, adresa);
    printf("Telefon: ");
    gets(telefon);
    phonebook[nrOfElements].telefon = malloc(sizeof(char) * strlen(telefon));
    strcpy(phonebook[nrOfElements].telefon, telefon);
}

void deleteReg(pb *phonebook, int nrOfElements, char *nume, char *prenume)
{
    int i = 0;
    while (i < nrOfElements)
    {
        if (strcmp(nume, phonebook[i].nume) == 0 && strcmp(prenume, phonebook[i].prenume) == 0)
        {

        }
    }
}

void showAll(pb *phonebook, int nrOfElements)
{
    int i;
    for (i = 0; i < nrOfElements; i++)
    {
        printf("Nume: %s\n", phonebook[i].nume);
        printf("Prenume: %s\n", phonebook[i].prenume);
        printf("Adresa: %s\n", phonebook[i].adresa);
        printf("Telefon: %s\n", phonebook[i].telefon);
    }
}
