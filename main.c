#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i, j;

	i = _printf("%d\n", 1042);
	j = printf("%d\n", 1042);
	printf("%d\n%d", i, j);
	return (0);
}
