#include "shell.h"

/**
 * strca_t - concatenate two strings__
 * @destination: char pointer the destination of the copied str
 * @source: const char pointer the source of str
 * Return: the dest
 */
char *strca_t(char *destination, const char *source)
{
	int m;
	int j;

	for (m = 0; destination[m] != '\0'; m++)
		;

	for (j = 0; source[j] != '\0'; j++)
	{
		destination[m] = source[j];
		m++;
	}

	destination[m] = '\0';
	return (destination);
}
/**
 * strcp_y - Copies the string pointed to by src.
 * @destination: Type char pointer the dest of the copied str
 * @source: Type char pointer the source of str
 * Return: the dest.
 */

char *strcp_y(char *destination, char *source)
{

	size_t a;

	for (a = 0; source[a] != '\0'; a++)
	{
		destination[a] = source[a];
	}
	destination[a] = '\0';

	return (destination);
}
/**
 * strcm_p - Function that compares two strings.
 * @string1: type str compared
 * @string2: type str compared
 * Return: Always 0.
 */

int strcm_p(char *string1, char *string2)
{
	int m;

	for (m = 0; string1[m] == string2[m] && string1[m]; m++)
		;

	if (string1[m] > string2[m])
		return (1);
	if (string1[m] < string2[m])
		return (-1);
	return (0);
}


/**
 * strch_r - locates a character in a string,_
 * @s: string_
 * @c:_character_
 * Return: the pointer to the first occurrence of the character c.
 */

char *strch_r(char *s, char c)
{
	unsigned int m = 0;

	for (; *(s + m) != '\0'; m++)
		if (*(s + m) == c)
			return (s + m);
	if (*(s + m) == c)
		return (s + m);
	return ('\0');
}


/**
 * strsp_n - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */

int strsp_n(char *s, char *accept)
{
	int m, j, bool;

	for (m = 0; *(s + m) != '\0'; m++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + m) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (m);
}
