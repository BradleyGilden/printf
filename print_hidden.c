#include "main.h"

/**
 * find_HEX - prints in uppercase hexidecimal format
 * @input: address input
 *
 * Return: hexidecimal length
 */

int find_HEX(unsigned int input)
{
	int i = 0, len = 0;
	int *buffer;
	char search[] = "0123456789ABCDEF";
	unsigned int copy;

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
 * print_hidden - print hidden chars in /xHEX format
 * @ap: list pointer to argument
 *
 * Return: length of hidden chars and string
 */

int print_hidden(va_list ap)
{
	int i = 0, len = 0, padding = 0;
	char *hidden = va_arg(ap, char *);
	char placeholder[] = "(null)";

	if (hidden == NULL)
		hidden = placeholder;

	for (i = 0; hidden[i]; i++)
	{
		if (hidden[i] < 32 || hidden[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len += 2;
			padding = hidden[i];
			if (padding < 16)
			{
				_putchar('0');
				len++;
			}
			len += find_HEX(padding);
		}
		else
		{
			_putchar(hidden[i]);
			len++;
		}
	}
	return (len);
}
