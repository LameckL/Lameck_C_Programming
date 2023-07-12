#include <stdio.h>
/*
 * main - entry point
 * Return: 0 - success
 */
int main(void)
{
	char name[20];
	printf("Enter your name: ");
	scanf("%s", name);
	puts(name);
	return (0);
}
