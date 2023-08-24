#include "shell.h"
/**
 * execute - func executing a command with path variables
 * @data: data pointer
 * Return: 0 - success, else -1
 */
int execute(data_of_program *data)
{
	int reval = 0, status;
	pid_t pidd;

	reval = builtins_list(data);
	if (reval != -1)
		return (reval);
	reval = find_program(data);
	if (reval)
	{
		return (reval);
	}
	else
	{
		pidd = fork();
		if (pidd == -1)
		{
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			reval = execve(data->tokens[0], data->tokens, data->env);
			if (reval == -1)
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
