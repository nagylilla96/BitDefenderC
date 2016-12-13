#include "e2.h"

int main()
{
    size = 50;
    int nrOfElements = 0;
    pb* phonebook = malloc(size * sizeof(phonebook));
    int answer;
    printf("Ce vrei sa faci?\n1. Adauga inregistare\n2. Sterge inregistrare\n3. Cautare bazata pe nume + prenume\n");
    printf("4. Cautare bazata pe numar de telefon\n5. Afisare bazata pe nume de familie\n6. Afisare in ordine alfabetica\n");
    printf("7. Afisare tot\n8. Iesire\nScrie numarul!\n");
    while (scanf("%d", &answer) >= 0) {
        switch (answer) {
            case 1:
                new_entry(phonebook, nrOfElements);
                nrOfElements++;
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
                break;
            default:
                break;
        }
        printf("Ce vrei sa faci?\n1. Adauga inregistare\n2. Sterge inregistrare\n3. Cautare bazata pe nume + prenume\n");
        printf("4. Cautare bazata pe numar de telefon\n5. Afisare bazata pe nume de familie\n6. Afisare in ordine alfabetica\n");
        printf("7. Afisare tot\n8. Iesire\nScrie numarul!\n");
    }
    return 0;
}
