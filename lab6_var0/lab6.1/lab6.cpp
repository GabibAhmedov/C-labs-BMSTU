#include <stdio.h>;
#include <math.h>;
#include <malloc.h>


int** allocate(int strings, int columns);
void inputMatrix(int** matrix, int strings, int columns);
void outputMatrix(int** matrix, int strings, int columns);
void transport(int** matrix, int strings, int columns);

int main()
{
	int strings, number, distance, columns;
	int** matrix;
	printf("input strings and colums ");
	scanf_s("%d", &strings);
	scanf_s("%d", &columns);

	allocate( strings, columns);
	matrix= allocate(strings, columns);
	inputMatrix(matrix, strings, columns);
	transport( matrix,strings,columns);
	outputMatrix(matrix, strings, columns);	
}

int** allocate(int strings, int columns)
{
	int* array = (int*) malloc(strings * columns * sizeof(int));
	int** matrix = (int**)malloc(strings * sizeof(int*));
	for (int i = 0; i < strings; i++)
	{
		matrix[i] = array + i * columns;
	}
	return matrix;
}

void transport(int** matrix, int strings, int columns)
{
	int square = abs(strings - columns);
	if (strings < columns)
	{
		for (int i = 0; i < strings; ++i)
			for (int j = 0; j < columns - i - square; ++j)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[strings - j - 1][columns - i - 1 - square];
				matrix[strings - j - 1][columns - i - 1 - square] = tmp;
			}
	}

	else if (strings > columns)
	{
		for (int i = square; i < strings; ++i)
			for (int j = 0; j < columns - i + square; ++j)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[strings - j - 1][columns - i - 1 + square];
				matrix[strings - j - 1][columns - i - 1 + square] = tmp;
			}
	}
	else
	{


		for (int i = 0; i < strings; ++i)
			for (int j = 0; j < columns - i; ++j)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[strings - j - 1][columns - i - 1];
				matrix[strings - j - 1][columns - i - 1] = tmp;
			}
	}
}

void outputMatrix(int** matrix, int strings, int columns)
{
	for (int i = 0; i < strings; i++) 
	{
		for (int j = 0; j < columns; j++) 
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
}

void inputMatrix(int** matrix, int strings, int columns)
{
	for (int i = 0; i < strings; i++) 
	{
		for (int j = 0; j < columns; j++) 
		{
			scanf_s("%d", &matrix[i][j]);
		}
		printf("\n");
	}
}