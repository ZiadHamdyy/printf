#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
int _char(va_list vlist);
int _str(va_list vlist);
int _per(va_list vlist);
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
			if (format[i + 1] == 'c')
			{
				len += _char(vlist);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				len += _str(vlist);
				i++;
			}
			else if (format[i + 1] == '%')
			{
				len += _per(vlist);
				i++;
			}
			else if (format[i + 1] == '\0' || format[i + 1] == ' ')
			{
				return (-1);
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				len += _int(vlist);
				i++;
			}
			else
			{
				len += _putchar('%');
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
int _int(va_list vlist)
{
	int n, nc, d, nd = 0 ,div = 1, i, len = 0;


	n = va_arg(vlist, int);

	nc = n;
	if (nc == 0)
	{
		nd = 1;
	}
	else
	{
		while (nc > 0)
		{
			nc /= 10;
			nd++;
		}
	}
	if (n < 0)
	{
		len += _putchar('-');
		n = -n;
	}
	for (i = 1; i < nd; ++i)
		div *= 10;
	while (div != 0)
	{
		d = n / div;
		len += _putchar('0' + d);
		n %= div;
		div /= 10;
	}
		return (len);
}
