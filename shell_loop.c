#include "main.h"

/**
 * without_comment - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *without_comment(char *in)
{
	int m, up_to;

	up_to = 0;
	for (m = 0; in[m]; m++)
	{
	if (in[m] == '#')
		{
		if (m == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[m - 1] == ' ' || in[m - 1] == '\t' || in[m - 1] == ';')
				up_to = m;
		}
	}

	if (up_to != 0)
	{
		in = realloc15(in, m, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of shell
 * @datash_mogale: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell_15 *datash_mogale)
{
	int loop, i_eof;
	char *input15;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "Mogale_Erick_shell ", 4);
		input15 = read_line(&i_eof);
		if (i_eof != -1)
		{
			input15 = without_comment(input15);
			if (input15 == NULL)
				continue;

			if (check_syntax_error(datash_mogale, input15) == 1)
			{
				datash_mogale->status15 = 2;
				free(input15);
				continue;
			}
			input15 = rep_var(input15, datash_mogale);
			loop = split_commands(datash_mogale, input15);
			datash_mogale->counter15 += 1;
			free(input15);
		}
		else
		{
			loop = 0;
			free(input15);
		}
	}
}
