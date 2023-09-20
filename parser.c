#include "main.h"
<<<<<<< HEAD
/**
* is_cmd - determines if a file is an executable command
=======

/**
 * is_cmd - determines if a file is an executable command
>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
<<<<<<< HEAD
=======

>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
int is_cmd(info_t *info, char *path)
{
	struct stat st;

<<<<<<< HEAD
	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
=======

	(void)info;

	if (!path || stat(path, &st))

		return (0);


		if (st.st_mode & S_IFREG)
	
	{

		return (1);

        }

	return (0);

}

>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
<<<<<<< HEAD
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}
=======

	int i = 0, k = 0;


	for (k = 0, i = start; i < stop; i++)

		if (pathstr[i] != ':')

			buf[k++] = pathstr[i];

		buf[k] = 0;

	return (buf);

}

>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
<<<<<<< HEAD

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);

	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
=======
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;

	char *path;


	if (!pathstr)

		return (NULL);

	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))

	{

		if (is_cmd(info, cmd))

			return (cmd);

        }

	while (1)

        {

		if (!pathstr[i] || pathstr[i] == ':')

                {

		path = dup_chars(pathstr, curr_pos, i);

		if (!*path)

		_strcat(path, cmd);

		else

			{

				_strcat(path, "/");

 				_strcat(path, cmd);

 			}

 			if (is_cmd(info, path))

				return (path);

			if (!pathstr[i])

				break;

			curr_pos = i;

		}

		i++;

	}

	return (NULL);

>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
}
