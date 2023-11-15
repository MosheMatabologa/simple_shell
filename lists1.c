#include "shell.h"

/**
<<<<<<< HEAD
 * list_len - determines length of linked list
=======
 * list_len - used as a determiner to length of linked list
>>>>>>> 2fd19d552464bf55de0970c403c090f91e9f0c20
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
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
	strs[i] = NULL;
	return (strs);
}


/**
<<<<<<< HEAD
 * print_list - prints all elements of a list_t linked list
=======
 * print_list - will prints all elements of a list_t linked list
>>>>>>> 2fd19d552464bf55de0970c403c090f91e9f0c20
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
<<<<<<< HEAD
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
=======
 * node_starts_with - returns node whose string starts with prefix (found here)
 * @node: is the pointer of the head
 * @prefix: matches strings
>>>>>>> 2fd19d552464bf55de0970c403c090f91e9f0c20
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
<<<<<<< HEAD
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
=======
 * @head: assists in pointer to list head
 * @node: assists in locating pointer to the node
 *
 * Return: will index of node or -1
>>>>>>> 2fd19d552464bf55de0970c403c090f91e9f0c20
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
