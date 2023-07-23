#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
int _char(va_list vlist);
int _str(va_list vlist);
int _per(va_list vlist);
/**
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
			else
			{
				len += _putchar('%');

			}
		}
	}
	va_end(vlist);
	return (len);
}
int _char(va_list vlist)
{
	char x;
	x = va_arg(vlist, int);
	if (!x)
		x = '\0';
	_putchar(x);
	return (1);
}
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
int _per(__attribute__((unused)) va_list vlist)
{
	_putchar('%');
	return(1);
}
