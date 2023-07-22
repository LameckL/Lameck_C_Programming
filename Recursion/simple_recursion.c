#include <stdio.h>
/*
 * print - function that perforn recursion and display numbers
 * main - entry point
 * Return: 0 success
 */
void print(int n)
{
	if (n < 1)
		return;
	else
	{
		printf("%d", n);
		print(n - 1);
		printf("%d", n);
	}
}
int main(void)
{
	int n = 5;
	print(n);
	return (0);
}

