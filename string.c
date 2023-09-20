#include "main.h"
<<<<<<< HEAD
/**
=======
/** 
>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
*/

int _strlen(char *s)

{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);

}

/**
* _strcmp - performs lexicogarphic comparison of two strangs.

* @s1: the first strang
* @s2: the second strang
*

* Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2

*/

int _strcmp(char *s1, char *s2)

{

	while (*s1 && *s2)
	{

		if (*s1 != *s2)

			return (*s1 - *s2);
		s1++;
		s2++;

	}
	if (*s1 == *s2)
		return (0);
	else
<<<<<<< HEAD
=======

>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
		return (*s1 < *s2 ? -1 : 1);
}

/**
<<<<<<< HEAD
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
=======

 * starts_with - checks if needle starts with haystack

 * @haystack: string to search

 * @needle: the substring to find

 *

 * Return: address of next char of haystack or NULL

 */

char *starts_with(const char *haystack, const char *needle)

>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
{
	while (*needle)

		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}


/**
<<<<<<< HEAD
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */

char *_strcat(char *dest, char *src)
=======

 * _strcat - concatenates two strings
 
 * @dest: the destination buffer

 * @src: the source buffer

 *

 * Return: pointer to destination buffer

 */

char *_strcat(char *dest, char *src)

>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
