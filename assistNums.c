#include "shell.h"

/**
 * long_to_string - this func converts a number to str
 * @number: number to be converted
 * @string: buffer to store the number as str
 * @base: base to convert number
 * Return: none
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long ente = number;
	char lett[] = {"0123456789abcdef"};

	if (ente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (ente)
	{
		if (ente < 0)
			string[index++] = lett[-(ente % base)];
		else
			string[index++] = lett[ente % base];
		ente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}


/**
 * _atoi - this func convert a str to an int
 * @s: str pointer
 * Return: 0, or str int
 */
int _atoi(char *s)
{
	int sgn = 1;
	unsigned int num = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sgn *= -1;
		if (*s == '+')
			sgn *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		num = (num * 10) + (*s - '0');
		s++;
	}
	return (num * sgn);
}

/**
 * count_characters - func to count similar of char in str
 * @string: str pointer
 * @character: string containing  chars to be counted
 * Return: 0 or str int
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}
