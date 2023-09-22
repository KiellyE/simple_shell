#include "shell.h"
/**
 * get_error - calls the error according the builtin, syntax or permission
 * @datash_mogale: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(data_shell_15 *datash_mogale, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(datash_mogale);
		break;
	case 126:
		error = error_path_126(datash_mogale);
		break;
	case 127:
		error = error_not_found(datash_mogale);
		break;
	case 2:
		if (strcm_p("exit", datash_mogale->args15[0]) == 0)
			error = error_exit_shell(datash_mogale);
		else if (strcm_p("cd", datash_mogale->args15[0]) == 0)
			error = error_get_cd(datash_mogale);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, strlen15(error));
		free(error);
	}

	datash_mogale->status15 = eval;
	return (eval);
}
