/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhidalgo <jhidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:49:17 by jhidalgo          #+#    #+#             */
/*   Updated: 2021/03/14 21:53:11 by jhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	ft_hundreds(int tmp, long *dct_num, char **dct_c, int len)
{
	ft_nbr2cpos(tmp, dct_num, dct_c, len);
	ft_print(dct_c[len]);
}

void	ft_ifmidnunmbers(unsigned int num, long *dct_num, char **dct_c, int pos)
{
	int tmp;

	tmp = (num / dct_num[pos]);

	if ((num > 99 && tmp == 1))
	{
		ft_nbr2cpos(tmp, dct_num, dct_c, pos);
		ft_print(dct_c[pos]);
	}
	else if ((num >= dct_num[pos] && num <= 99) && (tmp > 0 && tmp <= 20))
	{
		ft_print(dct_c[pos]);
	}
	else if ((num >= dct_num[pos] && num > 99) && (tmp > 0 && tmp <= 9))
	{
		ft_hundreds(tmp, dct_num, dct_c, pos);
		if (num % (tmp * dct_num[pos]) != 0)
		{
			ft_print("and");
		}
	}
}

void	ft_midnumbers(unsigned int num, long *dct_num, char **dct_c, int len)
{
	int i;
	int tmp;

	i = 1;
	while ((len - i) > 0 && num != 0)
	{
		tmp = (num / dct_num[len - i]);
		if (num < dct_num[len - i] || dct_num[len - i] < 0)
		{
			i++;
		}
		else if (((num >= dct_num[len - i]) && (num > 99 && tmp == 1)) ||
		((num >= dct_num[len - i] && num <= 99) && (tmp > 0 && tmp <= 20)) ||
		((num >= dct_num[len - i] && num > 99) && (tmp > 0 && tmp <= 9)))
		{
			ft_ifmidnunmbers(num, dct_num, dct_c, (len - i));
			num = num - tmp * dct_num[len - i];
			i = 1;
		}
		else if (num >= dct_num[len - i] && (tmp > 20 && tmp < 99))
		{
			i++;
		}
	}
}

void	ft_numzero(unsigned int num, long *dct_num, char **dct_c, int len)
{
	int i;

	i = 0;
	while (num != dct_num[len - i])
	{
		i++;
	}
	ft_print(dct_c[len - i]);
}

void	ft_assignationif(unsigned int num, long *dct_num, char **dct_c, int pos)
{
	int tmp;

	tmp = (num / dct_num[pos]);
	if (num >= 100 && num < 999)
	{
		ft_nbr2c(tmp, dct_num, dct_c, pos);
		ft_print(dct_c[pos]);
		if (num % (tmp * dct_num[pos]) != 0)
		{
			ft_print("and");
		}
	}
	else if (num >= 1000)
	{
		ft_nbr2c(tmp, dct_num, dct_c, pos);
		ft_print(dct_c[pos]);
	}
	else
	{
		ft_print(dct_c[pos]);
	}
}

void	ft_assignationif2(unsigned int num, long *dct_num, char **dct_c, int pos)
{
	int tmp;
	tmp = (num / dct_num[pos]);
	if (num == dct_num[pos])
	{
		ft_print(dct_c[pos]);
		num = num - dct_num[pos];
	}
	else if (num >= dct_num[pos])
	{
		if (tmp > 0 && tmp <= 20)
		{
			ft_assignationif(num, dct_num, dct_c, pos);
		}
		else if (tmp > 20 && tmp < 999)
		{
			ft_midnumbers(tmp, dct_num, dct_c, pos);
			ft_print(dct_c[pos]);
		}

	}
}

void	ft_assignation(unsigned int num, long *dct_num, char **dct_c, int len)
{
	int				i;
	unsigned int	tmp;

	i = 1;
	if (num == 0)
		ft_numzero(num, dct_num, dct_c, len);
	else
	{
		i = 1;
		while ((len - i) > 0)
		{
			tmp = (num / dct_num[len - i]);
			if (num < dct_num[len - i] || dct_num[len - i] < 0)
				i++;
			else if (num >= dct_num[len - i])
			{
				ft_assignationif2(num, dct_num, dct_c, (len - 1));
				num = num - (tmp * dct_num[len - i]);
				i = 1;
			}
			else
			{
				i++;
			}
		}
	}
}
