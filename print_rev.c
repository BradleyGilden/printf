#include "main.h"

/**
 * print_rev - function that reverses a string.
 * @ap: list pointer to argument.
 * Return: The number of characters in string.
 */

int print_rev(va_list ap)
{
	int len = 0, j = 0;
	char *str = va_arg(ap, char *);
	char placeholder[] = "(null)";

	if (str == NULL)
		str = placeholder;

	while (str[len])
		len++;

	for (j = len - 1; j >= 0; j--)
		_putchar(str[j]);

	return (len);
}
