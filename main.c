#include "main.h"
#include <stdio.h>
int main()
{
	int i, j;
char* invalid_str = "Hello, World!";
char* ptr_to_invalid_memory = invalid_str - 100;
	i = _printf("%s", ptr_to_invalid_memory);
	j = printf("%s", ptr_to_invalid_memory);


	printf("%d%d\n", i , j);
	return (0);
}
