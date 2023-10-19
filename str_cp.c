#include "shell.h"

/**
 * _strcp - Copies a string from source to destination.
 * @dest: Destination buffer.
 * @srcstr: Source string.
 * Return: Pointer to the destination.
 */
char *_strcp(char *dest, char *srcstr)
{
	int i = 0;

	if (dest == srcstr || srcstr == 0)
		return (dest);
	while (srcstr[i])
	{
		dest[i] = srcstr[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - Duplicates a string.
 * @str: Input string to duplicate.
 * Return: Pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - Prints a string to the standard output.
 * @str: Input string to print.
 * Return: Void (no return value).
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - Writes a character to standard output.
 * @chr: Character to write.
 * Return: 1 when successful.
 */
int _putchar(char chr)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (chr != BUF_FLUSH)
		buf[i++] = chr;
	return (1);
}
