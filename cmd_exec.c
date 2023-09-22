#include "main.h"

/**
 * is_cdir - checks ":" if is in the current directory.
 * @path: type char pointer char.
 * @m: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int is_cdir(char *path, int *m)
{
	if (path[*m] == ':')
		return (1);

	while (path[*m] != ':' && path[*m])
	{
		*m += 1;
	}

	if (path[*m])
		*m += 1;

	return (0);
}

/**
 * _which - locates a command
 *
 * @cmd: command name
 * @_environ15: environment variable
 * Return: location of the command.
 */
char *_which(char *cmd15, char **_environ15)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, m;
	struct stat st;

	path = _getenv("PATH", _environ15);
	if (path)
	{
		ptr_path = strdup15(path);
		len_cmd = strlen15(cmd15);
		token_path = strtok15(ptr_path, ":");
		m = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &m))
				if (stat(cmd15, &st) == 0)
					return (cmd15);
			len_dir = strlen15(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			strcp_y(dir, token_path);
			strca_t(dir, "/");
			strca_t(dir, cmd15);
			strca_t(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = strtok15(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd15, &st) == 0)
			return (cmd15);
		return (NULL);
	}
	if (cmd15[0] == '/')
		if (stat(cmd15, &st) == 0)
			return (cmd15);
	return (NULL);
}

/**
 * is_executable - determines if is an executable
 *
 * @datash_mogale: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_executable(data_shell_15 *datash_mogale)
{
	struct stat st;
	int m;
	char *input15;

	input15 = datash_mogale->args15[0];
	for (m = 0; input15[m]; m++)
	{
		if (input15[m] == '.')
		{
			if (input15[m + 1] == '.')
				return (0);
			if (input15[m + 1] == '/')
				continue;
			else
				break;
		}
		else if (input15[m] == '/' && m != 0)
		{
			if (input15[m + 1] == '.')
				continue;
			m++;
			break;
		}
		else
			break;
	}
	if (m == 0)
		return (0);

	if (stat(input15 + m, &st) == 0)
	{
		return (m);
	}
	get_error(datash_mogale, 127);
	return (-1);
}

/**
 * check_error_cmd - verifies if user has permissions to access
 *
 * @dir: destination directory
 * @datash_mogale: data structure
 * Return: 1 if there is an error, 0 if not
 */
int check_error_cmd(char *dir, data_shell_15 *datash_mogale)
{
	if (dir == NULL)
	{
		get_error(datash_mogale, 127);
		return (1);
	}

	if (strcm_p(datash_mogale->args15[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(datash_mogale, 126);
			free(dir);
			return (1);
		}
				free(dir);
	}
	else
	{
		if (access(datash_mogale->args15[0], X_OK) == -1)
		{
			get_error(datash_mogale, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exec - executes command lines
 *
 * @datash_mogale: data relevant (args15 and input15)
 * Return: 1 on success.
 */
int cmd_exec(data_shell_15 *datash_mogale)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable(datash_mogale);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(datash_mogale->args15[0], datash_mogale->_environ15);
		if (check_error_cmd(dir, datash_mogale) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(datash_mogale->args15[0], datash_mogale->_environ15);
		else
			dir = datash_mogale->args15[0];
		execve(dir + exec, datash_mogale->args15, datash_mogale->_environ15);
	}
	else if (pd < 0)
	{
		perror(datash_mogale->av15[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash_mogale->status15 = state / 256;
	return (1);
}
