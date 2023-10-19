#include "shell.h"

/**
 * str_cp - Copies a string with a specified length.
 * @dest: Destination string.
 * @src: Source string.
 * @n: Number of characters to copy.
 * Return: Pointer to the resulting string.
 */
char *str_cp(char *dest, char *src, int n)
{
	int i, j;
	char *str = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (str);
}

/**
 * str_cat - Concatenates strings with a specified length.
 * @dest: Destination string.
 * @src: Source string.
 * @n: Number of bytes to concatenate.
 * Return: Pointer to the concatenated string.
 */
char *str_cat(char *dest, char *src, int n)
{
	int i, j;
	char *str = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (str);
}

/**
 * str_chr - Finds a character in a string.
 * @str: String to search.
 * @c: Character to find.
 * Return: Pointer to the found character or NULL if not found.
 */
char *str_chr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
