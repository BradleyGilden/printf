#include "main.h"

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
		{'%', print_pcnt}, {'c', print_char},
		{'s', print_str}, {'d', print_int},
		{'i', print_int}, {'b', print_bin}
	};

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);

Start:
	while (format[i])
	{
		for (j = 0; j < 6; j++)
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
