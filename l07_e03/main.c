//
// Created by lilla on 13/12/16.
//

#include "e03.h"

int main() {
    size = 50;
    int nrOfStud = 0;
    stud* student = malloc(size * sizeof(student));
    int answer;
    printf("Ce vrei sa faci?\n1. Adauga student\n2. Sterge student\n3. Modificare student\n");
    printf("4. Cautare student (nume)\n5. Cautare student (numar matricol)\n6. Afisare studenti (ordine alfabetica)\n");
    printf("7. Afisare studenti (numar matricol)\n8. Afisare studenti\n9. Iesire\nScrie numarul!\n");
    while (scanf("%d", &answer) >= 0) {
        switch (answer) {
            case 1:
                new_student(student, nrOfStud);
                nrOfStud++;
                break;
            case 2:
                if (deleteStud(student, nrOfStud))
                {
                    nrOfStud--;
                }
                else
                {
                    printf("Student not found\n");
                }
                break;
            case 3:
                if (!modifyStud(student, nrOfStud)) {
                    printf("Student not found\n");
                }
                break;
            case 4:
                if (!findStudName(student, nrOfStud)) {
                    printf("Student number not found\n");
                }
                break;
            case 5:
                if (!findNrMatricol(student, nrOfStud)) {
                    printf("Numar matricol not found\n");
                }
                break;
            case 6:
                sortByStudName(student, nrOfStud);
                break;
            case 7:
                sortByStudNr(student, nrOfStud);
                break;
            case 8:
                showStud(student, nrOfStud);
                break;
            case 9:
                return 0;
            default:
                break;
        }
        printf("Ce vrei sa faci?\n1. Adauga student\n2. Sterge student\n3. Modificare student\n");
        printf("4. Cautare student (nume)\n5. Cautare student (numar matricol)\n6. Afisare studenti (ordine alfabetica)\n");
        printf("7. Afisare studenti (numar matricol)\n8. Afisare studenti\n9. Iesire\nScrie numarul!\n");
    }
    return 0;
}
