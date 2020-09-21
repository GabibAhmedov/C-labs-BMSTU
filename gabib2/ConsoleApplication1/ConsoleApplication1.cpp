﻿#include <stdio.h>
#include <math.h>

float typeFor(float start, float finish, float step);
float typeWhile(float start, float finish, float step);
float typeDoWhile(float start, float finish, float step);
float function(float i);
float top();
float bottom();
float tablebody(float variable, float functionresult);

int main()
{
	float start, finish, step, amount;
	int type;

	scanf_s("%f", &start);
	scanf_s("%f", &finish);
	scanf_s("%f", &amount);
	scanf_s("%d", &type);


	step = (finish - start) / amount;
	if (finish <= start || amount <= 0)
	{
		printf("incorrect value");
	}
	else if (type == 1)
	{
		typeFor(start, finish, step);
	}
	else if (type == 2)
	{
		typeWhile(start, finish, step);
	}
	else if (type == 3)
	{
		typeDoWhile(start, finish, step);
	}
	else
	{
		printf("incorrect type");

	}
}

float typeFor(float start, float finish, float step)
{
	float functionresult;
	top();
	for (float variable = start; variable < finish; variable = variable + step)
	{
		functionresult = function(variable);
		tablebody(variable, functionresult);
	}
	return 0;
}

float typeWhile(float start, float finish, float step)
{
	float functionresult;
	float variable = start;
	top();
	while (variable < finish)
	{
		functionresult = function(variable);
		tablebody(variable, functionresult);
		variable = variable + step;
	}
	return 0;
}

float typeDoWhile(float start, float finish, float step)
{
	float functionresult;
	float variable = start;
	top();
	do
	{
		functionresult = function(variable);
		tablebody(variable, functionresult);
		variable = variable + step;

	} while (variable < finish);
	return 0;
}

float top()
{
	printf("---------------------------\n");
	printf("|  Variable  |   Answer   |\n");
	printf("---------------------------\n");
	return 0;
}

float tablebody(float variable, float functionresult)
{
	printf("|    %.3f   |    %.3f   |\n", variable, function(variable));
	printf("---------------------------\n");
	return 0;
}


float function(float variable)
{
	return (sin(variable) * sin(variable)) / variable;
}