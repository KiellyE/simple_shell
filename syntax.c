#include "main.h"

/**
 * repeated_char - counts the repetitions of a char
 *
 * @input15: input string
 * @m: index
 * Return: repetitions
 */
int repeated_char(char *input15, int m)
{
	if (*(input15 - 1) == *input15)
		return (repeated_char(input15 - 1, m + 1));

	return (m);
}

/**
 * error_sep_op - finds syntax errors
 *
 * @input15: input string
 * @m: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int error_sep_op(char *input15, int m, char last)
{
	int count;

	count = 0;
	if (*input15 == '\0')
		return (0);

	if (*input15 == ' ' || *input15 == '\t')
		return (error_sep_op(input15 + 1, m + 1, last));

	if (*input15 == ';')
		if (last == '|' || last == '&' || last == ';')
			return (m);

	if (*input15 == '|')
	{
		if (last == ';' || last == '&')
			return (m);

		if (last == '|')
		{
			count = repeated_char(input15, 0);
			if (count == 0 || count > 1)
				return (m);
		}
	}

	if (*input15 == '&')
	{
		if (last == ';' || last == '|')
			return (m);

		if (last == '&')
		{
			count = repeated_char(input15, 0);
			if (count == 0 || count > 1)
				return (m);
		}
	}

	return (error_sep_op(input15 + 1, m + 1, *input15));
}

/**
 * first_char - finds index of the first char
 *
 * @input15: input string
 * @m: index
 * Return: 1 if there is an error. 0 in other case.
 */

int first_char(char *input15, int *m)
{

	for (*m = 0; input15[*m]; *m += 1)
	{
		if (input15[*m] == ' ' || input15[*m] == '\t')
			continue;

		if (input15[*m] == ';' || input15[*m] == '|' || input15[*m] == '&')
			return (-1);
		break;
	}

	return (0);
}

/**
 * print_syntax_error - prints when a syntax error is found
 *
 * @datash_mogale: data structure
 * @input15: input string
 * @m: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void print_syntax_error(data_shell_15 *datash_mogale, char *input15, int m, int bool)	
{
	char *msg, *msg2, *msg3, *error, *counter15;
	int length;

	if (input15[m] == ';')
	{
		if (bool == 0)
			msg = (input15[m + 1] == ';' ? ";;" : ";");
		else
			msg = (input15[m - 1] == ';' ? ";;" : ";");
	}

	if (input15[m] == '|')
		msg = (input15[m + 1] == '|' ? "||" : "|");

	if (input15[m] == '&')
		msg = (input15[m + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter15 = aux_itoa(datash_mogale->counter15);
	length = strlen15(datash_mogale->av15[0]) + strlen15(counter15);
	length += strlen15(msg) + strlen15(msg2) + strlen15(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(counter15);
		return;
	}
	strcp_y(error, datash_mogale->av15[0]);
	strca_t(error, ": ");
	strca_t(error, counter15);
	strca_t(error, msg2);
	strca_t(error, msg);
	strca_t(error, msg3);
	strca_t(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter15);
}

/**
 * check_syntax_error - intermediate function to
 * find and print a syntax error
 *
 * @datash_mogale: data structure
 * @input15: input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_syntax_error(data_shell_15 *datash_mogale, char *input15)
{
	int begin = 0;
	int f_char = 0;
	int m = 0;

	f_char = first_char(input15, &begin);
	if (f_char == -1)
	{
		print_syntax_error(datash_mogale, input15, begin, 0);
		return (1);
	}

	m = error_sep_op(input15 + begin, 0, *(input15 + begin));
	if (m != 0)
	{
		print_syntax_error(datash_mogale, input15, begin + m, 1);
		return (1);
	}

	return (0);
}
