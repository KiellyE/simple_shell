#include "main.h"

/**
 * read_line - reads the input string.
 *
 * @i_eof: return value of getline function
 * Return: input string
 */
char *read_line(int *i_eof)
{
	char *input15 = NULL;
	size_t bufsize15 = 0;

	*i_eof = getline(&input15, &bufsize15, stdin);

	return (input15);
}
