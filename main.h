#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
typedef struct flag
{
	char sp;
	int (*f)(va_list);
} flag_t;
int _putchar(char c);
int _printf(const char *format, ...);
int _char(va_list vlist);
int _str(va_list vlist);
int _per(va_list vlist);
int _int(va_list vlist);
int int_len(int x);
int _binary(va_list vlist);
int rev_string(va_list vlist);
#endif
