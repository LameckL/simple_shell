#include "shell.h"

/**
 * builtin_env - a function that shows shell environment
 * @data: struct data
 * Return: 0 - success
 */
int builtin_env(data_of_program *data)
{
	int i;
	char cp_name[50] = {'\0'};
	char *var_copy = NULL;

	if (data->tokens[1] == NULL)
		print_environ(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{
			if (data->tokens[1][i] == '=')
			{
				var_copy = str_duplicate(env_get_key(cp_name, data));
				if (var_copy != NULL)
					env_set_key(cp_name, data->tokens[1] + i + 1, data);

				print_environ(data);
				if (env_get_key(cp_name, data) == NULL)
				{
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{
					env_set_key(cp_name, var_copy, data);
					free(var_copy);
				}
				return (0);
			}
			cp_name[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * builtin_set_env - a function to set env
 * @data: struct data
 * Return: 0 - success
 */
int builtin_set_env(data_of_program *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	env_set_key(data->tokens[1], data->tokens[2], data);

	return (0);
}

/**
 * builtin_unset_env - function to unset env
 * @data: struct data
 * Return: 0 - success
 */
int builtin_unset_env(data_of_program *data)
{
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	env_remove_key(data->tokens[1], data);

	return (0);
}
