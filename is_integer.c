#include "monty.h"

/**
 * is_integer - Checks if a string is a valid integer
 * @str: String to be checked
 * Return: 1 if true, 0 if false
 */
int is_integer(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
