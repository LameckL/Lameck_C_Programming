#include <stdio.h>
#include "main.h"

/**
 * error_env - func handling error msg for environment in get_env
 * @datash: data; args, counter
 * Return: error message
 */
char *error_env(data_shell *datash)
{
	int lenn;
	char *message;
	char *error;
	char *r_str;

	r_str = aux_itoa(datash->counter);
	message = ": Unable to add/remove from environment\n";
	lenn = _strlen(datash->av[0]) + _strlen(r_str);
	lenn += _strlen(datash->args[0]) + _strlen(message) + 4;
	error = malloc(sizeof(char) * (lenn + 1));
	if (error == 0)
	{
		free(error);
		free(r_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, r_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, message);
	_strcat(error, "\0");
	free(r_str);

	return (error);
}
/**
 * error_path_126 - this func handles error message
 * for path failure denied permission
 * @datash: data; args, counter
 * Return: string error
 */
char *error_path_126(data_shell *datash)
{
	int lenn;
	char *r_str;
	char *error;

	r_str = aux_itoa(datash->counter);
	lenn = _strlen(datash->av[0]) + _strlen(r_str);
	lenn += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (lenn + 1));
	if (error == 0)
	{
		free(error);
		free(r_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, r_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(r_str);
	return (error);
}
