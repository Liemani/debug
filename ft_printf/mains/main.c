#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int	i;

	i = -1;
	ft_printf("hi \n");
	ft_printf("i [as %%d] -> [%d] \n", i);
	printf("i [as %%d] -> [%d] \n", i);
	ft_printf("i [as %%p] -> [%p] \n", &i);
	printf("i [as %%p] -> [%p] \n", &i);
	ft_printf("i [as %%05.*i] -> [%05.*i] \n", i, i);
	printf("i [as %%05.*i] -> [%05.*i] \n", i, i);
//	ft_printf(

	return (0);
}
