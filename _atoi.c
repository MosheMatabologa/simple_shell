#include "shell.h"

/**
 * interactive_mode - Check if in interactive mode
 * @info: struct address
<<<<<<< HEAD
 * Authors: Moshe Matabologa and Onkabetse02
 * Return: 1 if interactive mode, 0 otherwise for flagging
=======
 * Return: 1 if interactive mode, 0 otherwise
>>>>>>> 86b26fd8015ad41b89e7ec13c0e2487a74975520
 */
int interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Check if character is delimiter
 * @c: Character to check
 * @delim: Delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - Check for alphabetic character
 * @c: The character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - Convert strings to integers
 * @s: String to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
	int i, sign = 1, flagging = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flagging != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flagging = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flagging == 1)
			flagging = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

