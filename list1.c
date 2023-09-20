#include "main.h"

/**
<<<<<<< HEAD
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */

size_t list_len(const list_t *h)

=======
 * list_len - Determines the length of a linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
 */
size_t list_len(const list_t *h)
>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
<<<<<<< HEAD
	return (i);
}
/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
=======

	return (i);
}

/**
 * list_to_strings - Returns an array of strings from the list.
 * @head: Pointer to the first node.
 *
 * Return: Array of strings.
>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
<<<<<<< HEAD
	size_t i = list_len(head), j;
=======
	size_t i = list_len(head);
>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
	char **strs;
	char *str;

	if (!head || !i)
<<<<<<< HEAD
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
=======
	return (NULL);

	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
	return (NULL);

	for (i = 0; node; node = node->next, i++)
	{
	str = malloc(_strlen(node->str) + 1);
	if (!str)
	{
		for (size_t j = 0; j < i; j++)
		free(strs[j]);
		free(strs);
		return (NULL);
	}

	str = _strcpy(str, node->str);
	strs[i] = str;
	}

>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
	strs[i] = NULL;
	return (strs);
}

/**
<<<<<<< HEAD
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
=======
 * print_list - Prints all elements of a linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
<<<<<<< HEAD

=======
>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
<<<<<<< HEAD
=======

>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
	return (i);
}

/**
<<<<<<< HEAD
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */

=======
 * node_starts_with - Returns the node whose string starts with a prefix.
 * @node: Pointer to the list head.
 * @prefix: String to match.
 * @c: The next character after the prefix to match.
 *
 * Return: Matching node or NULL.
 */
>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
<<<<<<< HEAD
			return (node);
		node = node->next;
	}
=======
		return (node);
		node = node->next;
	}

>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
	return (NULL);
}

/**
<<<<<<< HEAD
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */

=======
 * get_node_index - Gets the index of a node in the list.
 * @head: Pointer to the list head.
 * @node: Pointer to the node.
 *
 * Return: Index of the node or -1 if not found.
 */
>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
	if (head == node)
<<<<<<< HEAD
		return (i);
	head = head->next;
	i++;
	}
=======
	return (i);
		head = head->next;
		i++;
	}

>>>>>>> 1d1576965e0e32ccbf0f4d61bf02c75041015c41
	return (-1);
}
