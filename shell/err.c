#include <stdio.h>
#include "main.h"

/**
 * strcat_cd - this func concatenates the message for cd error
 * @datash: data
 * @msg: message to print
 * @error: message to output
 * @ver_str: counter
 * Return: error
 */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *bad_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		bad_flag = malloc(3);
		bad_flag[0] = '-';
		bad_flag[1] = datash->args[1][1];
		bad_flag[2] = '\0';
		_strcat(error, bad_flag);
		free(bad_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *error_get_cd(data_shell *datash)
{
	int lenn, len_id;
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(datash->args[1]);
	}

	lenn = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	lenn += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(datash, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_not_found - func to handle error message for ‘command not found’
 * @datash: data relevant
 * Return: error message
 */
char *error_not_found(data_shell *datash)
{
	int lenn;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	lenn = _strlen(datash->av[0]) + _strlen(ver_str);
	lenn += _strlen(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (lenn + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * error_exit_shell - func to handle error message for exit in get_exit
 * @datash: data relevant
 * Return:error message
 */
char *error_exit_shell(data_shell *datash)
{
	int lenn;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	lenn = _strlen(datash->av[0]) + _strlen(ver_str);
	lenn += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (lenn + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datash->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
