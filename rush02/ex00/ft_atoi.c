#include "ft_lib.h"

long ft_atoi(char *str)
{
	long numero;
	int negativo;
	int i;

	numero = 0;
	negativo = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			negativo = -negativo;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numero = numero * 10 + str[i] - 48;
		i++;
	}
	return (numero * negativo);
}

long ft_atoi2(char *t)
{
	long result;
	int negative;
	result = 0;

	negative = 1;
	while ((*t == ' ') || (*t >= 9 && *t <= 13))
		t++;
	while (*t == '-' || *t == '+')
	{
		if (*t == '-')
			negative = -negative;
		t++;
	}
	while(*t >= '0' && *t <= '9')
	{
		if(result >  4294967295)
			return (-1);
		result = (result * 10) + (*t - '0');
		t++;
	}
	return (result * negative);
}