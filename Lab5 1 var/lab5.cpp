#include <stdio.h>;
#include <math.h>;
#include <malloc.h>

float imputArray(float* array, int amount);
float group(float* array, int amount);
float bubleSort(float* array, int amount);
float outputArray(float* array, int size);
int main()
{

	int size;
	printf("type number of elements ");
	scanf_s("%d", &size);
	float* array = (float*)malloc(size * sizeof(float));
	imputArray(array, size);
	bubleSort(array, size);
	group(array, size);
	outputArray(array, size);
}

float imputArray(float* array, int size)
{
	for (int i = 0; i < size; i = i + 1)
	{
		scanf_s("%f", &array[i]);
	}
	return 0;
}

float bubleSort(float* array, int size)
{
	for (int i = 1; i < size; i++)
		for (int j = 1; j < size; j++)
			if (array[j - 1] > array[j])
			{
				float tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
	return 0;
}

float group(float* array, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (array[i] < 0)
		{
			float tmp;
			float tmp2 = array[i];
			float tmp1 = array[size - 1];
			for (int j = size - 2; j >= i; j--)
			{
				tmp = array[j];
				array[j] = tmp1;
				tmp1 = tmp;

			}
			array[size - 1] = tmp2;
		}
	}

	for (int i = size - 1; i >= 0; i--)
	{
		if (array[i] == 0)
		{
			float tmp;
			float tmp2 = array[i];
			float tmp1 = array[size - 1];
			for (int j = size - 2; j >= i; j--)
			{
				tmp = array[j];
				array[j] = tmp1;
				tmp1 = tmp;

			}
			array[size - 1] = tmp2;
		}
	}
	return 0;
}

float outputArray(float* array, int size)
{
	for (int i = 0; i < size; i = i + 1)
	{
		printf("%.0f ", array[i]);
	}
	return 0;
}