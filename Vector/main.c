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

void printFunc(first* one, int index, FILE *f) {
    fprintf(f, "index = %d\n", index);
    node **phonebook = (node**) one->pointer;
    fprintf(f, "Nume: %s", phonebook[index]->nume);
    fprintf(f, "Prenume: %s", phonebook[index]->prenume);
    fprintf(f, "Adresa: %s", phonebook[index]->adresa);
    fprintf(f, "Telefon: %s", phonebook[index]->telefon);
    fprintf(f, "\n");
}

void printAllFunc(first* one, FILE *f) {
    int i;
    node **phonebook = (node **) one->pointer;
    fprintf(f, "Print func entered\n");
    for (i = 0; i < one->nrOfElements; i++) {
        if (one->pointer == NULL) {
            fprintf(f, "Double pointer is null\n");
        }
        if (phonebook[i]->nume == NULL) {
            fprintf(f, "phonebook nume is null\n");
        }
        printFunc(one, i, f);
    }
}

void freeFunct(void *a) {
    node *aa = (node *) a;
    free(a);
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

node *getNode(int i, FILE *f) {
    char nume[100], prenume[100], adresa[500], telefon[10];
    fprintf(f, "Nume: ");
    if (i == 0) {
        getchar();
    }
    fgets(nume, 100, stdin);
    fprintf(f, "Prenume: ");
    fgets(prenume, 100, stdin);
    fprintf(f, "Adresa: ");
    fgets(adresa, 500, stdin);
    fprintf(f, "Telefon: ");
    fgets(telefon, 10, stdin);
    return createNode(nume, prenume, adresa, telefon);
}

int cmpFunct(void *a, void *b) {
    node *aa = (node *) a;
    node *bb = (node *) b;
    if (strcmp(aa->nume, bb->nume) > 0) {
        return 1;
    }
    else {
        if (strcmp(aa->nume, bb->nume) == 0) {
            if (strcmp(aa->prenume, bb->prenume) > 0) {
                return 1;
            }
            else {
                if (strcmp(aa->prenume, bb->prenume) == 0) {
                    if (strcmp(aa->adresa, bb->adresa) > 0) {
                        return 1;
                    }
                    else {
                        if (strcmp(aa->adresa, bb->adresa) == 0) {
                            return 0;
                        }
                        else {
                            return -1;
                        }
                    }
                }
                else {
                    return -1;
                }
            }
        }
        else {
            return -1;
        }
    }
}

void freeNode(void* a){
    node *aa = (node*) a;
    free(aa->nume);
    free(aa->prenume);
    free(aa->adresa);
    free(aa->telefon);
}

int main()
{
    int size = 50;
    char nume[100], prenume[100], adresa[500], telefon[10];
    first *one = CreateVector(size);
    first *two = CreateVector(size);
    first *three;
    node *student;
    int nrOfItems, index;
    int answer;
    printf("Ce vrei sa faci?\n1. Adauga inregistari la final\n2. Sterge inregistrare\n3. Cautare\n");
    printf("4. Returnare index\n5. Adaugare la index\n6. Sortare\n");
    printf("7. Adauga inregistrari vector2\n8. Afisare tot vector1\n9. Afisare tot vector2\n10. Iesire\nScrie numarul!\n");
    while (scanf("%d", &answer) >= 0) {
        switch (answer) {
            case 1:
                printf("How many new items do you want?\n");
                scanf("%d", &nrOfItems);
                AddVectorItems(nrOfItems, one, getNode, stdout);
                break;
            case 2:
                printf("Which index do you want to delete?\n");
                scanf("%d", &index);
                if (index >= one->nrOfElements) {
                    printf("There are less than %d elements!\n", index);
                    break;
                }
                DeleteVectorItem(one, index, freeNode);
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
                int x = SearchVectorItem(one, student, cmpFunct, printFunc, stdout);
                if (x == -1) {
                    printf("Person not found\n");
                }
                break;
            case 4:
                printf("What index do you want? ");
                scanf("%d", &index);
                if (index >= one->nrOfElements) {
                    printf("Index %d is bigger than the number of elements!\n", index);
                    break;
                }
                GetVectorItem(index, one, printFunc, stdout);
                break;
            case 5:
                printf("Where do you want to insert the item?");
                scanf("%d", &index);
                if (index > one->nrOfElements) {
                    printf("You can't insert there!\n");
                    break;
                }
                PutVectorItem(index, one, getNode(0, stdout));
                break;
            case 6:
                SortVector(one, cmpFunct);
                break;
            case 7:
                printf("Add elements to vector2!");
                printf("How many new items do you want?\n");
                scanf("%d", &nrOfItems);
                AddVectorItems(nrOfItems, one, getNode, stdout);
                break;
            case 8:
                printf("Vector1\n");
                PrintVector(one, printAllFunc, stdout);
                break;
            case 9:
                printf("Vector2\n");
                PrintVector(two, printAllFunc, stdout);
                break;
            case 10:
                three = CreateVector((size_t) one->nrOfElements + two->nrOfElements);
                three = MergeVectors(one, two, three, cmpFunct);
                PrintVector(three, printAllFunc, stdout);
                break;
            case 11:
                DeleteVector(one, freeFunct);
                return 0;
            default:
                break;
        }
        printf("Ce vrei sa faci?\n1. Adauga inregistari la final\n2. Sterge inregistrare\n3. Cautare\n");
        printf("4. Returnare index\n5. Adaugare la index\n6. Sortare\n");
        printf("7. Adauga inregistrari vector2\n8. Afisare tot vector1\n9. Afisare tot vector2\n10. Merge\n11. Iesire\nScrie numarul!\n");
    }
    return 0;
}