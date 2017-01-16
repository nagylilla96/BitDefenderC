#include "tester.h"

int main(int argc, char **argv) {
    int length;
    char *name = malloc(sizeof(char) * 100);
    char *name1 = malloc(sizeof(char) * 100);
    printf("argc = %d\n", argc);
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
                int i;
                strcpy(name, argv[1]);
                strcpy(name1, argv[2]);
                char *input = malloc(sizeof(char) * 100);
                char *output = malloc(sizeof(char) * 100);
                strcpy(input, argv[1]);
                for (i = 0; i < name1[2] - name[2]; i++) {
                    input[2] += i;
                    printf("%s\n", input);
                    strcpy(output, input);
                    length = strlen(output);
                    output[length-2] = 'o';
                    output[length - 1] = 'u';
                    output[length] = 't';
                    output[length + 1] = '\0';
                    runTester(input, output);
                }
            }
        }
    }
    return 0;
}