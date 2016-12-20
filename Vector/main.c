//
// Created by lilla on 19/12/16.
//

#include "Vector.h"

void printFunc(first* one) {
    int i;
    pb **phonebook = (pb **) one->pointer;
    printf("Print func entered\n");
    for (i = 0; i < one->nrOfElements; i++) {
        if (one->pointer == NULL) {
            printf("Double pointer is null\n");
        }
        else {
            printf("Double pointer is not null\n");
        }
        if (i % 30 == 0) { // show the page value based on i, which is the number of entries
            printf("page %d\n", (i / 30) + 1);
        }
        if (phonebook[i]->nume == NULL) {
            printf("phonebook nume is null\n");
        }
        else {
            printf("phonebook nume is not null\n");
        }
        printf("Nume: %s", phonebook[i]->nume);
        printf("Prenume: %s", phonebook[i]->prenume);
        printf("Adresa: %s", phonebook[i]->adresa);
        printf("Telefon: %s", phonebook[i]->telefon);
        printf("\n");
    }
}

int main()
{
    size = 50;
    int nrOfElements = 0;
    pb* phonebook;
    char nume[100], prenume[100], adresa[500], telefon[10];
    stud *student = malloc(sizeof(student));
    first *one = malloc(sizeof(one));
    //= malloc(size * sizeof(phonebook));
    CreateVector(one, size);
    int answer;
    printf("Ce vrei sa faci?\n1. Adauga inregistare\n2. Sterge inregistrare\n3. Cautare bazata pe nume + prenume\n");
    printf("4. Cautare bazata pe numar de telefon\n5. Afisare bazata pe nume de familie\n6. Afisare in ordine alfabetica\n");
    printf("7. Afisare tot\n8. Iesire\nScrie numarul!\n");
    while (scanf("%d", &answer) >= 0) {
        switch (answer) {
            case 1:
                printf("Nume: ");
                getchar();
                fgets(nume, 100, stdin);
                student->nume = malloc(strlen(nume));
                strcpy(student->nume, nume);
                printf("Prenume: ");
                fgets(prenume, 100, stdin);
                student->prenume = malloc(strlen(prenume));
                strcpy(student->prenume, prenume);
                printf("Adresa: ");
                fgets(adresa, 500, stdin);
                student->adresa = malloc(strlen(adresa));
                strcpy(student->adresa, adresa);
                printf("Telefon: ");
                fgets(telefon, 10, stdin);
                student->telefon = malloc(strlen(telefon));
                strcpy(student->telefon, telefon);
                new_entry(one, student, &size);
                break;
            case 2:
                if (deleteReg(phonebook, nrOfElements))
                {
                    nrOfElements--;
                }
                else
                {
                    printf("Person not found\n");
                }
                break;
            case 3:
                if (!findName(phonebook, nrOfElements)) {
                    printf("Person not found\n");
                }
                break;
            case 4:
                if (!findPhone(phonebook, nrOfElements)) {
                    printf("Phone number not found\n");
                }
                break;
            case 5:
                if (!findFamily(phonebook, nrOfElements)) {
                    printf("Family name not found\n");
                }
                break;
            case 6:
                sortByName(phonebook, nrOfElements);
                break;
            case 7:
                PrintVector(one, printFunc);
                break;
            case 8:
                return 0;
            default:
                break;
        }
        printf("Ce vrei sa faci?\n1. Adauga inregistare\n2. Sterge inregistrare\n3. Cautare bazata pe nume + prenume\n");
        printf("4. Cautare bazata pe numar de telefon\n5. Afisare bazata pe nume de familie\n6. Afisare in ordine alfabetica\n");
        printf("7. Afisare tot\n8. Iesire\nScrie numarul!\n");
    }
    return 0;
}