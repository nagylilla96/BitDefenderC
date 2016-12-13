#include "e2.h"

int main()
{
    size = 50;
    int nrOfElements = 0;
    pb* phonebook = malloc(size * sizeof(phonebook));
    new_entry(phonebook, nrOfElements);
    nrOfElements++;
    new_entry(phonebook, nrOfElements);
    nrOfElements++;
    showAll(phonebook, nrOfElements);
    return 0;
}
