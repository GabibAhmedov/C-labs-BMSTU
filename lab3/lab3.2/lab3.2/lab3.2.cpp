

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
	float step, uzel, summchet,summnechet,begincalcu,endcalcu,finalsumm;
	step = (end - begin) / (2 * amount);
	begincalcu = log(begin);
	endcalcu = log(end);
	summchet = 0;
	summnechet = 0;
	for (int i = 1; i < (2 * amount)-1; i = i + 1)
	{
		uzel = begin + i * step;
		if (i % 2 == 0)
		{
			summchet = summchet + log(uzel);
		}
		else
		{
			summnechet = summnechet + log(uzel);
		}
	}
	finalsumm = (step /3) * (begincalcu + (4 * summnechet) + (2 * summchet) + endcalcu);
	return finalsumm;
	//printf("%f%f%f%f", begincalcu, summnechet, summchet, endcalcu);
}