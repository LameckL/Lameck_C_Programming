#include <stdio.h>
#include "main.h"

/**
 * check_env - a function checking if the typed variable
 * is an environment variable
 * @h: linked list head
 * @in: input string
 * @data: data structure
 * Return: none
 */
void check_env(r_var **h, char *in, data_shell *data)
{
	int j, row, ch, l_vl;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, ch = 0; _envr[row][ch]; ch++)
		{
			if (_envr[row][ch] == '=')
			{
				l_vl = _strlen(_envr[row] + ch + 1);
				add_rvar_node(h, j, _envr[row] + ch + 1, l_vl);
				return;
			}

			if (in[j] == _envr[row][ch])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_rvar_node(h, j, NULL, 0);
}

/**
 * check_vars - this func checks if the typed variable is $$ or $?
 * @h: linked list head
 * @in: input string
 * @st: last status of shell
 * @data: data structure
 * Return: none
 */
int check_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int i, lt, ld;

	lt = _strlen(st);
	ld = _strlen(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_rvar_node(h, 2, st, lt), i++;
			else if (in[i + 1] == '$')
				add_rvar_node(h, 2, data->pid, ld), i++;
			else if (in[i + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + i, data);
		}
	}

	return (i);
}

/**
 * replaced_input - func replacing string with variables
 * @head: linked list head
 * @input: input string
 * @new_input: new input string - replaced
 * @nlen: new length
 * Return: string replaced
 */
char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *ind;
	int i, j, k;

	ind = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(ind->len_var) && !(ind->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (ind->len_var && !(ind->len_val))
			{
				for (k = 0; k < ind->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < ind->len_val; k++)
				{
					new_input[i] = ind->val[k];
					i++;
				}
				j += (ind->len_var);
				i--;
			}
			ind = ind->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * rep_var - function call to replace string with variable
 * @input: string input
 * @datash: data structure
 * Return: replaced string
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *ind;
	char *sts, *new_input;
	int olen, nlen;

	sts = aux_itoa(datash->sts);
	head = NULL;

	olen = check_vars(&head, input, sts, datash);

	if (head == NULL)
	{
		free(sts);
		return (input);
	}

	ind = head;
	nlen = 0;

	while (ind != NULL)
	{
		nlen += (ind->len_val - ind->len_var);
		ind = ind->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(sts);
	free_rvar_list(&head);

	return (new_input);
}
