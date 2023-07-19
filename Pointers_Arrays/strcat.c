#include <stdio.h>
#include <string.h>
/*
 * main - entry point
 * Return: 0 success
 */
int main(void)
{
	char fname [20] = "Lameck";
	char lname [20] = "Kipruto";
	int len1, len2;
	len1 = strlen(fname);
	len2 = strlen(lname);
	strcat(fname, lname); /**concatenate two strings**/
	strcat(lname, fname);
	printf("%d\n", len1);
	printf("%d\n", len2);
	printf("%s\n", fname);
	printf("%s\n", lname);
	return (0);
}

