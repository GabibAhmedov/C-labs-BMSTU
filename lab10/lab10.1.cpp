#include <stdio.h>;
#include <math.h>;
#include <malloc.h>
#include <string.h>
#define MAX_NAME_SiZE 50

struct student
{
	char* name = (char*)malloc( MAX_NAME_SiZE * sizeof(char));
	int* grades = (int*)malloc(5 * sizeof(int));
	int  avgGrade = 0;
};
struct count
{
	int countOtl=0;
	int countHor=0;
	int countTro=0;
	int countDvo=0;
};

void inputArray(student* studentArray, int numberOfStudents);
void outputArrays(student* otlArray, student* horArray, student* troArray, student* dvoArray, count* counts);
void groupStudents(student* studentArray, student* otlArray, student* horArray, student* troArray, student* dvoArray, int numberOfStudents,count* counts);
void gets(char* str);
void countAvg(student* studentArray, int numberOfStudents);
void sortbyAlphabet(student* array, count* counts);
void swap(student* s1, student* s2);
void remove2dvo(student* dvoArray,count* counts);

int main()
{	
	int numberOfStudents = 0;
	printf("input number of students");
	scanf_s("%d", &numberOfStudents);
	getchar();
	count counts;
	student* studentArray = (student*)malloc( numberOfStudents* sizeof(student));
	student* otlArray= (student*)malloc(numberOfStudents * sizeof(student));
	student* horArray = (student*)malloc(numberOfStudents * sizeof(student));
	student* troArray = (student*)malloc(numberOfStudents * sizeof(student));
	student* dvoArray = (student*)malloc(numberOfStudents * sizeof(student));
	inputArray(studentArray,numberOfStudents);
	countAvg(studentArray, numberOfStudents);
	groupStudents(studentArray,  otlArray,  horArray,  troArray,  dvoArray,  numberOfStudents, &counts);
	sortbyAlphabet(otlArray, &counts);
	sortbyAlphabet(horArray, &counts);
	sortbyAlphabet(troArray, &counts);
	sortbyAlphabet(dvoArray, &counts);
	remove2dvo(dvoArray, &counts);
	outputArrays(otlArray, horArray, troArray, dvoArray,&counts);
}
void remove2dvo(student* dvoArray, count* counts)
{
	for (int i = 0; i < counts->countDvo; i++)
	{
		int number = 0;
		for (int j = 0; j < 4; j++)
		{
			if (dvoArray[i].grades[j] == 2)
			{
				number++;
			}
		}
		if (number >= 2)
		{
			for (int k = i; k < counts->countDvo; k++)
			{
				dvoArray[k] = dvoArray[k + 1];
				
			}
			i--;
		}
	}
}

student inputStudent()
{
	student result;
	printf("input name");
	gets(result.name);
	printf("input 5 grades");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d",&result.grades[i]);
	}
	getchar();
	return result;
}
void gets(char* str)
{
	fgets(str, MAX_NAME_SiZE, stdin);
	str[strlen(str) - 1] = '\0';
}

void countAvg(student* studentArray,int numberOfStudents)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		studentArray[i].avgGrade = (studentArray[i].grades[0] + studentArray[i].grades[1] + studentArray[i].grades[2] + studentArray[i].grades[3] + studentArray[i].grades[4]) / 5;
	}
}

void groupStudents(student*studentArray,student*otlArray,student*horArray, student* troArray, student* dvoArray,int numberOfStudents, count* counts)
{
	
	for (int i = 0; i < numberOfStudents; i++)
	{
		if (studentArray[i].grades[0] == 5 && studentArray[i].grades[1] == 5 && studentArray[i].grades[2] == 5 && studentArray[i].grades[3] == 5 && studentArray[i].grades[4] == 5)
		{
			otlArray[counts->countOtl] = studentArray[i];
			counts->countOtl++;
		} 
		else if (studentArray[i].grades[0] >=4 && studentArray[i].grades[1] >= 4 && studentArray[i].grades[2] >= 4 && studentArray[i].grades[3] >= 4 && studentArray[i].grades[4] >= 4)
		{
			horArray[counts->countHor] = studentArray[i];
			counts->countHor++;
		}
		else if (studentArray[i].grades[0] >= 3 && studentArray[i].grades[1] >= 3 && studentArray[i].grades[2] >= 3 && studentArray[i].grades[3] >= 3 && studentArray[i].grades[4] >= 3)
		{
			troArray[counts->countTro] = studentArray[i];
			counts->countTro++;
		}
		else 
		{
			dvoArray[counts->countDvo] = studentArray[i];
			counts->countDvo++;
		}

	}

}
void sortbyAlphabet(student* array, count* counts)
{
	for (int i = 0; i < counts->countOtl; i++)
	{
		for (int j = i + 1; j < counts->countOtl; j++)
		{
			if (strcmp(array[i].name, array[j].name) > 0)
			{
				swap(&array[i], &array[j]);
			}
		}
	}
}

void swap(student* s1, student* s2)
{
	student tmp;
	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void outputArrays(student* otlArray, student* horArray, student* troArray, student* dvoArray,count* counts)
{
	printf("olt: \n");
	for (int i = 0; i < counts->countOtl; i++)
	{
		printf("%s\n", otlArray[i].name);
	}

	printf("hor: \n");
	for (int i = 0; i<counts->countHor; i++)
	{
		printf("%s\n", horArray[i].name);
	}
	printf("tro: \n");
	for (int i = 0;i< counts->countTro; i++)
	{
		printf("%s\n", troArray[i].name);

	}
	printf("dvo: \n");
	for (int i = 0; i<counts->countDvo; i++)
	{
		printf("%s\n", dvoArray[i].name);
	}
}

void inputArray(student* studentArray,int numberOfStudents)
{
	for (int i = 0; i < numberOfStudents; i++)
		studentArray[i] = inputStudent();
}