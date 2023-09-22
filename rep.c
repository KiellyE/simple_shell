#include "shell.h"

/**
 * check_env - checks if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void check_env(r_var15 **h, char *in, data_shell_15 *data)
{
	int row, chr, j, lval;
	char **_envr;

	envr = data->_environ15;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = strlen15(_envr[row] + chr + 1);
				add_rvar_node(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
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
 * check_vars - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int check_vars(r_var15 **h, char *in, char *st, data_shell_15 *data)
{
	int m, lst, lpd;

	lst = strlen15(st);
	lpd = strlen15(data->pid15);

	for (m = 0; in[m]; m++)
	{
		if (in[m] == '$')
			{
			if (in[m + 1] == '?')
				add_rvar_node(h, 2, st, lst), m++;
			else if (in[m + 1] == '$')
				add_rvar_node(h, 2, data->pid15, lpd), m++;
			else if (in[m + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[m + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[m + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[m + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[m + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + m, data);
			}
	}

	return (m);
}

/**
 * replaced_input - replaces string into variables
 *
 * @head: head of the linked list
 * @input15: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *replaced_input(r_var15 **head, char *input15, char *new_input, int nlen)
{
	r_var15 *indx;
	int m, j, k;

	indx = *head;
	for (j = m = 0; m < nlen; m++)
	{
		if (input15[j] == '$')
		{
			if (!(indx->len_15) && !(indx->len_val))
			{
				new_input[m] = input15[j];
				j++;
			}
			else if (indx->len_15 && !(indx->len_val))
			{
				for (k = 0; k < indx->len_15; k++)
					j++;
					m--;
			}
			else
			{
			for (k = 0; k < indx->len_val; k++)
				{
					new_input[m] = indx->value[k];
					m++;
				}
				j += (indx->len_15);
				m--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[m] = input15[j];
			j++;
		}
	}
	return (new_input);
}

/**
 * rep_var - calls functions to replace string into vars
 *
 * @input15: input string
 * @datash_mogale: data structure
 * Return: replaced string
 */
char *rep_var(char *input15, data_shell_15 *datash_mogale)
{
	r_var15 *head, *indx;
	char *status15, *new_input;
	int olen, nlen;

	status15 = aux_itoa(datash_mogale->status15);
	head = NULL;

	olen = check_vars(&head, input15, status15, datash_mogale);

	if (head == NULL)
	{
		free(status15);
		return (input15);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_15);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input15, new_input, nlen);

	free(input15);
	free(status15);
	free_rvar_list(&head);
	return (new_input);
}
