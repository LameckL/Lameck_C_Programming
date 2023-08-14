#include <stdio.h>
#include "main.h"

/**
 * read_line - a function that reads an input string
 * @i_eof: return value of the function
 * Return: input string
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
