#include "tester.h"

int main(int argc, char **argv) {
    int length;
    char *name = malloc(sizeof(char) * 100);
    printf("argc = %d", argc);
    if (argc <= 1) {
        printf("Please scpecify the file you want to use for testing!\n");
    }
    else {
        if (argc > 3) {
            printf("Too many arguments\n");
        }
        else {
            if (argc == 2) {
                length = strlen(argv[1]);
                strcpy(name, argv[1]);
                name[length-2] = 'o';
                name[length - 1] = 'u';
                name[length] = 't';
                name[length + 1] = '\0';
                printf("name = %s\n", name);
                runTester(argv[1], name);
            }
            else {

            }
        }
    }
    return 0;
}