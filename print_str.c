#include "main.h"

/**
 * print_str - function that prints strings
 * @ap: argument pointer
 * Return: length of characters printed
 */

int print_str(va_list ap)
{
	int len = 0, i = 0;
	char *str = va_arg(ap, char *);

	if (str == NULL)
	{
		str = "(null)";
		for (i = 0; str[i]; i++)
			_putchar(str[i]);
		return (6);
	}

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
		len++;
	}
	return (len);
}
