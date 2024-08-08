/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:52:22 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/16 19:27:09 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_length(char *str)
{
	int	i;

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
		if (base[i] == '+' || base[i] == '-')
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

void	show_new_number(int number, char *base, int size)
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
	int	size;
	int	number;

	size = ft_length(base);
	if (size > 1 && validate_base(base))
	{
		number = nbr;
		if (nbr < 0)
		{
			write(1, "-", 1);
			number *= -1;
		}
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
