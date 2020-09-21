

#include <stdio.h>;
#include <math.h>;

float calculation(float begin, float end, float amount);

int main()
{
	float begin, end, accuracy,step,amount,calculationX1,calculationX2 ;
	scanf_s("%f", &begin);
	scanf_s("%f", &end);
	scanf_s("%f", &accuracy);
	amount = 1;
	 calculationX2 = calculation(begin, end, amount);
	do
	{
		calculationX1 = calculationX2;
		amount = amount * 2;
		calculationX2 = calculation(begin, end, amount);

	} while ((calculationX2 - calculationX1) >= accuracy);
	printf("%.15f",calculationX2);
	//printf("%.6f", calculation(begin, end, amount));
}

float calculation(float begin, float end, float amount)
{
	
	float step; step = (end - begin) / (2 * amount);
	float begincalcu; begincalcu = log(begin);
	float endcalcu; endcalcu = log(end);
	float summchet; summchet = 0;
	float summnechet; summnechet = 0;
	for (int i = 1; i < (2 * amount)-1; i = i + 1)
	{
		float uzel; uzel = begin + i * step;
		if (i % 2 == 0)
		{
			 summchet = summchet + log(uzel);
		}
		else
		{
			 summnechet = summnechet + log(uzel);
		}
	}
	float finalsumm; finalsumm = (step /3) * (begincalcu + (4 * summnechet) + (2 * summchet) + endcalcu);
	return finalsumm;
	//printf("%f%f%f%f", begincalcu, summnechet, summchet, endcalcu);
}