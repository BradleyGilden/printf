#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct menu - Represents a function that prints an argument
 *based on a determined format
 * @spec: The conversion specifier
 * @func: The pointer to the printing function
 */

typedef struct menu
{
	char spec;
	int (*func)(va_list ap);
} menu_t;

/*mandatory specifiers*/
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list ap);
int print_pcnt(va_list ap);
int print_str(va_list ap);
int print_int(va_list ap);
void find_int(long int num, int *len);

/*advanced specifiers*/
int print_bin(va_list ap);
int print_uint(va_list ap);
void find_uint(unsigned int num, int *len);
int print_HEX(va_list ap);
int print_hex(va_list ap);
int print_oct(va_list ap);
int print_addr(va_list ap);
int find_hex(unsigned long int input);
int print_rev(va_list ap);
int print_ROT13(va_list ap);
int print_hidden(va_list ap);
int find_HEX(unsigned int input);

#endif /*_MAIN_H_*/
