#include "lab3.h"

int main()
{
    char *string, *word;
    int n;
    string = (char*) malloc(100 * sizeof(char));
    word = (char*) malloc(50 * sizeof(char));
    printf("What is your string?\n");
    fgets(string, 100, stdin);
    string = (char*) realloc(string, sizeof(char) * strlen(string));
    string = delete_space(string);
    printf("The new string is %s\n", string);
    printf("What word do you want to eliminate?\n");
    fgets(word, 50, stdin);
    word = (char*) realloc(word, sizeof(char) * strlen(word));
    string = delete_last(string, word);
    printf("The new string is %s\n", string);
    string = delete_all(string, word);
    printf("The new string is %s\n", string);
    printf("At which index do you want to insert your word?\n");
    scanf("%d", &n);
    string = insert(string, word, n);
    printf("The new string is %s\n", string);
    histogram(string);
    return 0;
}
