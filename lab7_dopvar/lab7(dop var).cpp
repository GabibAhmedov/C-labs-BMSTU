#include <stdio.h>;
#include <math.h>;
#include <malloc.h>


int** allocate(int strings, int columns);
void inputMatrix(int** matrix, int strings, int columns);
void outputMatrix(int** matrix, int strings, int columns);
int spiralSort(int** matrix, int* tempArray, int strings, int columns);
void moveToRightSide(int** matrix, int strings, int columns, int i, int j, int countS, int countC);
void moveToBottom(int** matrix, int strings, int columns, int i, int j, int countS, int countC);
void moveToLeftSide(int** matrix, int strings, int columns, int i, int j, int countS, int countC);
void moveToTop(int** matrix, int strings, int columns, int i, int j, int countS, int countC);
void swapElements(int** matrix, int index1, int index2);

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
	spiralSort(matrix, tempArray, strings, columns);
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

int spiralSort(int** matrix, int* tempArray, int strings, int columns)
{
	for (int k = 0; k < strings * columns; ++k)
	{
		int i = 0;
		int j = 0;
		int countS = strings;
		int countC = columns;
		do
		{
			for (; j < countC; j++)
			{
				moveToRightSide(matrix, strings, columns, i, j,countC);
			}
			j--;
			i++;
			for (; i < countS; i++)
			{
				moveToBottom(matrix, strings, columns, i, j,countS);
			}
			i--;
			j--;
			for (; j >= columns - countC; j--)
			{
				moveToLeftSide(matrix, strings, columns, i, j,countC);
			}

			j++;
			i--;
			countS--;
			for (; i >= strings - countS; i--)
			{
				moveToTop(matrix, strings, columns, i, j,countS);
			}
			
			i++;
			j++;
			countC--;
		} while (countS > 0 && countC > 0);
		
	}
	return 0;
}


void moveToRightSide(int** matrix, int strings, int columns, int i, int j, int countS, int countC)
{
	if (j != countC - 1)
	{
		swapElements(matrix, i, j,i, j+1);

	}
	else
	{

		if (i != countS - 1)
		{
			swapElements(matrix, i, j, i+1, j);

		}

	}
}

void moveToBottom(int** matrix, int strings, int columns, int i, int j, int countS, int countC)
{
	
		if (i != countS - 1)
		{
			swapElements(matrix, i, j, i + 1, j);
	
		}
		else
		{

			if (j != columns - countC)
			{
				swapElements(matrix, i, j, i, j - 1);
			}
	

		}
	
}

void moveToLeftSide(int** matrix, int strings, int columns, int i, int j, int countS, int countC)
{
	if (j != columns - countC)
	{
		swapElements(matrix, i, j, i, j - 1);

	}
	else
	{
		if (i != strings - countS)
		{
			swapElements(matrix, i, j, i-1, j);
		
		}

	}
}

void moveToTop(int** matrix, int strings, int columns, int i, int j, int countS, int countC)
{

			if (i != strings - countS)
			{
				swapElements(matrix, i, j, i - 1, j);
		
			}
			else
			{

				if (j != countC - 1)
				{

					swapElements(matrix, i, j, i, j+1);
		
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

void swapElements(int** matrix, int i, int j, int iAlt, int jAlt)
{
	if (matrix[iAlt][jAlt] < matrix[i][j])
	{
		int tmp = matrix[iAlt][jAlt];
		matrix[iAlt][jAlt] = matrix[i][j];
		matrix[i][j] = tmp;
	}
}