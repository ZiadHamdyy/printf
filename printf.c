#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * get_fun - return the function of the specifier
 * @ch: the sepcifier
 * Return: a function of NULL if not found
 */
int (*get_fun(char ch))(va_list vlist)
{
	int j = 0;

	flag_t sps[] = {
		{'c', _char}, {'s', _str}, {'%', _per},
		{'d', _int}, {'i', _int}, {'b', _binary},
		{'r', rev_string}, {'\0', NULL}
	};

		while (sps[j].f)
		{
			if (sps[j].sp == ch)
			{
				return (sps[j].f);
			}
			j++;
		}
		return (NULL);
}
/**
 * _printf - printf function.
 * @format:string to be printed.
 * Return:lenght of string.
 * or 0 or -1 or 1.
 */
int _printf(const char *format, ...)
{
	int i, len = 0;
	va_list vlist;

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
			if (!get_fun(format[i + 1]))
				len += _putchar('%');
			else
			{
				len += get_fun(format[i + 1])(vlist);
				i++;
			}
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
