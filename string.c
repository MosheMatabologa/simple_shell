#include "shell.h"

/**
<<<<<<< HEAD
 * _strlen - function returns the length of a string
=======
 * _strlen - returns the length of a string
>>>>>>> d5aabe718f103497afd12d2df6a36b9b9bb585a3
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
<<<<<<< HEAD
 * _strcmp - does the lexicogarphic comparison of two strangs.
 * @s1: refers to the first strang
=======
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
>>>>>>> d5aabe718f103497afd12d2df6a36b9b9bb585a3
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
		return (*s1 < *s2 ? -1 : 1);
}

/**
<<<<<<< HEAD
 * starts_with - operation checks if the needle starts with the haystack
 * @haystack: is the string needed to be searched
 * @needle: the substring we are looking for
=======
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
>>>>>>> d5aabe718f103497afd12d2df6a36b9b9bb585a3
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
<<<<<<< HEAD
 * _strcat - joins  two or more  strings
 * @dest: desktop created as the destination of buffer
 * @src: the source buffer
 *
 * Return:will return pointer to destination buffer
=======
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
>>>>>>> d5aabe718f103497afd12d2df6a36b9b9bb585a3
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
