#include "main.h"
/**
 * int_len  - lenght of the string.
 * @x:int.
 * Return:the lenght of the string
 * if x = 0 return 1.
 */
int int_len(int x)
{
	int counter = 0;

	if (x == 0)
		return (1);
	if (x < 0)
	{
		counter++;
		x = -x;
	}
	while (x > 0)
	{
		counter++;
		x /= 10;
	}
	return (counter);
}
/**
 * _int - print a integer as a string.
 * @vlist:a integer.
 * Return:lenght of the string.
 */
int _int(va_list vlist)
{
	int x = va_arg(vlist, int);
	int i = 0, len, f = 0;
	int *z;

	if (x == INT_MIN)
	{
		write(1, "–2147483648", 13);
		return (11);
	}
	if (x == 0)
	{
		_putchar('0');
		return (1);
	}
	if (x < 0)
	{
		_putchar('-');
		x *= -1;
		f = 1;
	}
	len = int_len(x);
	z = malloc(sizeof(int) * len);
	while (x != 0)
	{
		z[i] = x % 10;
		i++;
		x = x / 10;
	}
	for (i = i - 1; i >= 0; i--)
		_putchar(z[i] + '0');
	free(z);

	if (f == 1)
		return (len  +  1);
	else
		return (len);
}
void int_binary(int x, int *len)
{

        if (x > 1)
                int_binary(x / 2, len);
        _putchar('0' + (x % 2));
	(*len)++;
}
int _binary(va_list vlist)
{
         int x, len = 0;

        x = va_arg(vlist, int);
	int_binary(x, &len);
	return (len);
}
