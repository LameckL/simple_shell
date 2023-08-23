#include "shell.h"
/**
 * tokenize - func separating strings using a special delimiter
 * @data: data pointer
 * Return: string array
 */
void tokenize(data_of_program *data)
{
	char *delimiter = " \t";
	int i, j, lenn;
	int counter = 2;

	lenn = str_length(data->input_line);
	if (lenn)
	{
		if (data->input_line[lenn - 1] == '\n')
			data->input_line[lenn - 1] = '\0';
	}

	for (i = 0; data->input_line[i]; i++)
	{
		for (j = 0; delimiter[j]; j++)
		{
			if (data->input_line[i] == delimiter[j])
				counter++;
		}
	}

	data->tokens = malloc(counter * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	i = 0;
	data->tokens[i] = str_duplicate(_strtok(data->input_line, delimiter));
	data->command_name = str_duplicate(data->tokens[0]);
	while (data->tokens[i++])
	{
		data->tokens[i] = str_duplicate(_strtok(NULL, delimiter));
	}
}
