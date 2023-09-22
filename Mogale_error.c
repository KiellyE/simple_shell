#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 *
 * @datash_mogale: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *strcat_cd(data_shell_15 *datash_mogale, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	strcp_y(error, datash_mogale->av15[0]);
	strca_t(error, ": ");
	strca_t(error, ver_str);
	strca_t(error, ": ");
	strca_t(error, datash_mogale->args15[0]);
	strca_t(error, msg);
	if (datash_mogale->args15[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash_mogale->args15[1][1];
		illegal_flag[2] = '\0';
		strca_t(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		strca_t(error, datash_mogale->args15[1]);
	}

	strca_t(error, "\n");
	strca_t(error, "\0");
	return (error);
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @datash_mogale: data relevant (directory)
 * Return: Error message
 */
char *error_get_cd(data_shell_15 *datash_mogale)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(datash_mogale->counter15);
	if (datash_mogale->args15[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = strlen15(datash_mogale->args15[1]);
	}

	length = strlen15(datash_mogale->av15[0]) + strlen15(datash_mogale->args15[0]);
	length += strlen15(ver_str) + strlen15(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(datash_mogale, msg, error, ver_str);

	free(ver_str);

	return (error);
}


/**
 * error_not_found - generic error message for command not found
 * @datash_mogale: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_not_found(data_shell_15 *datash_mogale)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash_mogale->counter15);
	length = strlen15(datash_mogale->av15[0]) + strlen15(ver_str);
	length += strlen15(datash_mogale->args15[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	strcp_y(error, datash_mogale->av15[0]);
	strca_t(error, ": ");
	strca_t(error, ver_str);
	strca_t(error, ": ");
	strca_t(error, datash_mogale->args15[0]);
	strca_t(error, ": not found\n");
	strca_t(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * error_exit_shell - generic error message for exit in get_exit
 * @datash_mogale: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *error_exit_shell(data_shell_15 *datash_mogale)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash_mogale->counter15);
	length = strlen15(datash_mogale->av15[0]) + strlen15(ver_str);
	length += strlen15(datash_mogale->args15[0]) + strlen15(datash_mogale->args15[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	strcp_y(error, datash_mogale->av15[0]);
	strca_t(error, ": ");
	strca_t(error, ver_str);
	strca_t(error, ": ");
	strca_t(error, datash_mogale->args15[0]);
	strca_t(error, ": Illegal number: ");
	strca_t(error, datash_mogale->args15[1]);
	strca_t(error, "\n\0");
	free(ver_str);

	return (error);
}
