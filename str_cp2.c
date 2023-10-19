#include "shell.h"

/**
 * _strlength - Returns the length of a string.
 * @str: The input string.
 * Return: The length of the string as an integer.
 */
int _strlength(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;
	return (i);
}

/**
 * _strcomp - Performs lexicographic comparison of two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: - if s1 < s2, + if s1 > s2, or 0 if s1 == s2.
 */
int _strcomp(char *s1, char *s2)
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
 * starts_with - Checks if needle starts with haystack.
 * @haystack: The input string.
 * @needle: The substring to check.
 * Return: The address of the match or NULL if no match is found.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * str_cat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The input string to concatenate.
 * Return: A pointer to the resulting concatenated.
 */
char *str_cat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

