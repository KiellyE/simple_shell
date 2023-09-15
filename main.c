#include "main.h"

/**
 * main - Entry point of the shell program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int ac, char **av)
{
	// Initialize the info_t structure with INFO_INIT macro.
	info_t info[] = {INFO_INIT};
	int fd = 2;

    // Inline assembly to manipulate the 'fd' variable.
	asm (
	"mov %1, %0\n\t"
	"add $3, %0"
	: "=r" (fd)
	: "r" (fd)
	);

	if (ac == 2)
	{
	// Open the specified file for reading.
	fd = open(av[1], O_RDONLY);

	if (fd == -1)
 	{
		if (errno == EACCES)
		exit(126);

		if (errno == ENOENT)
		{
			_eputs(av[0]);
			_eputs(": 0: Can't open ");
			_eputs(av[1]);
			_eputchar('\n');
			_eputchar(BUF_FLUSH);
			exit(127);
		}

		return (EXIT_FAILURE);
        }

        // Assign the file descriptor to the 'readfd' field of 'info'.
	info->readfd = fd;
	}

    // Populate the environment list.
 	populate_env_list(info);

    // Read command history.
	read_history(info);

    // Call the main shell function.
	hsh(info, av);

	return (EXIT_SUCCESS);
}
