#ifndef MODULE_H_MODULE
#define MODULE_H_MODULE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *delete_space(char *s);
char *delete_last(char *s, char *w);
char *delete_all(char *s, char *w);
char *insert(char *s, char *w, int ind);
void histogram(char *s);

#endif
