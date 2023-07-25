#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * _printf - printf function.
 * @format:string to be printed.
 * Return:lenght of string.
 * or 0 or -1 or 1.
 */
int _printf(const char *format, ...)
{
	int i, len = 0, j = 0;
	va_list vlist;
	flag_t sps[] = {
		{'c', _char}, {'s', _str}, {'%', _per},
		{'d', _int}, {'i', _int}, {'b', _binary},
		{'r', rev_string}, {'\0', NULL}
	};

	if (!format)
		return (-1);
	va_start(vlist, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			len += _putchar(format[i]);
		else
		{
			if (format[i + 1] == '\0' || format[i + 1] == ' ')
				return (-1);
			while (sps[j].f)
			{
				if (sps[j].sp == format[i + 1])
				{
					len += sps[j].f(vlist);
					i++;
					break;
				}
				j++;
			}
			if (!sps[j].f)
				len += _putchar('%');
		}
	}
	va_end(vlist);
	return (len);
}
/**
 * _char - print character.
 * @vlist:the argument we will print.
 * Return:1.
 */
int _char(va_list vlist)
{
	char x;

	x = va_arg(vlist, int);
	if (!x)
		x = '\0';
	_putchar(x);
	return (1);
}
/**
 * _str - print string.
 * @vlist:the argument we will print.
 * Return:lenght of the string.
 */
int _str(va_list vlist)
{
	int i;
	char *x;

	x = va_arg(vlist, char *);
	if (x == NULL)
		x = "(null)";

	for (i = 0; x[i] != '\0'; i++)
	{
		_putchar(x[i]);
	}
	return (i);
}
/**
 * _per - print percentage.
 * @vlist:the argument we will print .
 * Return:1.
 */
int _per(__attribute__((unused)) va_list vlist)
{
	_putchar('%');
	return (1);
}
