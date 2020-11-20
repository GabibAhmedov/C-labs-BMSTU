#include <stdio.h>;
#include <math.h>;
#include <malloc.h>
#include <string.h>
#define MAX_LENGTH 100

void gets(char* str);
char* strdel(char* s, int count);
void counteachword(char* text);
char* strcpy(char* dest, char* source);
void removeSub(char* s, char* sub);
int main()
{
	char* text = (char*)malloc(MAX_LENGTH * sizeof(char));
	gets(text);
	puts(text);
	printf("\n");

	counteachword(text);
}


void gets(char* str)
{
	fgets(str, MAX_LENGTH, stdin);
	str[strlen(str) - 1] = ' ';
	str[strlen(str)] = '\0';
}

void counteachword(char* text)
{
	char space[] =" ";
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == space[0])
		{
			int count=0;
			char* word = (char*)malloc(MAX_LENGTH * sizeof(char));
			strcpy(word, text);
			word[i+1] = '\0';
			if (strlen(text) > strlen(word))
			{
				strdel(text, strlen(word));
				count = 1;
			}
			while (strstr(text, word)!=NULL)
			{
				count++;
				removeSub(text, word);	
			}
			printf("%s------------%d", word, count);
			printf("\n");
			i = 0;
		}
	}
}

char* strdel(char* s, int count)
{
	if (strlen(s) < count)
	{
		s[0] = '\0';
	}
	else
	{
		strcpy(s, s + count);
	}
	return s;
}

void removeSub(char* s, char* sub)
{
	char* tmp = strstr(s, sub);
	strcpy(tmp, tmp + strlen(sub));
}

char* strcpy(char* dest, char* source)
{
	for (int i = 0; dest[i] = source[i]; i++);
	return dest;
}
