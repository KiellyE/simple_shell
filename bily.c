#include "main.h"

/**
 * get_builtin - builtin that pais
 * @cmd15: command
 * Return: function pointer of the builtin command
 *
 */

int (*get_builtin(char *cmd15))(data_shell_15 *)
{
	builtin_t15 builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int m;

	for (m = 0; builtin[m].name; m++)
	{
		if (strcm_p(builtin[m].name, cmd15) == 0)
			break;
	}

	return (builtin[m].f25);
}
