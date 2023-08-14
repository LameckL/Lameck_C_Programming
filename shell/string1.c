#include <stdio.h>
#include "main.h"

/**
 * _strdup - a function duplicating a string in the heap of a memory
 * @s: char pointer
 * Return: string duplicated
 */
char *_strdup(const char *s)
{
	char *newd;
	size_t lenn;

	lenn = _strlen(s);
	newd = malloc(sizeof(char) * (lenn + 1));
	if (newd == NULL)
		return (NULL);
	_memcpy(newd, s, lenn + 1);
	return (newd);
}

/**
 * _strlen - a func that returns the lenght of a string
 * @s: char pointer
 * Return: 0 - success
 */
int _strlen(const char *s)
{
	int lenn;

	for (lenn = 0; s[lenn] != 0; lenn++)
	{
	}
	return (lenn);
}

/**
 * cmp_chars - a function that compare characters of strings
 * @str: input string
 * @delim: delimiter.
 * Return: 1 - if they are equals, 0 - if not
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - this func splits a string by a certain delimiter
 * @str: input string
 * @delim: delimiter
 * Return: splited str
 */
char *_strtok(char str[], const char *delim)
{
	static char *spltd, *str_end;
	char *str_start;
	unsigned int i, bl;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		spltd = str; /*Store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = spltd;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bl = 0; *spltd; spltd++)
	{
		if (spltd != str_start)
			if (*spltd && *(spltd - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*spltd == delim[i])
			{
				*spltd = '\0';
				if (spltd == str_start)
					str_start++;
				break;
			}
		}
		if (bl == 0 && *spltd) /*Str != Delim*/
			bl = 1;
	}
	if (bl == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - a function determining if string passed is a number
 * @s: input string
 * Return: 1 - if string is a number, else 0
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
