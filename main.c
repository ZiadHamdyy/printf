#include "main.h"
int main(void)
{
	int i, j;

	i = _printf("%d", (INT_MIN + INT_MAX));
	j = printf("\n%d\n", (INT_MIN + INT_MAX));
	printf("%d\n%d\n", i, j);
	return (0);
}
