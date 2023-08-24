#include "shell.h"

/**
 * env_get_key - func getting the value of an variable
 * @key: environment variable
 * @data: struct data
 * Return: pointer to the value of the variable
 */
char *env_get_key(char *key, data_of_program *data)
{
	int i, key_lenn = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);

	key_lenn = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_lenn) &&
		 data->env[i][key_lenn] == '=')
		{
			return (data->env[i] + key_lenn + 1);
		}
	}
	return (NULL);
}

/**
 * env_set_key - func overwriting the val of the environment var orcreate it
 * @key: variable name being set
 * @value: new value
 * @data: struct data
 * Return: 1 - parameters are NULL, 2 - error, 0 - success
 */

int env_set_key(char *key, char *value, data_of_program *data)
{
	int i;
	int key_lenn = 0, new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	key_lenn = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_lenn) &&
		 data->env[i][key_lenn] == '=')
		{
			new_key = 0;
			free(data->env[i]);
			break;
		}
	}
	data->env[i] = str_concat(str_duplicate(key), "=");
	data->env[i] = str_concat(data->env[i], value);

	if (new_key)
	{
		data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * env_remove_key - func removing a key from the environment
 * @key: key to remove
 * @data: data
 * Return: 1 - key removed, 0 - key does not exist
 */
int env_remove_key(char *key, data_of_program *data)
{
	int i, key_lenn = 0;

	if (key == NULL || data->env == NULL)
		return (0);

	key_lenn = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_lenn) &&
		 data->env[i][key_lenn] == '=')
		{
			free(data->env[i]);

			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environ - func printing current environment
 * @data: struct data
 * Return: none
 */
void print_environ(data_of_program *data)
{
	int j;

	for (j = 0; data->env[j]; j++)
	{
		_print(data->env[j]);
		_print("\n");
	}
}
