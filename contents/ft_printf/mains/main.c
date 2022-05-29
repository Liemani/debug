#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "ft_printf.h"
#include "lmt.h"

#define FUNCTIONNAME test

void	test()
{
	ft_printf("%1234", 4321);
}

void	a011()
{
	int	i;

	printf(   "%--12.7dt%04i %04.2% et %c titi \n", 125, 124, 256);
	ft_printf("%--12.7dt%04i %04.2% et %c titi \n", 125, 124, 256);
	printf(   "%04.2c \n", 'a');
	ft_printf("%04.2c \n", 'a');
	printf(   "%04c \n", 'a');
	ft_printf("%04c \n", 'a');
	printf(   "%04.c \n", 'a');
	ft_printf("%04.c \n", 'a');
	printf(   "%04.p \n", &i);
	ft_printf("%04.p \n", &i);
	printf(   "[%030.2p] \n", &i);
	ft_printf("[%030.2p] \n", &i);
	printf(   "[%030.2s] \n", "abcd");
	ft_printf("[%030.2s] \n", "abcd");
}

void	a010()
{
	short		hi;

	hi = -135;
	printf(   "hi [as %%hi] -> [%hi] \n", hi);
	printf(   "hi [as %%-4.hi] -> [%-4.hi] \n", hi);
	ft_printf("hi [as %%-4.hi] -> [%-4.hi] \n", hi);
	for (int j = -1; j > -5; --j)
	{
		printf(   "j [as %%d] -> [%d] \n", j);
		printf(   "j, hi [as %%-4.*hi] -> [%-4.*hi] \n", j, hi);
		ft_printf("j, hi [as %%-4.*hi] -> [%-4.*hi] \n", j, hi);
	}
	hi = -58;
	printf(   "hi [as %%hi] -> [%hi] \n", hi);
	for (int j = 1; j < 5; ++j)
	{
		printf(   "j [as %%d] -> [%d] \n", j);
		printf(   "j, hi [as %% -4.*hi] -> [% -4.*hi] \n", j, hi);
		ft_printf("j, hi [as %% -4.*hi] -> [% -4.*hi] \n", j, hi);
	}
	printf(   "hi [as %% -4hi] -> [% -4hi] \n", hi);
	ft_printf("hi [as %% -4hi] -> [% -4hi] \n", hi);
}

void	a008_2()
{
	const int	array[] = {0xffffff79, 0xc6};
	int			X;

	for (int i = 0; i < 2; ++i)
	{
		X = array[i];
		printf(   "X [as %%d] -> [%d] \n", X);
		printf(   "X [as %%4.3hhX] -> [%4.3hhX] \n", X);
		ft_printf("X [as %%4.3hhX] -> [%4.3hhX] \n", X);
		printf(   "X [as %%4.4hhX] -> [%4.4hhX] \n", X);
		ft_printf("X [as %%4.4hhX] -> [%4.4hhX] \n", X);
		printf(   "X [as %%4hhX] -> [%4hhX] \n", X);
		ft_printf("X [as %%4hhX] -> [%4hhX] \n", X);
		printf(   "X [as %%4.hhX] -> [%4.hhX] \n", X);
		ft_printf("X [as %%4.hhX] -> [%4.hhX] \n", X);
		printf(   "X [as %%-4hhX] -> [%-4hhX] \n", X);
		ft_printf("X [as %%-4hhX] -> [%-4hhX] \n", X);
		printf(   "X [as %%-4.hhX] -> [%-4.hhX] \n", X);
		ft_printf("X [as %%-4.hhX] -> [%-4.hhX] \n", X);
		printf(   "-4, X [as %%-4.*hhX] -> [%-4.*hhX] \n", -4, X);
		ft_printf("-4, X [as %%-4.*hhX] -> [%-4.*hhX] \n", -4, X);

		printf(   "-4, X [as %%#-4.*hhX] -> [%#-4.*hhX] \n", -4, X);
		ft_printf("-4, X [as %%#-4.*hhX] -> [%#-4.*hhX] \n", -4, X);
		printf(   "X [as %%#-4.3hhX] -> [%#-4.3hhX] \n", X);
		ft_printf("X [as %%#-4.3hhX] -> [%#-4.3hhX] \n", X);
		printf(   "X [as %%#-4.4hhX] -> [%#-4.4hhX] \n", X);
		ft_printf("X [as %%#-4.4hhX] -> [%#-4.4hhX] \n", X);
		printf(   "X [as %%#-4hhX] -> [%#-4hhX] \n", X);
		ft_printf("X [as %%#-4hhX] -> [%#-4hhX] \n", X);
		printf(   "X [as %%#-4.hhX] -> [%#-4.hhX] \n", X);
		ft_printf("X [as %%#-4.hhX] -> [%#-4.hhX] \n", X);
	}
}

