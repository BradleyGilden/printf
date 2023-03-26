#include "main.h"

/**
 * validation - validates if input string has correct specifiers
 *
 * @format: format string to print using printf
 * Return: -1 if incorrect format
 * 1 if formatting checks out
 */

int validation(const char *format)
{
	char specifiers[] = "%csdi";
	int i = 0, j = 0, len = 0;

validstart:
	while (format[i])
	{
		for (j = 0; j < 5; j++)
		{
			if (format[i] == '%' && format[i + 1] != specifiers[j])
			{
				len++;
			}
			if (format[i] != '%')
			{
				i++;
				goto validstart;
			}
		}
		if (len == 5)
			return (-1);
		len = 0;
		i += 2;
	}
	return (1);
}

/**
 * _printf - emulates the printf function using c's write func()
 *
 * @format: the formatted string entered in the printf function
 *
 * Return: length of the formatted string
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 4, len = 0;
	va_list ap;
	menu_t m[] = {
		{'%', print_pcnt},
		{'c', print_char},
		{'s', print_str},
		{'d', print_int},
		{'i', print_int}
	};

	if (format == NULL || validation(format) < 0)
		return (-1);
	va_start(ap, format);

Start:
	while (format[i])
	{
		for (j = 0; j < 5; j++)
		{
			if (format[i] == '%' && format[i + 1] == m[j].spec)
			{
				len += m[j].func(ap);
				i += 2;
				goto Start;
			}
		}
		_putchar(format[i]);
		len++;
		i++;
	}

	va_end(ap);
	return (len);
}
