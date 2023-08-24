#include "shell.h"

/**
 * str_length - func returning str length
 * @string: string pointer
 * Return: str length
 */
int str_length(char *string)
{
	int lenn = 0;

	if (string == NULL)
		return (0);

	while (string[lenn++] != '\0')
	{
	}
	return (--lenn);
}

/**
 * str_duplicate - this func duplicates a string
 * @string: str being copied
 * Return: array pointer
 */
char *str_duplicate(char *string)
{
	char *result;
	int i, lenn;

	if (string == NULL)
		return (NULL);

	lenn = str_length(string) + 1;

	result = malloc(sizeof(char) * lenn);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < lenn ; i++)
	{
		result[i] = string[i];
	}

	return (result);
}

/**
 * str_compare - this func compares 2 strings
 * @string1: first str (short)
 * @string2: second str(long)
 * @number: no. of chars to compare
 * Return: 1 - the strs equals, 0 - strings different
 */
int str_compare(char *string1, char *string2, int number)
{
	int iterate;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0)
	{
		if (str_length(string1) != str_length(string2))
			return (0);
		for (iterate = 0; string1[iterate]; iterate++)
		{
			if (string1[iterate] != string2[iterate])
				return (0);
		}
		return (1);
	}
	else
	{
		for (iterate = 0; iterate < number ; iterate++)
		{
			if (string1[iterate] != string2[iterate])
			return (0);
		}
		return (1);
	}
}

/**
 * str_concat - func concatenating 2 strings
 * @string1: str
 * @string2: str
 * Return: array pointer
 */
char *str_concat(char *string1, char *string2)
{
	char *result;
	int lenn = 0, lenn1 = 0;

	if (string1 == NULL)
		string1 = "";
	lenn = str_length(string1);

	if (string2 == NULL)
		string2 = "";
	lenn1 = str_length(string2);

	result = malloc(sizeof(char) * (lenn + lenn1 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	/* copy of string1 */
	for (lenn = 0; string1[lenn] != '\0'; lenn++)
		result[lenn] = string1[lenn];
	free(string1);

	/* copy of string2 */
	for (lenn1 = 0; string2[lenn1] != '\0'; lenn1++)
	{
		result[lenn] = string2[lenn1];
		lenn++;
	}

	result[lenn] = '\0';
	return (result);
}


/**
 * str_reverse - func reversing a string
 * @string: string pointer
 * Return: void
 */
void str_reverse(char *string)
{

	int i = 0, lenn = str_length(string) - 1;
	char hold;

	while (i < lenn)
	{
		hold = string[i];
		string[i++] = string[lenn];
		string[lenn--] = hold;
	}
}
