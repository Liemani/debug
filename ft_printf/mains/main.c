#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int	i;
	int j;
	int x;

	i = -1;
	j = 0;
	x = 0xfffff4;

	ft_printf("ft_printf() \n");
	ft_printf("i [as %%d] -> [%d] \n", i);
	ft_printf("i [as %%.d] -> [%.d] \n", j);
	ft_printf("i [as %%p] -> [%p] \n", &i);
	ft_printf("i [as %%05.*i] -> [%05.*i] \n", i, i);
	ft_printf("j [as %%d] -> [%d] \n", j);
	ft_printf("x [as %%x] -> [%x] \n", x);
	ft_printf("x [as %%X] -> [%X] \n", x);
	ft_printf("j [as %%.x] -> [%.x] \n", j);
	ft_printf("j [as %%.X] -> [%.X] \n", j);
	ft_printf("j [as %%.0x] -> [%.0x] \n", j);
	ft_printf("j [as %%.0X] -> [%.0X] \n", j);
	ft_printf("NULL [as %%-2s] -> [%-2s] \n", NULL);
	ft_printf("NULL [as %%-2.s] -> [%-2.s] \n", NULL);
	ft_printf("NULL [as %%1.s] -> [%1.s] \n", NULL);
	ft_printf("\"abcd\" [as %%1.s] -> [%1.s] \n", "abcd");
	ft_printf("NULL [as %%.s] -> [%.s] \n", NULL);
	ft_printf("NULL [as %%-4s] -> [%-4s] \n", NULL);
	ft_printf("NULL [as %%-2.4s] -> [%-2.4s] \n", NULL);
	ft_printf("NULL [as %%-8.12s] -> [%-8.12s] \n", NULL);
	ft_printf("NULL [as %%3s] -> [%3s] \n", NULL);
	ft_printf("NULL [as %%8s] -> [%8s] \n", NULL);
	ft_printf("NULL [as %%---2s] -> [%---2s] \n", NULL);
	ft_printf("-2, NULL [as %%.*s] -> [%.*s] \n", -2, NULL);
	ft_printf("NULL [as %%.0s] -> [%.0s] \n", NULL);
	ft_printf("NULL [as %%.1s] -> [%.1s] \n", NULL);
	ft_printf("NULL [as %%.2s] -> [%.2s] \n", NULL);
	ft_printf("NULL [as %%.4s] -> [%.4s] \n", NULL);
	ft_printf("NULL [as %%.8s] -> [%.8s] \n", NULL);
	ft_printf("NULL [as %%4.2s] -> [%4.2s] \n", NULL);
	ft_printf("NULL [as %%8.4s] -> [%8.4s] \n", NULL);
	ft_printf("NULL [as %%12.8s] -> [%12.8s] \n", NULL);
	ft_printf("NULL [as %%12.s] -> [%12.s] \n", NULL);
	ft_printf("-1, NULL [as %%12.*s] -> [%12.*s] \n", -1, NULL);
	ft_printf("\"0\" [as %%.s] -> [%.s] \n", "0");
	ft_printf("[as %%%%] -> [%%] \n");
	ft_printf("[as %%05%%] -> [%05%] \n");
	ft_printf("[as %%-05%%] -> [%-05%] \n");

	putchar('\n');
	printf("printf() \n");
	printf("i [as %%d] -> [%d] \n", i);
	printf("i [as %%.d] -> [%.d] \n", j);
	printf("i [as %%p] -> [%p] \n", &i);
	printf("i [as %%05.*i] -> [%05.*i] \n", i, i);
	printf("j [as %%d] -> [%d] \n", j);
	printf("x [as %%x] -> [%x] \n", x);
	printf("x [as %%X] -> [%X] \n", x);
	printf("j [as %%.x] -> [%.x] \n", j);
	printf("j [as %%.X] -> [%.X] \n", j);
	printf("j [as %%.0x] -> [%.0x] \n", j);
	printf("j [as %%.0X] -> [%.0X] \n", j);
	printf("NULL [as %%-2s] -> [%-2s] \n", NULL);
	printf("NULL [as %%-2.s] -> [%-2.s] \n", NULL);
	printf("NULL [as %%1.s] -> [%1.s] \n", NULL);
	printf("\"abcd\" [as %%1.s] -> [%1.s] \n", "abcd");
	printf("NULL [as %%.s] -> [%.s] \n", NULL);
	printf("NULL [as %%-4s] -> [%-4s] \n", NULL);
	printf("NULL [as %%-2.4s] -> [%-2.4s] \n", NULL);
	printf("NULL [as %%-8.12s] -> [%-8.12s] \n", NULL);
	printf("NULL [as %%3s] -> [%3s] \n", NULL);
	printf("NULL [as %%8s] -> [%8s] \n", NULL);
	printf("NULL [as %%---2s] -> [%---2s] \n", NULL);
	printf("-2, NULL [as %%.*s] -> [%.*s] \n", -2, NULL);
	printf("NULL [as %%.0s] -> [%.0s] \n", NULL);
	printf("NULL [as %%.1s] -> [%.1s] \n", NULL);
	printf("NULL [as %%.2s] -> [%.2s] \n", NULL);
	printf("NULL [as %%.4s] -> [%.4s] \n", NULL);
	printf("NULL [as %%.8s] -> [%.8s] \n", NULL);
	printf("NULL [as %%4.2s] -> [%4.2s] \n", NULL);
	printf("NULL [as %%8.4s] -> [%8.4s] \n", NULL);
	printf("NULL [as %%12.8s] -> [%12.8s] \n", NULL);
	printf("NULL [as %%12.s] -> [%12.s] \n", NULL);
	printf("-1, NULL [as %%12.*s] -> [%12.*s] \n", -1, NULL);
	printf("\"0\" [as %%.s] -> [%.s] \n", "0");
	printf("[as %%%%] -> [%%] \n");
	printf("[as %%05%%] -> [%05%] \n");
	printf("[as %%-05%%] -> [%-05%] \n");

	return (0);
}
