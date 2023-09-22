#include "main.h"

/**
 * error_env - error message for env in get_env.
 * @datash_mogale: data relevant (counter, arguments)
 * Return: error message.
 */
char *error_env(data_shell_15 *datash_mogale)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(datash_mogale->counter15);
	msg = ": Unable to add/remove from environment\n";
	length = strlen15(datash_mogale->av15[0]) + strlen15(ver_str);
	length += strlen15(datash_mogale->args15[0]) + strlen15(msg) + 4;
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
	strca_t(error, msg);
	strca_t(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_path_126 - error message for path and failure denied permission.
 * @datash_mogale - data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *error_path_126(data_shell_15 *datash_mogale)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(datash_mogale->counter15);
	length = strlen15(datash_mogale->av15[0]) + strlen15(ver_str);
	length += strlen15(datash_mogale->args15[0]) + 24;
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
	strca_t(error, ": Permission denied\n");
	strca_t(error, "\0");
	free(ver_str);
	return (error);
}
