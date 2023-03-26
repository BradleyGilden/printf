#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct spec_printer - Represents a function that prints an argument
 * \ based on a determined format
 * @spec: The conversion specifier
 * @print_arg: The pointer to the printing function
 */

typedef struct menu{
	char spec;
	int (*func)(va_list ap);
} menu_t;

int validation(const char *format);
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list ap);
int print_pcnt(va_list ap);
int print_str(va_list ap);
int print_int(va_list ap);
void find_int(int num, int *len);

#endif /*_MAIN_H_*/
