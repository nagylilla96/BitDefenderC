//
// Created by lilla on 13/12/16.
//

#include "e03.h"

int main() {
    size = 50;
    size2 = 50;
    int nrOfStud = 0, nrOfCurs = 0;
    stud *student = malloc(size * sizeof(student));
    curs *course = malloc(size2 * sizeof(course));
    int answer;
    printf("Ce vrei sa faci?\n1. Adauga student\n2. Sterge student\n3. Modificare student\n");
    printf("4. Cautare student (nume)\n5. Cautare student (numar matricol)\n6. Afisare studenti (ordine alfabetica)\n");
    printf("7. Afisare studenti (numar matricol)\n8. Afisare studenti\n9. Adauga curs\n10. Sterge curs\n11. Modifica curs\n");
    printf("12. Gaseste curs (ID)\n13. Afisare cursuri\n14. Adauga studenti la curs\n15. Sterge studenti de la curs\n");
    printf("16. Iesire\nScrie numarul!\n");
    while (scanf("%d", &answer) >= 0) {
        switch (answer) {
            case 1:
                new_student(student, nrOfStud, course, nrOfCurs);
                nrOfStud++;
                break;
            case 2:
                if (deleteStud(student, nrOfStud)) {
                    nrOfStud--;
                } else {
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
                if (!findNrMatricol(student, nrOfStud, course, nrOfCurs)) {
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
                new_course(course, nrOfCurs, student, nrOfStud);
                nrOfCurs++;
                break;
            case 10:
                if (deleteCurs(course, nrOfCurs, student, nrOfStud)) {
                    nrOfCurs--;
                } else {
                    printf("Course not found\n");
                }
                break;
            case 11:
                if (!modifyCurs(course, nrOfCurs)) {
                    printf("Course not found\n");
                }
                break;
            case 12:
                if (!findID(student, nrOfStud, course, nrOfCurs)) {
                    printf("Course not found\n");
                }
                break;
            case 13:
                showCurs(course, nrOfCurs);
                break;
            case 14:
                addStudToCurs(student, course, nrOfStud, nrOfCurs);
                break;
            case 15:
                if (!removeStudFromCurs(student, course, nrOfStud, nrOfCurs)) {
                    printf("Student/curs not found\n");
                }
                break;
            case 16:
                return 0;
            default:
                break;
        }
        printf("Ce vrei sa faci?\n1. Adauga student\n2. Sterge student\n3. Modificare student\n");
        printf("4. Cautare student (nume)\n5. Cautare student (numar matricol)\n6. Afisare studenti (ordine alfabetica)\n");
        printf("7. Afisare studenti (numar matricol)\n8. Afisare studenti\n9. Adauga curs\n10. Sterge curs\n11. Modifica curs\n");
        printf("12. Gaseste curs (ID)\n13. Afisare cursuri\n14. Adauga studenti la curs\n15. Sterge studenti de la curs\n");
        printf("16. Iesire\nScrie numarul!\n");
    }
    return 0;
}
