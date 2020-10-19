#include <stdio.h>;
#include <math.h>;
#include <malloc.h>


int** allocate(int strings, int columns);
void inputMatrix(int** matrix, int strings, int columns);
void outputMatrix(int** matrix, int strings, int columns);
int spiralSort(int** matrix, int* tempArray, int strings, int columns);

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
				if (j != countC - 1)
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

					if (i != countS - 1) 
{
						if ((matrix[i + 1][j] < matrix[i][j]))
						{
							int tmp = matrix[i + 1][j];
							matrix[i + 1][j] = matrix[i][j];
							matrix[i][j] = tmp;
						}
					}

				}
			}
			j--;
			i++;
			for (; i < countS; i++)
			{
				if (i != countS - 1)
				{
					if (matrix[i + 1][j] < matrix[i][j])
					{
						int tmp = matrix[i + 1][j];
						matrix[i + 1][j] = matrix[i][j];
						matrix[i][j] = tmp;
					}
				}
				else
				{

					if (j != columns - countC) {

						if ((matrix[i][j - 1] < matrix[i][j]))
						{
							int tmp = matrix[i][j - 1];
							matrix[i][j - 1] = matrix[i][j];
							matrix[i][j] = tmp;
						}
					}

				}
			}
			i--;
			j--;
			for (; j >= columns - countC; j--)
			{
				if (j != columns - countC)
				{
					if (matrix[i][j-1] < matrix[i][j])
					{
						int tmp = matrix[i][j - 1];
						matrix[i][j - 1] = matrix[i][j];
						matrix[i][j] = tmp;
					}
				}
				else
				{
					if (i != strings - countS)
					{

						if ((matrix[i - 1][j] < matrix[i][j]))
						{
							int tmp = matrix[i - 1][j];
							matrix[i - 1][j] = matrix[i][j];
							matrix[i][j] = tmp;
						}
					}

				}
			}

			j++;
			i--;
			countS--;
			for (; i >= strings - countS; i--)
			{
				if (i != strings - countS)
				{
					if (matrix[i - 1][j] < matrix[i][j])
					{
						int tmp = matrix[i - 1][j];
						matrix[i - 1][j] = matrix[i][j];
						matrix[i][j] = tmp;
					}
				}
				else
				{

					if (j != countC - 1) 
					{


						if ((matrix[i][j + 1] < matrix[i][j]))
						{
							int tmp = matrix[i][j + 1];
							matrix[i][j + 1] = matrix[i][j];
							matrix[i][j] = tmp;
						}
					}

				}
			}
			i++;
			j++;
			countC--;
		} while (countS > 0 && countC > 0);
		
	}
	return 0;
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