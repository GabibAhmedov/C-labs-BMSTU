
#include <stdio.h>;
#include <math.h>;
#include <malloc.h>


char* strstr(char* s, char* subs)
{
	char* q, * p = s, * qs = subs;
	int check = 1;
	while (*p && *qs && check)
	{
		for (q = p, qs = subs; *q && *q == *qs; q++, qs++);
		if (!(*qs && *q))
		{
			check = 0;
		}
		else
		{
			p++;
		}
	}
	return *p ? p : NULL;
}

int strlen(char* str)
{
	int len;
	for (len = 0; str[len]; len++);
	return len;
}

char* strcpy(char* dest, char* source)
{
	for (int i = 0; dest[i] = source[i]; i++);
	return dest;
}

char* strcat(char* dest, char* src)
{
	char* p;
	for (p = dest; *p; p++);
	for (int i = 0; p[i] = src[i]; i++);
	return dest;
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

void insertsubstring(char* s, char* sub, int pos)
{
	//char* copy = (char*)malloc(strlen(s) * sizeof(char));
	char copy[100] = "";
	strcpy(copy, s);
	s[pos] = '\0';
	strcat(s, sub);
	strcat(s, copy + pos);
	//free(copy);
}

char* strins(char* s, char* sub)
{
	char* tmp = (char*)malloc(strlen(s) * sizeof(char));
	strcpy(tmp, s);
	strcpy(s, sub);
	strcat(s, tmp);
	//free(tmp);
	return(s);
}