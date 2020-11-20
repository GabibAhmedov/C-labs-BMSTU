#include <stdio.h>;
#include <math.h>;
#include <malloc.h>
#include "mystring.h";

#define STRING_MAX_LEMGTH 100

char** allocate(int strings, int maxLen);
void inputStrings(char** stringArray, char strings, char maxLen);
void outputStrings(char** stringArray, char strings, char maxLen);
void replaceSuf(char** stringArray, char strings, char maxLen, char* suf1, char* suf2);
int main()
{
	char** stringArray;
	int strings, maxLen;
	scanf_s("%d", &strings);
	getchar();
	//scanf_s("%d\n", &maxLen);
	char* suf1 = (char*)malloc(STRING_MAX_LEMGTH * sizeof(int));
	char* suf2 = (char*)malloc(STRING_MAX_LEMGTH * sizeof(int));
	stringArray = allocate(strings, STRING_MAX_LEMGTH);
	fgets(suf1, STRING_MAX_LEMGTH, stdin);
	suf1[strlen(suf1) - 1] = '\0';
	fgets(suf2, STRING_MAX_LEMGTH, stdin);
	suf2[strlen(suf2) - 1] = '\0';
	inputStrings(stringArray, strings, STRING_MAX_LEMGTH);
	outputStrings(stringArray, strings, STRING_MAX_LEMGTH);
	//removeSub(stringArray[0], suf1);
	replaceSuf(stringArray, strings, STRING_MAX_LEMGTH, suf1, suf2);
	outputStrings(stringArray, strings, STRING_MAX_LEMGTH);
	//getchar();
}

void replaceSuf(char** stringArray, char strings, char maxLen, char* suf1, char* suf2)
{
	char space[] = " ";
	for (int i = 0; i < strings; i++)
	{
		char* tempString = (char*)malloc(strings * sizeof(char));
		strcpy(tempString, stringArray[i]);
		int spaceIndex = strstr(stringArray[i], space) - stringArray[i];
		stringArray[i][spaceIndex + 1] = '\0';
		strdel(tempString, strlen(stringArray[i]));	
		int suf1index = strstr(stringArray[i], suf1) - stringArray[i];
		removeSub(stringArray[i], suf1);
		insertsubstring(stringArray[i], suf2, suf1index);
		//strins(tempString,stringArray[i]);
		strcat(stringArray[i], tempString);
	}
}
void inputStrings(char** stringArray, char strings, char maxLen)
{
	for (int i = 0; i < strings; i++)
	{
		fgets(stringArray[i], maxLen, stdin);
	}
}

void outputStrings(char** stringArray, char strings, char maxLen)
{
	for (int i = 0; i < strings; i++)
	{
		puts(stringArray[i]);
	}
}

char** allocate(int strings, int maxLen)
{
	char* array = (char*)malloc(strings * maxLen * sizeof(char));
	char** stringArray = (char**)malloc(strings * sizeof(char*));
	for (int i = 0; i < strings; i++)
	{
		stringArray[i] = array + i * maxLen;
	}
	return stringArray;
}