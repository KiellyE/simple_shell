#include "main.h"

/**
 * memcpy15 - copies information between void pointers.
 * @newptr15: destination pointer.
 * @ptr15: source pointer.
 * @size15: size of the new pointer.
 *
 * Return: no return.
 */
void memcpy15(void *newptr15, const void *ptr15, unsigned int size15)
{
	char *char_ptr = (char *)ptr15;
	char *char_newptr = (char *)newptr15;
	unsigned int m;

	for (m = 0; m < size15; m++)
		char_newptr[m] = char_ptr[m];
}

/**
 * realloc15 - reallocates a memory block.
 * @ptr15: pointer to the memory previously allocated.
 * @old_size15: size, in bytes, of the allocated space of ptr.
 * @new_size15: new size, in bytes, of the new memory block.
 *
 * Return: pointer.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *realloc15(void *ptr15, unsigned int old_size15, unsigned int new_size15)
{
	void *newptr15;

	if (ptr15 == NULL)
		return (malloc(new_size15));

	if (new_size15 == 0)
	{
		free(ptr15);
		return (NULL);
	}

	if (new_size15 == old_size15)
		return (ptr15);

	newptr15 = malloc(new_size15);
	if (newptr15 == NULL)
		return (NULL);

	if (new_size15 < old_size15)
		memcpy15(newptr15, ptr15, new_size15);
	else
		memcpy15(newptr15, ptr15, old_size15);
	free(ptr15);
	return (newptr15);
}

/**
 * reallocdp15 - reallocates a memory block of a double pointer.
 * @ptr15: double pointer to the memory previously allocated.
 * @old_size15: size, in bytes, of the allocated space of ptr.
 * @new_size15: new size, in bytes, of the new memory block.
 *
 * Return: ptr15.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **reallocdp15(char **ptr15, unsigned int old_size15, unsigned int new_size15)
{
	char **newptr15;
	unsigned int m;	
	
	if (ptr15 == NULL)
		return (malloc(sizeof(char *) * new_size15));

	if (new_size15 == old_size15)
		return (ptr15);

	newptr15 = malloc(sizeof(char *) * new_size15);
	if (newptr15 == NULL)
		return (NULL);

	for (m = 0; m < old_size15; m++)
		newptr15[m] = ptr15[m];

	free(ptr15);

	return (newptr15);
}
