#include <stdio.h>
/*
 * main - entry point
 * Return: 0 success
 */
int main(void)
{
	char name[20];
        printf("Using scanf to input string, Please enter your name: ");
	scanf("%s", name);
	printf("Your name is: %s\n", name);
	return (0);
}
