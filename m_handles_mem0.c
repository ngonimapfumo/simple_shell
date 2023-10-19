#include "shell.h"

/**
 * is_freed - Will free pntr
 * @pntr: pntr address
 * Return: 1 otherwise 0.
 */
int is_freed(void **pntr)
{
	if (pntr && *pntr)
	{
		free(*pntr);
		*pntr = NULL;
		return (1);
	}
	return (0);
}

