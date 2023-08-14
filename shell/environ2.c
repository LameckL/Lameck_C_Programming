#include <stdio.h>
#include "main.h"
/**
 * copy_info - a function that copies the information to create a new environment or alias
 * @name: name of environment or alias
 * @value: value of alias or environment
 * Return: new env or alias
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int lenn_name, lenn_value, len;

	lenn_name = _strlen(name);
	lenn_value = _strlen(value);
	len = lenn_name + lenn_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - a function that sets an environment variable
 * @name: name of variable
 * @value: value of the variable
 * @datash: data structure
 * Return: none
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int i;
	char *env_var, *env_name;

	for (i = 0; datash->_environ[i]; i++)
	{
		env_var = _strdup(datash->_environ[i]);
		env_name = _strtok(env_var, "=");
		if (_strcmp(env_name, name) == 0)
		{
			free(datash->_environ[i]);
			datash->_environ[i] = copy_info(env_name, value);
			free(env_var);
			return;
		}
		free(env_var);
	}

	datash->_environ = _reallocdp(datash->_environ, i, sizeof(char *) * (i + 2));
	datash->_environ[i] = copy_info(name, value);
	datash->_environ[i + 1] = NULL;
}

/**
 * _setenv - a function that compares environment variables names containing
 * the name passed
 * @datash: data
 * Return: 1 - success.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - a function that deletes an environment variable
 * @datash: data
 * Return: 1 - success.
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *env_var, *env_name;
	int i, j, k;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->_environ[i]; i++)
	{
		env_var = _strdup(datash->_environ[i]);
		env_name = _strtok(env_var, "=");
		if (_strcmp(env_name, datash->args[1]) == 0)
		{
			k = i;
		}
		free(env_var);
	}
	if (k == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = datash->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash->_environ[k]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
