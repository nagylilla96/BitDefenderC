#include "BSTTester.h"

int main(int argc, char **argv) {
    char *name = malloc(sizeof(char) * 100);
    char *name1 = malloc(sizeof(char) * 100);
    printf("argc = %d\n", argc);
    if (argc <= 1) { // if we don't have enough arguments, an error message is displayed
        printf("Please scpecify the file you want to use for testing!\n");
    }
    else {
        if (argc > 3) { // if we have too many arguments, an error message is displayed
            printf("Too many arguments\n");
        }
        else {
            if (argc == 2) {
                if (strcmp(argv[1], "runall") == 0 ) { //if the command is runall
                    DIR *dir = opendir("Input/"); //we open the Input directory
                    if (dir != NULL){
                        struct dirent *dr;
                        while ((dr = readdir(dir)) != NULL) {
                            if (dr->d_type == DT_REG) { //and look for files
                                char *input = malloc(sizeof(char) * 100);
                                strcpy(input, "Input/");
                                char *output = malloc(sizeof(char) * 100);
                                char *basicName = malloc(sizeof(char) * 100);
                                strcpy(basicName, strtok(dr->d_name, "."));
                                strcat(input, basicName);
                                strcpy(output, "Output/");
                                strcat(output, basicName);
                                strcat(input, ".in");
                                strcat(output, ".out");
                                runTester(input, output); //we copy the path + file name (and add 1 to it in each loop)
                            } // and run it!
                        }
                        closedir(dir); // close the directory
                    }
                    else {
                        printf("Can't open directory\n"); // display that directory can't be opened
                    }
                }
                else {
                    strcpy(name, argv[1]); //if there is one argument, a file name, run it
                    strcat(argv[1],".in");
                    strcat(name, ".out");
                    printf("name = %s\n", name);
                    runTester(argv[1], name);
                }
            }
            else {
                int i;
                strcpy(name, argv[1]); // run the tests between these two arguments
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