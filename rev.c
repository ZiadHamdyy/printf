#include "main.h"
/**
 * rev_string_helper - revers a string.
 * @s:string.
 * @len:the lenght of the string.
 * Return:void.
 */
void rev_string_helper(char *s, int *len)
{
	if (*s == '\0')
		return;
	rev_string_helper(s + 1, len);
	_putchar(*s);
	(*len)++;
}
/**
 * rev_string - reverses a string.
 * @vlist:a string.
 * Return:the lenght of the string.
 */
int rev_string(va_list vlist)
{
	int len = 0;
	char *s;

	s = va_arg(vlist, char *);
	rev_string_helper(s, &len);
	return (len);

}