void	a009()
{
	const int	array[] = {-135, -1, 0};
	int			d;

	for (int i = 0; i < 3; ++i)
	{
		d = array[i];
		printf("d [as %%d] -> [%d] \n", d);
		printf(   "d [as %%+4.3d] -> [%+4.3d] \n", d);
		ft_printf("d [as %%+4.3d] -> [%+4.3d] \n", d);
		printf(   "d [as %%+4.4d] -> [%+4.4d] \n", d);
		ft_printf("d [as %%+4.4d] -> [%+4.4d] \n", d);
		printf(   "d [as %%+4d] -> [%+4d] \n", d);
		ft_printf("d [as %%+4d] -> [%+4d] \n", d);
		printf(   "d [as %% -4.d] -> [% -4.d] \n", d);
		ft_printf("d [as %% -4.d] -> [% -4.d] \n", d);
		printf(   "-4, d [as %% -4.*d] -> [% -4.*d] \n", -4, d);
		ft_printf("-4, d [as %% -4.*d] -> [% -4.*d] \n", -4, d);
		printf(   "d [as %% -4.4d] -> [% -4.4d] \n", d);
		ft_printf("d [as %% -4.4d] -> [% -4.4d] \n", d);
		printf(   "d [as %% -4d] -> [% -4d] \n", d);
		ft_printf("d [as %% -4d] -> [% -4d] \n", d);
		printf(   "d [as %%-4.d] -> [%-4.d] \n", d);
		ft_printf("d [as %%-4.d] -> [%-4.d] \n", d);
		printf(   "-4, d [as %%-4.*d] -> [%-4.*d] \n", -4, d);
		ft_printf("-4, d [as %%-4.*d] -> [%-4.*d] \n", -4, d);
		printf(   "-3, d [as %%-4.*d] -> [%-4.*d] \n", -3, d);
		ft_printf("-3, d [as %%-4.*d] -> [%-4.*d] \n", -3, d);
	}
}

void	a008()
{
	const int	array[] = {0xffffff79, 0xc6};
	int			x;

	for (int i = 0; i < 2; ++i)
	{
		x = array[i];
		printf(   "x [as %%d] -> [%d] \n", x);
		printf(   "x [as %%4.3hhx] -> [%4.3hhx] \n", x);
		ft_printf("x [as %%4.3hhx] -> [%4.3hhx] \n", x);
		printf(   "x [as %%4.4hhx] -> [%4.4hhx] \n", x);
		ft_printf("x [as %%4.4hhx] -> [%4.4hhx] \n", x);
		printf(   "x [as %%4hhx] -> [%4hhx] \n", x);
		ft_printf("x [as %%4hhx] -> [%4hhx] \n", x);
		printf(   "x [as %%4.hhx] -> [%4.hhx] \n", x);
		ft_printf("x [as %%4.hhx] -> [%4.hhx] \n", x);
		printf(   "x [as %%-4hhx] -> [%-4hhx] \n", x);
		ft_printf("x [as %%-4hhx] -> [%-4hhx] \n", x);
		printf(   "x [as %%-4.hhx] -> [%-4.hhx] \n", x);
		ft_printf("x [as %%-4.hhx] -> [%-4.hhx] \n", x);
		printf(   "-4, x [as %%-4.*hhx] -> [%-4.*hhx] \n", -4, x);
		ft_printf("-4, x [as %%-4.*hhx] -> [%-4.*hhx] \n", -4, x);

		printf(   "-4, x [as %%#-4.*hhx] -> [%#-4.*hhx] \n", -4, x);
		ft_printf("-4, x [as %%#-4.*hhx] -> [%#-4.*hhx] \n", -4, x);
		printf(   "x [as %%#-4.3hhx] -> [%#-4.3hhx] \n", x);
		ft_printf("x [as %%#-4.3hhx] -> [%#-4.3hhx] \n", x);
		printf(   "x [as %%#-4.4hhx] -> [%#-4.4hhx] \n", x);
		ft_printf("x [as %%#-4.4hhx] -> [%#-4.4hhx] \n", x);
		printf(   "x [as %%#-4hhx] -> [%#-4hhx] \n", x);
		ft_printf("x [as %%#-4hhx] -> [%#-4hhx] \n", x);
		printf(   "x [as %%#-4.hhx] -> [%#-4.hhx] \n", x);
		ft_printf("x [as %%#-4.hhx] -> [%#-4.hhx] \n", x);
	}
}

