#include "main.h"

/**
 * find_int - a function that finds string length of integer.
 * @num: number to be printed.
 * @len: lenght of a string.
 * Return: return string length.
 */

void find_int(long int num, int *len)
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
 * print_int - a function that prints integers.
 * @ap: argument pointer.
 * Return: return string length.
 */

int print_int(va_list ap)
{
	int len = 0;
	long int num = (long int)va_arg(ap, int);

	find_int(num, &len);
	return (len);
}

/**
 * find_uint - a function that finds string length of integer.
 * @num: number to be printed.
 * @len: length of a string.
 * Return: return string length.
 */

void find_uint(unsigned int num, int *len)
{
	if (num / 10)
		find_uint(num / 10, len);
	_putchar(num % 10 + '0');
	(*len)++;
}

/**
 * print_uint - function that pprints unsigned ints.
 * @ap: argument pointer.
 * Return: return string length.
 */

int print_uint(va_list ap)
{
	int len = 0;
	unsigned int num = va_arg(ap, unsigned int);

	find_uint(num, &len);
	return (len);
}
