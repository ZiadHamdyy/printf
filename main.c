#include "main.h"
#include <stdio.h>
int main()
{
	char x = '\0';
	int i, j;

	i = _printf("%c", x);
	j = printf("%c", x);


	printf("%d%d\n", i , j);
	return (0);
}
