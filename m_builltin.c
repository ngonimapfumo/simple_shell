#include "shell.h"

/**
 * copy_ext - function to handle exiting shell
 * @info: a structure
 *  Return: Will exit according to status
 *         0 for info.argv[0] != "exit"
 */
int copy_ext(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* checks If there is an exit arguement */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->error_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->error_num = -1;
	return (-2);
}

/**
 * copy_cd - a function to changes the current directory of the process
 * @info: a struc
 *  Return: 0
 */
int copy_cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("getcwd failure<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "cannot cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
OBOBOB		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
OBOBOB	}
	return (0);
}
OBOBOB
OBOBOB/**
 * help - a function to change curr dir of process
 * @info: a struc
OBOBOB *  Return: 0
 */
int help(info_t *info)
OBOBOB{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
