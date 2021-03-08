#include <stdio.h>

int main()
{
	char	c;

	c = 'b';
	printf("c [as %%c] -> [%c] \n", c);
	printf("c [as %%llc] -> [%llc] \n", c);
}