void	a007()
{
	const int	array[] = {0xffffff79, 0xc6};
	int			x;

	for (int i = 0; i < 2; ++i)
	{
		x = array[i];
		printf(   "x [as %%d] -> [%d] \n", x);
		printf(   "x [as %%4.3x] -> [%4.3x] \n", x);
		ft_printf("x [as %%4.3x] -> [%4.3x] \n", x);
		printf(   "x [as %%4.4x] -> [%4.4x] \n", x);
		ft_printf("x [as %%4.4x] -> [%4.4x] \n", x);
		printf(   "x [as %%4x] -> [%4x] \n", x);
		ft_printf("x [as %%4x] -> [%4x] \n", x);
		printf(   "x [as %%4.x] -> [%4.x] \n", x);
		ft_printf("x [as %%4.x] -> [%4.x] \n", x);
		printf(   "x [as %%-4x] -> [%-4x] \n", x);
		ft_printf("x [as %%-4x] -> [%-4x] \n", x);
		printf(   "x [as %%-4.x] -> [%-4.x] \n", x);
		ft_printf("x [as %%-4.x] -> [%-4.x] \n", x);
		printf(   "-4, x [as %%-4.*x] -> [%-4.*x] \n", -4, x);
		ft_printf("-4, x [as %%-4.*x] -> [%-4.*x] \n", -4, x);

		printf(   "-4, x [as %%#-4.*x] -> [%#-4.*x] \n", -4, x);
		ft_printf("-4, x [as %%#-4.*x] -> [%#-4.*x] \n", -4, x);
		printf(   "x [as %%#-4.3x] -> [%#-4.3x] \n", x);
		ft_printf("x [as %%#-4.3x] -> [%#-4.3x] \n", x);
		printf(   "x [as %%#-4.4x] -> [%#-4.4x] \n", x);
		ft_printf("x [as %%#-4.4x] -> [%#-4.4x] \n", x);
		printf(   "x [as %%#-4x] -> [%#-4x] \n", x);
		ft_printf("x [as %%#-4x] -> [%#-4x] \n", x);
		printf(   "x [as %%#-4.x] -> [%#-4.x] \n", x);
		ft_printf("x [as %%#-4.x] -> [%#-4.x] \n", x);
	}
}

void	a006()
{
	int	array[] = {0, -1, -135};
	int	d;

	for (int i = 0; i < 3; ++i)
	{
		d = array[i];
		printf(   "(d) == (%d) \n", d);
		printf(   "-->|%+-4.d|<--\n", d);
		ft_printf("-->|%+-4.d|<--\n", d);
		printf(   "-->|%+-4.*d|<--\n", -4, d);
		ft_printf("-->|%+-4.*d|<--\n", -4, d);

		printf(   "-->|% -4.4d|<--\n", d);
		ft_printf("-->|% -4.4d|<--\n", d);

		printf(   "-->|% -4d|<--\n", d);
		ft_printf("-->|% -4d|<--\n", d);
	}
}

