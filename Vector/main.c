//
// Created by lilla on 19/12/16.
//

#include "Vector.h"

int main()
{
    size = 50;
    int nrOfElements = 0;
    pb* phonebook;
    char nume[100], prenume[100], adresa[500], telefon[10];
    stud student;
    first one;
    //= malloc(size * sizeof(phonebook));
    CreateVector(&phonebook, &one, size);
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
                student.nume = malloc(strlen(nume));
                strcpy(student.nume, nume);
                printf("Prenume: ");
                fgets(prenume, 100, stdin);
                student.prenume = malloc(strlen(prenume));
                strcpy(student.prenume, prenume);
                printf("Adresa: ");
                fgets(adresa, 500, stdin);
                student.adresa = malloc(strlen(adresa));
                strcpy(student.adresa, adresa);
                printf("Telefon: ");
                fgets(telefon, 10, stdin);
                student.telefon = malloc(strlen(telefon));
                strcpy(student.telefon, telefon);
                new_entry(&phonebook, &one, &student, &size);
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
                showAll(phonebook, nrOfElements);
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