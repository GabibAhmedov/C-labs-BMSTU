#include <stdio.h>;
#include <math.h>;
#include <malloc.h>


int** allocate(int strings, int columns);
void inputMatrix(int** matrix, int strings, int columns);
void outputMatrix(int** matrix, int strings, int columns);
int snakeSort(int** matrix, int* tempArray, int strings, int columns);
void evenStrings(int** matrix, int strings, int columns, int i, int j);
void oddStrings(int** matrix, int strings, int columns, int i, int j);

int main()
{
	int strings, number, distance, columns;
	int** matrix;
	printf("input strings and colums ");
	scanf_s("%d", &strings);
	scanf_s("%d", &columns);
	allocate(strings, columns);
	matrix = allocate(strings, columns);
	int* tempArray = (int*)malloc(strings * sizeof(int));
	inputMatrix(matrix, strings, columns);
	snakeSort(matrix, tempArray, strings, columns);
	outputMatrix(matrix, strings, columns);
}

int** allocate(int strings, int columns)
{
	int* array = (int*)malloc(strings * columns * sizeof(int));
	int** matrix = (int**)malloc(strings * sizeof(int*));
	for (int i = 0; i < strings; i++)
	{
		matrix[i] = array + i * columns;
	}
	return matrix;
}

int snakeSort(int** matrix, int* tempArray, int strings, int columns)
{
	for (int k = 0; k < strings * columns; ++k)
	{
		for (int i = 0; i < strings; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{	
				if (i % 2 == 0)
				{
					evenStrings(matrix, strings, columns, i, j);
				}
				else 
				{
					oddStrings(matrix, strings, columns, i, j);
				}
			}
		}
	}
	return 0;
}

void evenStrings(int** matrix,int strings,int columns,int i, int j)
{
	if (j != columns - 1)
	{
		if (matrix[i][j + 1] < matrix[i][j])
		{
			int tmp = matrix[i][j + 1];
			matrix[i][j + 1] = matrix[i][j];
			matrix[i][j] = tmp;
		}
	}
	else
	{
		if (i != strings - 1)
		{
			if ((matrix[i + 1][columns - 1] < matrix[i][j]))
			{
				int tmp = matrix[i + 1][columns - 1];
				matrix[i + 1][columns - 1] = matrix[i][j];
				matrix[i][j] = tmp;
			}
		}
	}
}
void oddStrings(int** matrix, int strings, int columns, int i, int j)
{
	if (j != 0)
	{
		if (matrix[i][columns - j - 1] < matrix[i][columns - j])
		{
			int tmp = matrix[i][columns - j - 1];
			matrix[i][columns - j - 1] = matrix[i][columns - j];
			matrix[i][columns - j] = tmp;
		}
	}
	else
	{
		if (i != strings - 1)
		{
			if ((matrix[i + 1][0] < matrix[i][j]))
			{
				int tmp = matrix[i + 1][0];
				matrix[i + 1][0] = matrix[i][j];
				matrix[i][j] = tmp;
			}
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