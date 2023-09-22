#include "main.h"

/**
 * copy_info - copies info to CREATES
 * a new env or alias
 * @name: name (env or alias)
 * @value15: value (env or alias)
 *
 * Return: new env or alias.
 */

char *copy_info(char *name, char *value15)
{
	char *new;
	int len_name, len_value, len;

	len_name = strlen15(name);
	len_value = strlen15(value15);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	strcp_y(new, name);
	strca_t(new, "=");
	strca_t(new, value15);
	strca_t(new, "\0");

	return (new);
}


/**
 * set_env - sets an environment var
 *
 * @name: name of the environment variab
 * @values: value of the environment variable
 * @datash_mogale: data structure environ_
 * Return: nothing
 */

void set_env(char *name, char *values, data_shell_15 *datash_mogale)
{
	int m;
	char *var_env, *name_env;

	for (m = 0; datash_mogale->_environ15[m]; m++)
	{
		var_env = strdup15(datash_mogale->_environ15[m]);
		name_env = strtok15(var_env, "=");
		if (strcm_p(name_env, name) == 0)
		{
			free(datash_mogale->_environ15[m]);
			datash_mogale->_environ15[m] = copy_info(name_env, values);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash_mogale->_environ15 = reallocdp15(datash_mogale->_environ15,	
			m, sizeof(char *) * (m + 2));
	datash_mogale->_environ15[m] = copy_info(name, values);
	datash_mogale->_environ15[m + 1] = NULL;
}


/**
 * _setenv - compares env _variables_ names
 * with the name passed_
 * @datash_mogale: data relevant (env name_ and_ env value)
 *
 * Return: 1 on SUccess
 */
int _setenv(data_shell_15 *datash_mogale)
{

	if (datash_mogale->args15[1] == NULL || datash_mogale->args15[2] == NULL)
	{
		get_error(datash_mogale, -1);
		return (1);
	}

	set_env(datash_mogale->args15[1], datash_mogale->args15[2], datash_mogale);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 *
 * @datash_mogale: data relevant (env name)
 *
 * Return: 1 on success.
 */

int _unsetenv(data_shell_15 *datash_mogale)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int m , j, k;

	if (datash_mogale->args15[1] == NULL)
	{
		get_error(datash_mogale, -1);
		return (1);
	}
	k = -1;
	for (m = 0; datash_mogale->_environ15[m]; m++)
	{
		var_env = strdup15(datash_mogale->_environ15[m]);
		name_env = strtok15(var_env, "=");
		if (strcm_p(name_env, datash_mogale->args15[1]) == 0)
		{
			k = m;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(datash_mogale, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (m));
	for (m = j = 0; datash_mogale->_environ15[m]; m++)
	{
		if (m != k)
		{
			realloc_environ[j] = datash_mogale->_environ15[m];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash_mogale->_environ15[k]);
	free(datash_mogale->_environ15);
	datash_mogale->_environ15 = realloc_environ;
	return (1);
}
