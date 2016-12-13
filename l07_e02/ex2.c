#include <stdio.h>
#include "e2.h"

void new_entry(pb *phonebook, int nrOfElements) {
    char nume[100], prenume[100], adresa[500], telefon[10];
    if (nrOfElements + 1 >= size) {
        size += size;
        phonebook = realloc(phonebook, sizeof(phonebook) * (size));
    }
    printf("nr of el = %d\n", nrOfElements + 1);
    printf("Nume: ");
    fgets(nume, 100, stdin);
    phonebook[nrOfElements].nume = malloc(sizeof(char) * strlen(nume));
    strcpy(phonebook[nrOfElements].nume, nume);
    printf("Prenume: ");
    fgets(prenume, 100, stdin);
    phonebook[nrOfElements].prenume = malloc(sizeof(char) * strlen(prenume));
    strcpy(phonebook[nrOfElements].prenume, prenume);
    printf("Adresa: ");
    fgets(adresa, 500, stdin);
    phonebook[nrOfElements].adresa = malloc(sizeof(char) * strlen(adresa));
    strcpy(phonebook[nrOfElements].adresa, adresa);
    printf("Telefon: ");
    fgets(telefon, 10, stdin);
    phonebook[nrOfElements].telefon = malloc(sizeof(char) * strlen(telefon));
    strcpy(phonebook[nrOfElements].telefon, telefon);
}

int deleteReg(pb *phonebook, int nrOfElements) {
    char nume[100], prenume[100];
    int i = 0, j;
    int found = 0;
    printf("Nume: ");
    fgets(nume, 100, stdin);
    printf("Prenume: ");
    fgets(prenume, 100, stdin);
    while (i < nrOfElements) {
        if (strcmp(nume, phonebook[i].nume) == 0 && strcmp(prenume, phonebook[i].prenume) == 0)
        {
            printf("found\n");
            nrOfElements--;
            found = 1;
            for (j = i; j < nrOfElements; j++)
            {
                phonebook[j] = phonebook[j + 1];
            }
            i = nrOfElements;
            return 1;
        }
        i++;
    }
    return 0;
}

int findName(pb *phonebook, int nrOfElements) {
    char nume[100], prenume[100];
    int i = 0;
    printf("Nume: ");
    fgets(nume, 100, stdin);
    printf("Prenume: ");
    fgets(prenume, 100, stdin);
    while (i < nrOfElements) {
        if (strcmp(nume, phonebook[i].nume) == 0 && strcmp(prenume, phonebook[i].prenume) == 0) {
            printf("Nume: %s\n", phonebook[i].nume);
            printf("Prenume: %s\n", phonebook[i].prenume);
            printf("Adresa: %s\n", phonebook[i].adresa);
            printf("Telefon: %s\n", phonebook[i].telefon);
            i = nrOfElements;
            return 1;
        }
        i++;
    }
    return 0;
}

int findPhone(pb *phonebook, int nrOfElements) {
    char telefon[10];
    int i = 0;
    printf("Telefon: ");
    fgets(telefon, 10, stdin);
    while (i < nrOfElements) {
        if (strcmp(telefon, phonebook[i].telefon) == 0) {
            printf("Nume: %s\n", phonebook[i].nume);
            printf("Prenume: %s\n", phonebook[i].prenume);
            printf("Adresa: %s\n", phonebook[i].adresa);
            printf("Telefon: %s\n", phonebook[i].telefon);
            i = nrOfElements;
            return 1;
        }
        i++;
    }
    return 0;
}

int findFamily(pb *phonebook, int nrOfElements) {
    char nume[100];
    int i = 0, found = 0;
    printf("Nume: ");
    fgets(nume, 100, stdin);
    while (i < nrOfElements) {
        if (strcmp(nume, phonebook[i].nume) == 0) {
            printf("Nume: %s\n", phonebook[i].nume);
            printf("Prenume: %s\n", phonebook[i].prenume);
            printf("Adresa: %s\n", phonebook[i].adresa);
            printf("Telefon: %s\n", phonebook[i].telefon);
            found = 1;
        }
        i++;
    }
    if (found == 0)
    {
        return 0;
    }
    return 1;
}

pb *sortByName(pb *phonebook, int nrOfElements) {
    pb *newPhoneBook = phonebook;
    int i, swapped, n = nrOfElements;
    char fullName1[200], fullName2[200];
    do {
        swapped = 0;
        for (i = 0; i < n - 1; i++) {
            strcpy(fullName1, newPhoneBook[i].nume);
            strcat(fullName1, newPhoneBook[i].prenume);
            strcpy(fullName2, newPhoneBook[i+1].nume);
            strcpy(fullName2, newPhoneBook[i+1].prenume);
            if (strcmp(fullName1, fullName2) > 0) {
                pb temp = newPhoneBook[i];
                newPhoneBook[i] = newPhoneBook[i + 1];
                newPhoneBook[i + 1] = temp;
                swapped = 1;
            }
        }
        n--;
    } while (!swapped);
    return newPhoneBook;
}


void showAll(pb *phonebook, int nrOfElements) {
    int i;
    printf("page 1\n");
    for (i = 0; i < nrOfElements; i++) {
        if (i % 30 == 0) {
            printf("page %d\n", (i / 30) + 1);
        }
        printf("Nume: %s\n", phonebook[i].nume);
        printf("Prenume: %s\n", phonebook[i].prenume);
        printf("Adresa: %s\n", phonebook[i].adresa);
        printf("Telefon: %s\n", phonebook[i].telefon);
    }
}
