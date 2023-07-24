#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "main.h"
int int_len(int x)
{
    int counter = 0;
    if (x == 0)
        return (1);
    if (x < 0)
        x *= -1;
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
    int y, i = 0,len = int_len(x);
    int *z = malloc(sizeof(int) * len);
    
    if (x == INT_MIN)
    {
        write(1, "–2147483648", 13);
	free(z);
        return (12);
    }
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }
    while (x != 0)
    {
        y = x  % 10;
        z[i] = y;
        i++;
        x = x / 10;
    }
    for (i = i - 1; i > -1; i--)
     putchar(z[i] + '0');
	free(z);
        return (len);
}
