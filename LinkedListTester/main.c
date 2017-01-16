#include "tester.h"



int main(int argc, char **argv) {
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
                    DIR *dir = opendir("Input/");
                    if (dir != NULL){
                        struct dirent *dr;
                        while ((dr = readdir(dir)) != NULL) {
                            if (dr->d_type == DT_REG) {
                                printf("%s\n", dr->d_name);
                                char *input = calloc(100, sizeof(char));
                                strcpy(input, "Input/");
                                char *output = calloc(100, sizeof(char));
                                char *basicName = calloc(100, sizeof(char));
                                strcpy(basicName, strtok(dr->d_name, "."));
                                strcat(input, basicName);
                                strcpy(output, "Output/");
                                strcat(output, basicName);
                                strcat(input, ".in");
                                strcat(output, ".out");
                                runTester(input, output);
                            }
                        }
                        closedir(dir);
                    }
                    else {
                        printf("Can't open directory\n");
                    }
                }
                else {
                    strcpy(name, argv[1]);
                    strcat(argv[1],".in");
                    strcat(name, ".out");
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
                    runTester(input, output);
                    input[2] ++;
                }
            }
        }
    }
    return 0;
}