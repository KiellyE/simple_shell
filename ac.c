#include "main.h"
/**
 * strdup15 - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *strdup15(const char *s)
{
	char *new;
	size_t len;

	len = strlen15(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	memcpy15(new, s, len + 1);
	return (new);
}
/**
 * strlen15 - Returns the lenght of a string__
 * @s: Type char pointer_
 * Return: integer_
 */
int strlen15(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}
/**
 * cmp_chars - will compare chars of strings_
 * @str: input string_
 * @delim: Is the delimiter
 *
 * Return: 1  equals, 0 if not__
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int m, j, k;

	for (m = 0, k = 0; str[m]; m++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[m] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (m == k)
		return (1);
	return	(0);
}
/**
 * strtok15 - splits a string by some delimiter.
 * @str: This inputs the string.
 * @delim: delimiter15.
 *
 * Return: string _splited_.
 */
char *strtok15(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int m, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);

		splitted = str;

		m = strlen15(str);
		str_end = &str[m];
	}
	str_start = splitted;
	if (str_start == str_end)
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (m = 0; delim[m]; m++)
		{
			if (*splitted == delim[m])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_start);
}
/**
 * _isdigit15 - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit15(const char *s)
{
	unsigned int m;

	for (m = 0; s[m]; m++)
	{
		if (s[m] < 48 || s[m] > 57)
			return (0);
	}
	return (1);
}
