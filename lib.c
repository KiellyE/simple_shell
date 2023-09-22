#include "main.h"

/**
 * get_len - Get the lenght of a number_
 * @n: type int number__
 * Return: Lenght of a number_34
 */

int get_len(int n)
{
	unsigned int n1;
	int lenght = 1;

	if (n < 0)
	{
		lenght++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		lenght++;
		n1 = n1 / 10;
	}

	return (lenght);
}

/**
 * aux_itoa - function converts int to string_
 * @n: type integer number
 * Return: String.
 */

char *aux_itoa(int n)
{
	unsigned int n1;
	int lenght = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	lenght--;
	do {
		*(buffer + lenght) = (n1 % 10) + '0';
		n1 = n1 / 10;
		lenght--;
	}
	while (n1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - converts a string to an _integer_
 * @s: input _string_
 * Return: integer_
 */

int _atoi(char *s)
{
	unsigned int count = 0, size15 = 0, oi15 = 0, pn = 1, e = 1, m;

	while (*(s + count) != '\0')
	{
		if (size15 > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size15 > 0)
				e *= 10;
			size15++;
		}
		count++;
	}

	for (m = count - size15; m < count; m++)
	{
		oi15 = oi15 + ((*(s + m) - 48) * e);
		e /= 10;
	}
	return (oi15 * pn);
}
