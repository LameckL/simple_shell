#include "shell.h"

/**
 * print_alias - function to add, remove or show aliases
 * @data: struct data
 * @alias: alias name to print
 * Return: 0 - success, else return other number
 */
int print_alias(data_of_program *data, char *alias)
{
	int i, j;
	int alias_lenn;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_lenn = str_length(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_compare(data->alias_list[i], alias, alias_lenn)
				&&	data->alias_list[i][alias_lenn] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - a function that add, remove and show aliases
 * @data: struct data
 * @name: alias name
 * Return: 0 - success, else other number
 */
char *get_alias(data_of_program *data, char *name)
{
	int i, lenn;

	/* validate the arguments */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	lenn = str_length(name);

	for (i = 0; data->alias_list[i]; i++)
	{
		if (str_compare(name, data->alias_list[i], lenn) &&
			data->alias_list[i][lenn] == '=')
		{/* returns the value of the key NAME=  when find it */
			return (data->alias_list[i] + lenn + 1);
		}
	}

	return (NULL);

}

/**
 * set_alias - a function that add or override an alias
 * @alias_string: alias to seted
 * @data: struct data
 * Return: 0 - success
 */
int set_alias(char *alias_string, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{
			temp = get_alias(data, alias_string + i + 1);
			break;
		}

	for (j = 0; data->alias_list[j]; j++)
		if (str_compare(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{
			free(data->alias_list[j]);
			break;
		}

	if (temp)
	{
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[j] = str_duplicate(buffer);
	}
	else /* if the alias does not exist */
		data->alias_list[j] = str_duplicate(alias_string);
	return (0);
}
