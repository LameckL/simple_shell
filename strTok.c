#include "shell.h"
/**
 * _strtok - func separating strings from delimiters
 * @line: array pointer
 * @delim: chars in str
 * Return: token pointer
*/
char *_strtok(char *line, char *delim)
{
	int j;
	static char *str;
	char *cpstr;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			break;
		}
		if (delim[j] == '\0')
			break;
	}
	cpstr = str;
	if (*cpstr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			{
				*str = '\0';
				str++;
				return (cpstr);
			}
		}
	}
	return (cpstr);
}
