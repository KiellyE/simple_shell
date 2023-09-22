#include "main.h"

/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int m;

	for (m = 0; nenv[m] != '='; m++)
	{
		if (nenv[m] != name[m])
		{
			return (0);
		}
	}

	return (m + 1);
}

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * @_environ15: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_environ15)
{
	char *ptr_env;
	int m, mov;

	/* Initialize */
	ptr_env = NULL;
	mov = 0;
	/* Compare all variables */
	/* environ is declared in the file */
	for (m = 0; _environ15[m]; m++)
	{
		/* If name and equal */
		mov = cmp_env_name(_environ15[m], name);
		if (mov)
		{
			ptr_env = _environ15[m];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - prints the evironment variables
 *
 * @datash_mogale - data relevant.
 * Return: 1 on success.
 */
int _env(data_shell_15 *datash_mogale)
{
	int m, j;

	for (m = 0; datash_mogale->_environ15[m]; m++)
	{

		for (j = 0; datash_mogale->_environ15[m][j]; j++)
			;

		write(STDOUT_FILENO, datash_mogale->_environ15[m], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash_mogale->status15 = 0;

	return (1);
}
