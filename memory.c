#include "main.h"

/**
 * bfree - Frees a pointer and NULLs the address.
 * @ptr: Address of the pointer to free.
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
<<<<<<< HEAD
	return (1);
	}

	return (0);
=======
	return 1;
	}

	return 0;
>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
}
