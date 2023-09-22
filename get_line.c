#include "shell.h"

/**
* bring_line - assigns the line var for get_line
 * @linptr: Buffer that store the input str
 * @buffer: str that is been called to line
 * @n: size of line
 * @j: size of buffer
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
	if (*lineptr == NULL)
	{
		if  (j > BUFSIZE15)
			*n = j;

		else
			*n = BUFSIZE15;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE15)
			*n = j;
		else
			*n = BUFSIZE15;
		*lineptr = buffer;
	}
	else
	{
		strcp_y(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * get_line - Read inpt from stream
 * @lineptr15: buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t get_line(char **lineptr15, size_t *n, FILE *stream)
{
	int m;
	static ssize_t input15;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input15 == 0)
		fflush(stream);
	else
		return (-1);
	input15 = 0;

	buffer = malloc(sizeof(char) * BUFSIZE15);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		m = read(STDIN_FILENO, &t, 1);
		if (m == -1 || (m == 0 && input15 == 0))
		{
			free(buffer);
			return (-1);
		}
		if (m == 0 && input15 != 0)
		{
			input15++;
			break;
		}
		if (input15 >= BUFSIZE15)
			buffer = realloc15(buffer, input15, input15 + 1);
		buffer[input15] = t;
		input15++;
	}
	buffer[input15] = '\0';
	bring_line(lineptr15, n, buffer, input15);
	retval = input15;
	if (m != 0)
		input15 = 0;
	return (retval);
}
