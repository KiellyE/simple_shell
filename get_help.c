#include "main.h"

/**
 * get_help - function that retrieves help messages according builtin
 * @datash_mogale: data structure (args and input)
 * Return: Return 0
*/
int get_help(data_shell_15 *datash_mogale)
{
	if (datash_mogale->args15[1] == 0)
		aux_help_general();
	else if (strcm_p(datash_mogale->args15[1], "setenv") == 0)
		aux_help_setenv();
	else if (strcm_p(datash_mogale->args15[1], "env") == 0)
		aux_help_env();
	else if (strcm_p(datash_mogale->args15[1], "unsetenv") == 0)
		aux_help_unsetenv();
	else if (strcm_p(datash_mogale->args15[1], "help") == 0)
		aux_help();
	else if (strcm_p(datash_mogale->args15[1], "exit") == 0)
		aux_help_exit();
	else if (strcm_p(datash_mogale->args15[1], "cd") == 0)
		aux_help_cd();
	else if (strcm_p(datash_mogale->args15[1], "alias") == 0)
		aux_help_alias();
	else
		write(STDERR_FILENO, datash_mogale->args15[0],
			strlen15(datash_mogale->args15[0]));
	datash_mogale->status15 = 0;
	return (1);
}
