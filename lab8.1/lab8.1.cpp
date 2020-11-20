#include <stdio.h>;
#include <math.h>;
#include <malloc.h>
#include "mystring.h";

void removeExtraSpaces(char* string);

int main()
{
	char string[50];
	fgets(string,50,stdin);
	puts(string);
	removeExtraSpaces(string);
	puts(string);
}

 void removeExtraSpaces(char* string)
{
	 char* probelPos;
	 char subString [] = "  ";
	 while (probelPos = strstr(string, subString))
		 strcpy(probelPos, probelPos + 1);
}