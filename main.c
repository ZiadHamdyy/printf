#include "main.h"
#include <stdio.h>
int main()
{
	char x = 'x';
	char *y = "ziad";
	int i, j;

	i = _printf("my name is %s %% %c\n", y, x);
	j = printf("my name is %s %% %c\n", y, x);


	printf("%d%d\n", i , j);
	return (0);
}
