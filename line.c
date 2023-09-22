#include "shell.h"

/**
 * exec_line - Function finds builtins and commands
 *
 * @datash_mogale: data 
 * Return:Will return 1 on success.
 */
int exec_line(data_shell_15 *datash_mogale)
{
	int (*builtin)(data_shell_15 *datash_mogale);

	if (datash_mogale->args15[0] == NULL)
		return (1);

	builtin = get_builtin(datash_mogale->args15[0]);

	if (builtin != NULL)
		return (builtin(datash_mogale));

	return (cmd_exec(datash_mogale));
}
