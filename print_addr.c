#include "main.h"

/**
 * find_hex - prints in lowercase hexidecimal format
 * @input: address input
 *
 * Return: hexidecimal length
 */

int find_hex(unsigned long int input)
{
	int i = 0, len = 0;
	int *buffer;
	char search[] = "0123456789abcdef";
	unsigned long int copy;

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
 * print_addr - prints in address of data in unsigned hexidecimal
 * @ap: pointer to argument list
 *
 * Return: address length
 */

int print_addr(va_list ap)
{
	void *ptr;
	char placeholder[] = "(null)";
	long int addr;
	int len = 0, i = 0;

	ptr = va_arg(ap, void *);
	if (ptr == NULL)
	{
		for (i = 0; placeholder[i]; i++)
			_putchar(placeholder[i]);
		return (i);
	}

	addr = (unsigned long int)ptr;
	_putchar('0');
	_putchar('x');
	len = find_hex(addr);
	return (len + 2);
}

