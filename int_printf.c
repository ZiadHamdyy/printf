#include "main.h"
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
    return counter;
}
int _int(va_list vlist)
{
    int x = va_arg(vlist, int);
    int i = 0,len, f = 0;
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
    if(x < 0)
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
