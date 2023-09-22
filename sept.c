#include "shell.h"

/**
 * cd_dot - changes to the parent directory
 *
 * @datash_mogale: data relevant (environ)
 *
 * Return: no return
 */
void cd_dot(data_shell_15 *datash_mogale)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = strdup15(pwd);
	set_env("OLDPWD", cp_pwd, datash_mogale);
	dir = datash_mogale->args15[1];
	if (strcm_p(".", dir) == 0)
	{
		set_env("PWD", cp_pwd, datash_mogale);
		free(cp_pwd);
		return;
	}
	if (strcm_p("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = strtok15(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = strtok15(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, datash_mogale);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", datash_mogale);
	}
	datash_mogale->status15 = 0;
	free(cp_pwd);
}

/**
 * cd_to - changes to a directory given
 * by the user
 *
 * @datash_mogale: data relevant (directories)
 * Return: no return
 */
void cd_to(data_shell_15 *datash_mogale)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;
 
	getcwd(pwd, sizeof(pwd));

	dir = datash_mogale->args15[1];
	if (chdir(dir) == -1)
	{
		get_error(datash_mogale, 2);
		return;
	}

	cp_pwd = strdup15(pwd);
	set_env("OLDPWD", cp_pwd, datash_mogale);

	cp_dir = strdup15(dir);
	set_env("PWD", cp_dir, datash_mogale);

	free(cp_pwd);
	free(cp_dir);

	datash_mogale->status15 = 0;

	chdir(dir);
}

/**
 * cd_previous - changes to the previous directory
 * @datash_mogale: data relevant (environ)
 * Return: no return
 */
void cd_previous(data_shell_15 *datash_mogale)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = strdup15(pwd);

	p_oldpwd = _getenv("OLDPWD", datash_mogale->_environ15);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = strdup15(p_oldpwd);

	set_env("OLDPWD", cp_pwd, datash_mogale);

	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cp_pwd, datash_mogale);
	else
		set_env("PWD", cp_oldpwd, datash_mogale);

	p_pwd = _getenv("PWD", datash_mogale->_environ15);

	write(STDOUT_FILENO, p_pwd, strlen15(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	datash_mogale->status15 = 0;

	chdir(p_pwd);
}

/**
 * cd_to_home - changes to home directory
 *
 * @datash_mogale: data relevant (environ15)
 * Return: no return
 */
void cd_to_home(data_shell_15 *datash_mogale)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = strdup15(pwd);

	home = _getenv("HOME", datash_mogale->_environ15);

	if (home == NULL)
	{
		set_env("OLDPWD", p_pwd, datash_mogale);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_error(datash_mogale, 2);
		free(p_pwd);
		return;
	}

	set_env("OLDPWD", p_pwd, datash_mogale);
	set_env("PWD", home, datash_mogale);
	free(p_pwd);
	datash_mogale->status15 = 0;
}
