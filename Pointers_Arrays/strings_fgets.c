#include <stdio.h>
/*
 *  * main - entry point
 *   * Return: 0 success
 *    */
int main(void)
{
	char name[20];
	printf("Enter your name: ");
	fgets(name, sizeof(name), stdin);
	printf("your name is %s\n", name);
	return (0);
}

