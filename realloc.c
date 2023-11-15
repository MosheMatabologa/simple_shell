#include "shell.h"

/**
<<<<<<< HEAD
 * _memset - looking at a constant byte and fills its memory with it
 * @s: refers to the pointer of the memory within an area
 * @b: the byte to fill *s with
 * @n: looks at the amount of bytes to be filled
=======
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
>>>>>>> d5aabe718f103497afd12d2df6a36b9b9bb585a3
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
<<<<<<< HEAD
 * ffree - frees a string of the other strings
 * @pp: reffers to string of strings
=======
 * ffree - frees a string of strings
 * @pp: string of strings
>>>>>>> d5aabe718f103497afd12d2df6a36b9b9bb585a3
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
<<<<<<< HEAD
 * _realloc - this will reallocate a block of memory
 * @ptr: pointer to previous malloc located block
 * @old_size: looks at byte size of previous block
=======
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
>>>>>>> d5aabe718f103497afd12d2df6a36b9b9bb585a3
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
<<<<<<< HEAD

=======
>>>>>>> d5aabe718f103497afd12d2df6a36b9b9bb585a3
