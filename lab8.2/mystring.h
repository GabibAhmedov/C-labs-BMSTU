#pragma once
#include <stdio.h>;
#include <math.h>;
#include <malloc.h>

char* strstr(char* s, char* subs);
char* strcpy(char* dest, char* source);
int strlen(char* str);
char* strcat(char* dest, char* src);
void removeSub(char* s, char* sub);
void insertsubstring(char* s, char* sub, int pos);
char* strdel(char* s, int count);
