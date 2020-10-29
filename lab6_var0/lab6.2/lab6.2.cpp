#include <stdio.h>;
#include <math.h>;
#include <malloc.h>


int** allocate(int strings, int columns);
void inputMatrix(int** matrix, int strings, int columns);
void outputMatrix(int** matrix, int strings, int columns);
void swapMinMax(int** matrix, int strings, int columns);
void tallMatrix(int** matrix, int strings,int  columns, int mini, int maxi);
void longMatrix(int** matrix, int strings, int columns, int mini, int maxi);
void squaredMatrix(int** matrix, int strings, int columns, int mini, int maxi);


int main()
{
	int strings, number, distance, columns;
	int** matrix;
	printf("input strings and colums ");
	scanf_s("%d", &strings);
	scanf_s("%d", &columns);
	allocate(strings, columns);
	matrix = allocate(strings, columns);
	inputMatrix(matrix, strings, columns);
	swapMinMax( matrix, strings, columns);
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

void swapMinMax(int** matrix, int strings, int columns)
{
	int square = abs(strings - columns);
	int min = matrix[0][0];
	int max = matrix[0][0];
	int maxi = 0; int maxj = 0;
	int mini = 0; int minj = 0;
	for (int i = 0; i < strings; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{

			if (matrix[i][j] > max)
			{
				max = matrix[i][j]; maxi = i; maxj = j;
			}
			if (matrix[i][j] < min)
			{
				min = matrix[i][j]; mini = i; minj = j;
			}
		}
	}
	if (strings < columns) 
	{
		longMatrix(matrix, strings, columns, mini,  maxi);
	}
	else if (strings > columns)
	{
		tallMatrix(matrix, strings, columns, mini,maxi);
	}
	else
	{
		squaredMatrix(matrix, strings, columns, mini, maxi);
	}
}



void tallMatrix(int** matrix, int strings,int columns, int mini, int maxi)
{
	int tmpMax = max;
	matrix[maxi][maxj] = matrix[strings - 1 - maxj][columns - 1 - maxi + square];
	matrix[strings - 1 - maxj][columns - 1 - maxi + square] = tmpMax;

	int tmpMin = min;
	matrix[mini][minj] = matrix[strings - 1 - minj][columns - 1 - mini + square];
	matrix[strings - 1 - minj][columns - 1 - mini + square] = tmpMin;
}
void longMatrix(int** matrix, int strings, int columns, int mini, int maxi)
{
	int tmpMax = max;
	matrix[maxi][maxj] = matrix[strings - 1 - maxj][columns - 1 - maxi - square];
	matrix[strings - 1 - maxj][columns - 1 - maxi - square] = tmpMax;

	int tmpMin = min;
	matrix[mini][minj] = matrix[strings - 1 - minj][columns - 1 - mini - square];
	matrix[strings - 1 - minj][columns - 1 - mini - square] = tmpMin;
}
void squaredMatrix(int** matrix, int strings, int columns,int mini, int maxi)
{
	int tmpMax = max;
	matrix[maxi][maxj] = matrix[strings - 1 - maxj][strings - 1 - maxi];
	matrix[strings - 1 - maxj][strings - 1 - maxi] = tmpMax;

	int tmpMin = min;
	matrix[mini][minj] = matrix[strings - 1 - minj][strings - 1 - mini];
	matrix[strings - 1 - minj][strings - 1 - mini] = tmpMin;
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