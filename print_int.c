#include "main.h"

/**
 * find_int - function that finds string lenght of interger.
 * @num: number to be printed.
 * @len: lenght of a string.
 * Return: return string length.
 */

void find_int(int num, int *len)
{
	if (num < 0)
	{
		_putchar('-');
		num = -num;
		(*len)++;
	}
	if (num / 10)
	find_int(num / 10, len);
	_putchar(num % 10 + '0');
	(*len)++;
}

/**
 * print_int - function that prints argument pointers.
 * @ap: argument pointer.
 * Return: return string length.
 */

int print_int(va_list ap)
{
	int len = 0;
	int num = va_arg(ap, int);

	find_int(num, &len);
	return (len);
}
