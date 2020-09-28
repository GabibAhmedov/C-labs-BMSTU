
#include <stdio.h>;
#include <math.h>;

float imputArray(float* array, int amount);
float findmaxindex(float* array, int amount);
float findlastzero(float* array, int amount);
int main()
{
	float array[10000];
	int amount;
	printf("type number of elements");
	scanf_s("%d", &amount);
	imputArray(array, amount);
	int maxi = findmaxindex(array, amount);

	int lastzero = findlastzero(array, amount);


	float summ = 0, count = 0, avg = 0;
	for (int i = lastzero; i <= maxi; i = i + 1)
	{
		summ = summ + array[i];
		count = count + 1;
	}

	avg = summ / count;
	printf("%.3f", avg);
	
}

float imputArray(float *array,int amount)
{
	for (int i = 0; i < amount; i = i + 1)
	{
		scanf_s("%f", &array[i]);
	}
	return 0;
}

float findmaxindex(float* array, int amount)
{
	float max = array[0];
	int maxi = 0;
	for (int i = 0; i < amount; i = i + 1)
	{
		if (array[i] > max)
		{
			max = array[i];
			maxi = i;
		}
	}
	return maxi;
}
float findlastzero(float* array, int amount)
{
	int lastzero = 0;
	for (int i = 0; i < amount; i = i + 1)
	{
		if (array[i] == 0)
		{
			lastzero = i;
		}
	}
	return lastzero;
}
