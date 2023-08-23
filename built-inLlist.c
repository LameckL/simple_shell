#include "shell.h"

/**
 * builtins_list - a func searching for match then execute the builtin
 * @data: struct data
 * Return: function executed
 **/
int builtins_list(data_of_program *data)
{
	int iterate;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};

	for (iterate = 0; options[iterate].builtin != NULL; iterate++)
	{
		if (str_compare(options[iterate].builtin, data->command_name, 0))
		{
			return (options[iterate].function(data));
		}
	}
	return (-1);
}
