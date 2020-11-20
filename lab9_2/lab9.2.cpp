#include <stdio.h>;
#include <math.h>;
#include <malloc.h>
#include <string.h>
#define MAX_LENGTH 500

void gets(char* str);
char* strdel(char* s, int count);
void counteachword(char* text);
char* strcpy(char* dest, char* source);
void removeSub(char* s, char* sub);
void formatText(char* text, int width);
int main()
{
	char* text = (char*)malloc(MAX_LENGTH * sizeof(char));
	int width = 0;
	gets(text);
	scanf_s("%d", &width);
	formatText(text, width);
	puts(text);
}

void formatText(char* text,int width)
{
	char space[] = " ";
	int lastspace = 0;
	
	for (lastspace = width; lastspace < strlen(text); lastspace = lastspace + width)
	{
		if (text[lastspace] == space[0])
		{
			text[lastspace] = '\n';

		}
		else
		{
			int constlastspace = lastspace;
			for (int j = 0; j < constlastspace; j++)
			{
				if (text[j] == space[0])
				{
					lastspace = j;
				}
			}
			text[lastspace] = '\n';
		}
	}


}
void gets(char* str)
{
	fgets(str, MAX_LENGTH, stdin);
	str[strlen(str) - 1] = ' ';
	str[strlen(str)] = '\0';
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