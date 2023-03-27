#include "main.h"

/**
 * print_HEX - prints in uppercase hexidecimal format
 * @ap: pointer to argument list
 *
 * Return: hexidecimal length
 */

int print_HEX(va_list ap)
{
	unsigned int copy, len = 0;
	int i = 0;
	int *buffer;
	char search[] = "0123456789ABCDEF";
	unsigned int input = va_arg(ap, unsigned int);

	if (input == 0)
	{
		_putchar ('0');
		return (1);
	}

	copy = input;
	while (copy)
	{
		copy /= 16;
		len++;
	}

	buffer = (int *)malloc(sizeof(int) * len);
	if (buffer == NULL)
		return (-1);

	while (input)
	{
		buffer[i] = input % 16;
		input /= 16;
		i++;
	}

	for (i = len - 1; i >= 0; i--)
	_putchar(search[buffer[i]]);

	free(buffer);
	return (len);
}

/**
 * print_hex - prints in capital hexidecimal format
 * @ap: pointer to argument list
 *
 * Return: hexidecimal length
 */

int print_hex(va_list ap)
{
	unsigned int copy, len = 0;
	int i = 0;
	int *buffer;
	char search[] = "0123456789abcdef";
	unsigned int input = va_arg(ap, unsigned int);

	if (input == 0)
	{
		_putchar ('0');
		return (1);
	}

	copy = input;
	while (copy)
	{
		copy /= 16;
		len++;
	}

	buffer = (int *)malloc(sizeof(int) * len);
	if (buffer == NULL)
		return (-1);

	while (input)
	{
		buffer[i] = input % 16;
		input /= 16;
		i++;
	}

	for (i = len - 1; i >= 0; i--)
	_putchar(search[buffer[i]]);

	free(buffer);
	return (len);
}
