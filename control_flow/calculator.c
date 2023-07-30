#include <stdio.h>
/*
 * main - entry point
 *
 *Description:
 * This program is a calculator that carries out mathematical calculations;
 * adding, subtracting, multiplying and dividing.
 * It allows users to input two numbers and an operator
 * of choice and then shows the outcome of the calculation.
 * Return: 0 - success
 *
 */
int main(void)
{
	char operator = ('+', '-', '*', '/');
	double num1;
	double num2;
	double result;

	printf("Enter the operator (+, -, *, /)\n");
	scanf("%c", &operator);
	printf("Enter the first number:\n");
	scanf("%lf", &num1);
	printf("Enter the second number:\n");
	scanf("%lf", &num2);

	if (operator == '+')
	{
		result = num1 + num2;
		printf("Sum is: %lf\n", result);
	}
	else if (operator == '-')
	{
		result = num1 - num2;
		printf("Subtraction is: %lf\n", result);
	}
	else if (operator == '*')
	{
		result = num1 * num2;
		printf("Multiplication is: %lf\n", result);
	}
	else if (operator == '/')
	{
		result = num1 / num2;
		printf("Division is: %lf\n", result);
	}
	else
	{
		printf("Operator nt applicable\n");
	}
	return (0);
}



