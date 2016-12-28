//
// Created by lilla on 19/12/16.
//

#include "Vector.h"

typedef struct {
    char *nume;
    char *prenume;
    char *adresa;
    char *telefon;
} node;

void printFunc(first* one, int index) {
    printf("index = %d\n", index);
    node **phonebook = (node**) one->pointer;
    printf("Nume: %s", phonebook[index]->nume);
    printf("Prenume: %s", phonebook[index]->prenume);
    printf("Adresa: %s", phonebook[index]->adresa);
    printf("Telefon: %s", phonebook[index]->telefon);
    printf("\n");
}

void printAllFunc(first* one) {
    int i;
    node **phonebook = (node **) one->pointer;
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
        printFunc(one, i);
    }
}

node *createNode(char *nume, char *prenume, char *adresa, char *telefon) {
    node *myNode = (node*) malloc(sizeof(node));
    myNode->nume = malloc(sizeof(char) * 100);
    myNode->prenume = malloc(sizeof(char) * 100);
    myNode->adresa = malloc(sizeof(char) * 500);
    myNode->telefon = malloc(sizeof(char) * 10);
    strcpy(myNode->nume, nume);
    strcpy(myNode->prenume, prenume);
    strcpy(myNode->adresa, adresa);
    strcpy(myNode->telefon, telefon);
    return myNode;
}

int ifEquals(void *a, void *b) {
    node *aa = (node *) a;
    node *bb = (node *) b;
    if (strcmp(aa->nume, bb->nume) == 0 && strcmp(aa->prenume, bb->prenume) == 0
        && strcmp(aa->adresa, bb->adresa) == 0 && strcmp(aa->telefon, bb->telefon) == 0) {
            return 0;
    }
    return -1;
}

int main()
{
    size = 50;
    char nume[100], prenume[100], adresa[500], telefon[10];
    first *one = CreateVector(size);
    node *student;
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
                printf("Prenume: ");
                fgets(prenume, 100, stdin);
                printf("Adresa: ");
                fgets(adresa, 500, stdin);
                printf("Telefon: ");
                fgets(telefon, 10, stdin);
                student = createNode(nume, prenume, adresa, telefon);
                new_entry(one, student, &size);
            case 2:
//                if (deleteReg(phonebook, nrOfElements))
//                {
//                    nrOfElements--;
//                }
//                else
//                {
//                    printf("Person not found\n");
//                }
                break;
            case 3:
                printf("Nume: ");
                getchar();
                fgets(nume, 100, stdin);
                printf("Prenume: ");
                fgets(prenume, 100, stdin);
                printf("Adresa: ");
                fgets(adresa, 500, stdin);
                printf("Telefon: ");
                fgets(telefon, 10, stdin);
                student = createNode(nume, prenume, adresa, telefon);
                int x = findName(one, student, ifEquals, printFunc);
                if (x == -1) {
                    printf("Person not found\n");
                }
                break;
            case 4:
//                if (!findPhone(phonebook, nrOfElements)) {
//                    printf("Phone number not found\n");
//                }
                break;
            case 5:
//                if (!findFamily(phonebook, nrOfElements)) {
//                    printf("Family name not found\n");
//                }
                break;
            case 6:
//                sortByName(phonebook, nrOfElements);
                break;
            case 7:
                PrintVector(one, printAllFunc);
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