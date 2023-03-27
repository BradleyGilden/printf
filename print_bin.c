#include "main.h"
/**
 * print_bin - a function that prints unsigned int input as binary
 *
 * @ap: pointer to input argument
 * Return: length of binary
 */

int print_bin(va_list ap)
{
	unsigned int copy, len = 0;
	int i = 0;
	unsigned int num = va_arg(ap, unsigned int);
	int *binary;

	copy = num;
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (copy)
	{
		copy /= 2;
		len++;
	}

	binary = (int *)malloc(sizeof(int) * len);
	if (binary == NULL)
		return (-1);

	while (num)
	{
		binary[i] = num % 2;
		num /= 2;
		i++;
	}
	for (i = len - 1; i >= 0; i--)
		_putchar(binary[i] + '0');

	free(binary);
	return (len);
}
