#include "main.h"

/**
 * print_ROT13 - encode/decode string in ROT13
 * @ap: list pointer to argument
 *
 * Return: length of encoded string
 */

int print_ROT13(va_list ap)
{
	int i = 0, j = 0, len = 0, tracker = 0;
	char letters[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char key[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};
	char *rot13 = va_arg(ap, char*);
	char placeholder[] = "(null)";

	if (rot13 == NULL)
		rot13 = placeholder;

	for (i = 0; rot13[i]; i++)
	{
		tracker = 0;
		for (j = 0; letters[j] && !tracker; j++)
		{
			if (rot13[i] == letters[j])
			{
				_putchar(key[j]);
				len++;
				tracker = 1;
			}
		}
		if (!tracker)
		{
			_putchar(rot13[i]);
			len++;
		}
	}
	return (len);
}
