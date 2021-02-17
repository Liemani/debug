#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int	i;

	i = 10;
	ft_printf("hi \n");
	ft_printf("i [as %%d] -> [%d] \n", i);
	printf("i [as %%d] -> [%d] \n", i);
	ft_printf("i [as %%p] -> [%p] \n", &i);
	printf("i [as %%p] -> [%p] \n", &i);
//	ft_printf(

	return (0);
}
