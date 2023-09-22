#include "main.h"


/**
 * exit_shell - exits the
 *
 * @datash_mogale: data relevant
 * Return: 0
 */

int exit_shell(data_shell_15 *datash_mogale)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (datash_mogale->args15[1] != NULL)
	{
		ustatus = _atoi(datash_mogale->args15[1]);
		is_digit = _isdigit15(datash_mogale->args15[1]);
		str_len = strlen15(datash_mogale->args15[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(datash_mogale, 2);
			datash_mogale->status15 = 2;
			return (1);
		}
		datash_mogale->status15 = (ustatus % 256);
	}
	return (0);
}
