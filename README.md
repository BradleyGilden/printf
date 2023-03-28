# The Printf Project

This repository contains a function, `_printf()` that is designed to mimic the printf function in the C `<stdio.h>` header file. The function utlizes the `write()` function in order to print single chars to stdout.

**prototype:** `int _printf(const char *format, ...);`

## Project File Contents:

N.B see [specifiers](#specifiers) for specifier descriptions

|FILES|FUNCTIONS \ STRUCTURES|
|:----|:--------|
|[main.h](main.h)|`struct menu` - This struct is able to store the specifiers for printf as well as point to it's related functions|
|[_printf.c](_printf.c)|`_printf()` - This is the master function that calls all other functions to print formated strings to output.|
|[_putchar.c](_putchar.c )|`_putchar()` - this function uses the write() function to print single char's out to stdout|
|[print_chars.c](print_chars.c)|`print_pcnt()` - this function accounts for the **%%** specifier and prints **%** in it's place.<br>`print_char()` - handles the **%c** specifier|
|[print_str.c](print_str.c)|`print_str()` - handles the **%s** specifier|
|[print_int.c](print_int.c)|`print_int()` - handles the **%d** and **%i** specifier<br>`find_int()` - a recursive function that assists **print_int()** in printing int to stdout<br><br>`print_uint()` - handles the **%u** specifier<br>`find_uint()` - a recursive function that assists **print_uint()** in printing unsigned int to stdout|
|[print_bin.c](print_bin.c )|`print_bin()` - handles the **%b** specifer|
|[print_hex.c](print_hex.c)|`print_hex()` - handles the **%x** specifier<br>`print_HEX()` - handles the **%X** specifier|
|[print_oct.c](print_oct.c)|`print_oct()` - handles the **%o** specifier|
|[print_hidden.c](print_hidden.c)|`print_hidden()` -  handles the %S specifier|
|[print_rev.c](print_rev.c)|`print_rev` - handles the %r specifier|
|[print_addr.c](print_addr.c)|`print_addr` - handles the %p specifier|
|[print_ROT13.c](print_ROT13.c)|`print_ROT13` - handles the %R specifier|

## Authorized functions:

* [write](#write-function-info)
* [malloc & free](https://github.com/BradleyGilden/alx-low_level_programming/blob/main/0x0C-more_malloc_free/moreinfo.md)
* [va_start & va_arg & va_end & va_copy](https://github.com/BradleyGilden/alx-low_level_programming/tree/main/0x10-variadic_functions)


## write function info:

prototype: `ssize_t write(int fd, const void *buf, size_t count);`

description: write() writes up to `count` bytes from the buffer starting at `buf` to the file referred to by the file descriptqor `fd`.

## gcc flag warnings

all warnings used: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format`

For `-Wno-format`  (same as `-Wformat=0`):

Checks calls to `printf` and `scanf`, etc... to make sure that the arguments supplied have types appropriate to the format string specified and that the conversion specified make sense.
e.g:

```C
	printf("%d", sizeof(int)); // wrong format
	printf("%lu", sizeof(int)); //right format
```

## Specifiers

|SPECIFIER|DESCRIPTION|
|:--------|:----------|
|%d %i|formats output for integers|
|%c|formats output for single characters|
|%s|formats output for string literals|
|%u|formats output as an unsigned integer|
|%o|formats output as an octal number|
|%x|formats output as lowercase hexidecimal|
|%X|formats ouptut as uppercase hexidecimal|
|%S|formats output for string literals but also shows hidden character output as "\x"%02X|
|%p|formats output of addresses as lowercase hexidecimal i.e "0X"%x|
|%r|formats the reverse of a string literal argument|
|%R|formats string literal to encrypt or decrypt rot13 encrypted strings|

## Suggested Test File

```C
#include <stdio.h>
#include "main.h"
#include <limits.h>

int main(void)
{
	int len;
	int len2;
	unsigned int ui = (unsigned int)INT_MAX + 1024;
	void *addr = (void *)0x7ffe637541f0;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("binary:[%b]\n", 15);
	printf("binary:[1111]\n");
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	len = _printf("Address:[%p]\n", addr);
	len2 = printf("Address:[%p]\n", addr);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Reverse:[%r]\n", "Hello World");
	printf("Reverse:[Hello World]\n");
	printf("rot13 encoded: P vf sha\n");
	_printf("rot13 decoded: %R\n", "P vf sha");
	printf("String with hidden characters: Date: 22/02/2002\\n\n");
	_printf("String with hidden characters: Date: %S\n", "22/02/2002\n");

	return (0);
}
```

## Output

```
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unsigned:[2147484671]
Unsigned:[2147484671]
binary:[1111]
binary:[1111]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Len:[25]
Len:[25]
Reverse:[dlroW olleH]
Reverse:[Hello World]
rot13 encoded: P vf sha
rot13 decoded: C is fun
String with hidden characters: Date: 22/02/2002\n
String with hidden characters: Date: 22/02/2002\x0A
```

## Authors

* [Bradley Dillion Gilden](https://github.com/BradleyGilden)
* [Lebohang Kevcare Mokobane](https://github.com/KevCareSA)