void	a005()
{
	for (int i = -1; i < 2; ++i)
		for (int k = 0; k < 11; k += 10)
			for (int j = -1; j < 6; ++j)
			{
				printf("(k, j, i) == (%d, %d, %d) \n", k, j, i);
				printf("k, j, i [as %% *.*d]   -> [% *.*d] \n", k, j, i);
				printf("k, j, i [as %%+ *.*d]  -> [%+ *.*d] \n", k, j, i);
				printf("k, j, i [as %% -*.*d]  -> [% *.*d] \n", k, j, i);
				printf("k, j, i [as %%+ -*.*d] -> [%+ *.*d] \n", k, j, i);
				putchar('\n');
			}
}

void	a004()
{
	for (int i = -1; i < 2; ++i)
		for (int k = 0; k < 11; k += 10)
			for (int j = -1; j < 6; ++j)
			{
				printf("(k, j, i) == (%d, %d, %d) \n", k, j, i);
				printf(   "printf   : k, j, i [as %%*.*o]   -> [%*.*o] \n", k, j, i);
				ft_printf("ft_printf: k, j, i [as %%*.*o]   -> [%*.*o] \n", k, j, i);
				printf(   "printf   : k, j, i [as %%0*.*o]  -> [%0*.*o] \n", k, j, i);
				ft_printf("ft_printf: k, j, i [as %%0*.*o]  -> [%0*.*o] \n", k, j, i);
				printf(   "printf   : k, j, i [as %%*.*x]   -> [%*.*x] \n", k, j, i);
				ft_printf("ft_printf: k, j, i [as %%*.*x]   -> [%*.*x] \n", k, j, i);
				printf(   "printf   : k, j, i [as %%0*.*x]  -> [%0*.*x] \n", k, j, i);
				ft_printf("ft_printf: k, j, i [as %%0*.*x]  -> [%0*.*x] \n", k, j, i);
				printf(   "printf   : k, j, i [as %%#*.*o]  -> [%#*.*o] \n", k, j, i);
				ft_printf("ft_printf: k, j, i [as %%#*.*o]  -> [%#*.*o] \n", k, j, i);
				printf(   "printf   : k, j, i [as %%#0*.*o] -> [%#0*.*o] \n", k, j, i);
				ft_printf("ft_printf: k, j, i [as %%#0*.*o] -> [%#0*.*o] \n", k, j, i);
				printf(   "printf   : k, j, i [as %%#*.*x]  -> [%#*.*x] \n", k, j, i);
				ft_printf("ft_printf: k, j, i [as %%#*.*x]  -> [%#*.*x] \n", k, j, i);
				printf(   "printf   : k, j, i [as %%#0*.*x] -> [%#0*.*x] \n", k, j, i);
				ft_printf("ft_printf: k, j, i [as %%#0*.*x] -> [%#0*.*x] \n", k, j, i);
				putchar('\n');
			}
}

void	a003()
{
	for (int i = -10; i < 11; ++i)
		for (int j = -10; j < 11; ++j)
		{
			printf("[i, j]: [%d, %d] \n", i, j);
			printf(   "printf   : NULL [as %%*.*ls] -> [%*.*ls] \n", i, j, (wchar_t *)NULL);
			ft_printf("ft_printf: NULL [as %%*.*ls] -> [%*.*ls] \n", i, j, (wchar_t *)NULL);
			putchar('\n');
		}
}

void	a002()
{
	for (int i = -10; i < 11; ++i)
		for (int j = -10; j < 11; ++j)
		{
			printf("[i, j]: [%d, %d] \n", i, j);
			printf("printf   : NULL [as %%*.*s]  -> [%*.*s] \n", i, j, (char *)NULL);
			printf("printf   : NULL [as %%*.*ls] -> [%*.*ls] \n", i, j, (wchar_t *)NULL);
			putchar('\n');
		}
}

void	a001()
{
	wchar_t	*ws;

	setlocale(LC_ALL, "");
	ws = L"감자";
	for (int i = -10; i < 11; ++i)
		for (int j = -10; j < 11; ++j)
		{
			printf("[i, j]: [%d, %d] \n", i, j);
			printf(   "printf    :  i, j, ws [as %%*.*ls] -> [%*.*ls] \n", i, j, ws);
			ft_printf("ft_printf :  i, j, ws [as %%*.*ls] -> [%*.*ls] \n", i, j, ws);
			putchar('\n');
		}
}

void	a000()
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

}

int main()
{
	FUNCTIONNAME();
	return (0);
}
