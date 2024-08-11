/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:52:22 by ffierro-          #+#    #+#             */
/*   Updated: 2024/08/11 21:17:01 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_length(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] == '+' || base[i] == '-')
			|| ((base[i] >= 0 && base[i] <= 31) || base[i] == 127))
			return (0);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	show_new_number(unsigned int number, char *base, unsigned int size)
{
	int	idx;

	if (number < size)
		write(1, &base[number], 1);
	else
	{
		show_new_number(number / size, base, size);
		idx = number % size;
		write(1, &base[idx], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	size;
	unsigned int	number;

	size = ft_length(base);
	if (size > 1 && validate_base(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			number = -nbr;
		}
		else
			number = nbr;
		show_new_number(number, base, size);
	}
}

/*
int	main(void)
{
	ft_putnbr_base(-3907, "poniguay");
	return (0);
}
*/
