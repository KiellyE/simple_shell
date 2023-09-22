#include "shell.h"

/**
 * free_data - frees_ data_ structure
 *
 * @datash_mogale: data structure
 * Return: no return
 */

void free_data(data_shell_15 *datash_mogale)
{
	unsigned int m;

	for (m = 0; datash_mogale->_environ15[m]; m++)
	{
		free(datash_mogale->_environ15[m]);
	}

	free(datash_mogale->_environ15);
	free(datash_mogale->pid15);
}

/**
 * set_data - Initialize data_ structure_
 *
 * @datash_mogale: data structure_
 * @av15: argument vector15
 * Return: void
 */

void set_data(data_shell_15 *datash_mogale, char **av15)
{
	unsigned int m;

	datash_mogale->av15 = av15;
	datash_mogale->input15 = NULL;
	datash_mogale->args15 = NULL;
	datash_mogale->status15 = 0;
	datash_mogale->counter15 = 1;

	for (m = 0; environ[m]; m++);

	datash_mogale->_environ15 = malloc(sizeof(char *) * (m + 1));

	for (m = 0; environ[m]; m++)
	{
		datash_mogale->_environ15[m] = strdup15(environ[m]);
	}

	datash_mogale->_environ15[m] = NULL;
	datash_mogale->pid15 = aux_itoa(getpid());
}

/**
 * main - Entry point-79
 *
 * @ac: argument count56
 * @av15: argument vector15
 *
 * Return: 0
 */

int main(int ac, char **av15)
{
	data_shell_15 datash_mogale;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash_mogale, av15);
	shell_loop(&datash_mogale);
	free_data(&datash_mogale);
	if (datash_mogale.status15 < 0)
		return (255);
	return (datash_mogale.status15);
}
