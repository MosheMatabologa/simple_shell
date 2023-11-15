<<<<<<< HEAD
#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
=======

/**
 * bfree - used to free a pointer and NULLs the address
>>>>>>> 2fd19d552464bf55de0970c403c090f91e9f0c20
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
