#include <unistd.h>
#include "ft_lib.h"

void	ft_print(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, " ", 1);
}

void	ft_nbr2c(unsigned int num, long *dct_num, char **dct_c, int len)
{
	while ((len - 1) >= 0)
	{
		if (num == (unsigned int)dct_num[len - 1])
		{
			ft_print(dct_c[len - 1]);
		}
		len--;
	}
}

void	ft_nbr2cpos(unsigned int num, long *dct_num, char **dct_c, int pos)
{
	while ((pos) >= 0)
	{
		if (num == (unsigned int)dct_num[pos])
		{
			ft_print(dct_c[pos]);
		}
		pos--;
	}
}