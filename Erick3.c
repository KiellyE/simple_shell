#include "shell.h"

/**
 * add_sep_node_end - adds a separator found at the en_d
 * of a sep_list15
 * @head: head of the linked list_
 * @sep: separator found (; | &)
 * Return: Address of the head.
 */
sep_list15 *add_sep_node_end(sep_list15 **head, char sep)
{
	sep_list15 *new, *temp;

	new = malloc(sizeof(sep_list15));
	if (new == NULL)
		return (NULL);

	new->separator15 = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - frees a sep_list_
 * @head: head of the linked list.
 * Return: void
 */
void free_sep_list(sep_list15 **head)
{
	sep_list15 *temp;
	sep_list15 *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - will adds a command line at the end
 * of a line_list15.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
line_list15 *add_line_node_end(line_list15 **head, char *line)
{
	line_list15 *new, *temp;

	new = malloc(sizeof(line_list15));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}


/**
 * free_line_list - frees a line_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_line_list(line_list15 **head)
{
	line_list15 *temp;
	line_list15 *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
