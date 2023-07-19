#include <stdio.h>
/*
 * main - entry point
 * Return: 0 success
 */
int subtract(int a, int b)
{
	return a-b;
}
int main(void)
{
	int c;
	int (*p)(int, int);
	p = &subtract;
	c = (*p)(5,3);
	printf("%d\n", c); /*dereferencing and executing func*/
	return (0);
}
