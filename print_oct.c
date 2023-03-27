#include "main.h"

/**
 * print_oct - prints in octal format
 * @ap: pointer to argument list
 *
 * Return: octal length
 */

int print_oct(va_list ap)
{
	unsigned int copy, len = 0;
	int i = 0;
	int *buffer;
	char search[] = "01234567";
	unsigned int input = va_arg(ap, unsigned int);

	if (input == 0)
	{
		_putchar ('0');
		return (1);
	}

	copy = input;
	while (copy)
	{
		copy /= 8;
		len++;
	}

	buffer = (int *)malloc(sizeof(int) * len);
	if (buffer == NULL)
		return (-1);

	while (input)
	{
		buffer[i] = input % 8;
		input /= 8;
		i++;
	}

	for (i = len - 1; i >= 0; i--)
		_putchar(search[buffer[i]]);

	free(buffer);
	return (len);
}
