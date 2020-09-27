
#include <stdio.h>;
#include <math.h>;
float array[10000];
int main()
{
	int amount;
	printf("type number of elements");
	scanf_s("%d", &amount);
	float max = -1000000;
	int maxi = 0;
	for (int i = 0; i < amount; i = i + 1)
	{
		scanf_s("%f", &array[i]);
		if (array[i] > max)
		{
			max = array[i];
			maxi = i;
		}
	}

	int lastzero = 0;
	for (int i = 0; i < amount; i = i + 1)
	{
		if (array[i] == 0) 
		{
			lastzero = i;
		}
	}

	float summ = 0, count = 0, avg = 0;
	for (int i = lastzero; i < maxi; i = i + 1)
	{
		summ = summ + array[i];
		count = count + 1;
	}

	avg = summ / count;
	printf("%f", avg);
	
}