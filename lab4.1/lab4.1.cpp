
#include <stdio.h>;
#include <math.h>;

float imputArray(float* array, int amount);
float findMaxIndex(float* array, int amount);
float findLastZero(float* array, int amount);
float avg(float avg, float count);

int main()
{
	float array[10000];
	int amount;
	printf("type number of elements");
	scanf_s("%d", &amount);
	imputArray(array, amount);
	int maxi = findMaxIndex(array, amount);

	int lastzero = findLastZero(array, amount);


	float summ = 0, count = 0;
	for (int i = lastzero; i <= maxi; i = i + 1)
	{
		summ = summ + array[i];
		count = count + 1;
	}

	printf("%.3f", avg(summ,count));
	
}

float imputArray(float *array,int amount)
{
	for (int i = 0; i < amount; i = i + 1)
	{
		scanf_s("%f", &array[i]);
	}
	return 0;
}

float findMaxIndex(float* array, int amount)
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
float findLastZero(float* array, int amount)
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
float avg(float summ, float count)
{
	return summ / count;
}
