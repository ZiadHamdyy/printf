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
			if (format[i + 1] == 's')
			{
				len += _str(vlist);
				i++;
			}
			if (format[i + 1] == '%')
			{
				len += _per(vlist);
				i++;
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
	_putchar(x);
	return (1);
}
int _str(va_list vlist)
{
	int i;
	char *x;

	x = va_arg(vlist, char *);
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
