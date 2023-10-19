#include "shell.h"

/**
 **set_memos - adds constant byte in memory
 *@s: a pointer
 *@b: the byte
 *@n: number of bytes
 *Return: a pointer
 */
char *set_memos(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * strn_free -  frees a string
 * @pp: a string
 */
void strn_free(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - a function to reallocate block of memory
 * @pntr: a pointer
 * @old_size: a parameter
 * @new_size: a parameter
 * Return: a pntr
 */
void *_realloc(void *pntr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!pntr)
		return (malloc(new_size));
	if (!new_size)
		return (free(pntr), NULL);
	if (new_size == old_size)
		return (pntr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)pntr)[old_size];
	free(pntr);
	return (p);
}

