#include "main.h"

/**
 * swap_char - swaps | and & for non-printed chars
 *
 * @input15: input string
 * @bool: type of swap
 * Return: swapped string
 */
char *swap_char(char *input15, int bool)
{
	int m;

	if (bool == 0)
	{
		for (m = 0; input15[m]; m++)
		{
			if (input15[m] == '|')
			{
				if (input15[m + 1] != '|')
					input15[m] = 16;
				else
					m++;
			}

			if (input15[m] == '&')
			{
				if (input15[m + 1] != '&')
					input15[m] = 12;
				else
					m++;
			}
		}
	}
	else
	{
		for (m = 0; input15[m]; m++)
		{
			input15[m] = (input15[m] == 16 ? '|' : input15[m]);
			input15[m] = (input15[m] == 12 ? '&' : input15[m]);
		}
	}
	return (input15);
}

/**
 * add_nodes - add separators and command lines in the lists
 *
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @input15: input string
 * Return: no return
 */
void add_nodes(sep_list15 **head_s, line_list15 **head_l, char *input15)
{
	int m;
	char *line;

	input15 = swap_char(input15, 0);

	for (m = 0; input15[m]; m++)
	{
		if (input15[m] == ';')
			add_sep_node_end(head_s, input15[m]);

		if (input15[m] == '|' || input15[m] == '&')
		{
			add_sep_node_end(head_s, input15[m]);
			m++;
		}
	}

	line = strtok15(input15, ";|&");
	do {
		line = swap_char(line, 1);
		add_line_node_end(head_l, line);
		line = strtok15(NULL, ";|&");
	} while (line != NULL);
}

/**
 * go_next - go to the next command line stored
 *
 * @list_s: separator list
 * @list_l: command line list
 * @datash_mogale: data structure
 * Return: no return
 */
void go_next(sep_list15 **list_s, line_list15 **list_l, data_shell_15 *datash_mogale)
{
	int loop_sep;
	sep_list15 *ls_s;
	line_list15 *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (datash_mogale->status15 == 0)
		{
			if (ls_s->separator15 == '&' || ls_s->separator15 == ';')
				loop_sep = 0;
			if (ls_s->separator15 == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator15 == '|' || ls_s->separator15 == ';')
				loop_sep = 0;
			if (ls_s->separator15 == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - splits command lines according to
 * the separators ;, | and &, and executes them
 *
 * @datash_mogale: data structure
 * @input: input string
 * Return: 0 to exit, 1 to continue
 */
int split_commands(data_shell_15 *datash_mogale, char *input15)
{
	sep_list15 *head_s, *list_s;
	line_list15 *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, input15);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash_mogale->input15 = list_l->line;
		datash_mogale->args15 = split_line(datash_mogale->input15);
		loop = exec_line(datash_mogale);
		free(datash_mogale->args15);

		if (loop == 0)
			break;

		go_next(&list_s, &list_l, datash_mogale);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_list(&head_s);
	free_line_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_line - tokenizes the input string
 * @input15: input string.
 * Return: string splitted.
 */
char **split_line(char *input15)
{
	size_t bsize;
	size_t m;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE15;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

		token = strtok15(input15, TOK_DELIM15);
		tokens[0] = token;

	for (m = 1; token != NULL; m++)
	{
		if (m == bsize)
		{
			bsize += TOK_BUFSIZE15;
			tokens = reallocdp15(tokens, m, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok15(NULL, TOK_DELIM15);
		tokens[m] = token;
	}
	return (tokens);
}
