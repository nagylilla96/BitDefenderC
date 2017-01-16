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
                if (strcmp(argv[1], "runall") == 0 ) {

                }
                else {
//                    length = strlen(argv[1]);
                    strcpy(name, argv[1]);
                    strcat(argv[1],".in");
                    strcat(name, ".out");
//                    name[length-2] = 'o';
//                    name[length - 1] = 'u';
//                    name[length] = 't';
//                    name[length + 1] = '\0';
                    printf("name = %s\n", name);
                    runTester(argv[1], name);
                }
            }
            else {
                int i;
                strcpy(name, argv[1]);
                strcpy(name1, argv[2]);
                char *input = malloc(sizeof(char) * 100);
                char *output = malloc(sizeof(char) * 100);
                strcpy(input, argv[1]);
                strcpy(output, input);
                strcat(input, ".in");
                strcat(output, ".out");
                printf("name1-nam2 = %d\n", name1[2] - name[2]);
                for (i = 0; i <= name1[2] - name[2]; i++) {
                    printf("i = %d\n", i);
                    printf("%s\n", input);
                    strncpy(output, input, 3);
//                    length = strlen(output);
//                    output[length-2] = 'o';
//                    output[length - 1] = 'u';
//                    output[length] = 't';
//                    output[length + 1] = '\0';
                    runTester(input, output);
                    input[2] ++;
                }
            }
        }
    }
    return 0;
}