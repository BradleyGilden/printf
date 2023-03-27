#include "main.h"

/**
 *print_char - a function that prints characters of integer.
 *@ap: argument pointer.
 *Return: 1 on success.
 */

int print_char(va_list ap)
{
	char c = va_arg(ap, int);

	_putchar(c);
	return (1);
}

/**
 *print_pcnt - prints percentages of integer.
 *@ap: argument pointer.
 *Return: 1 on success.
 */

int print_pcnt(va_list ap)
{
	(void)ap;

	_putchar('%');
	return (1);
}
