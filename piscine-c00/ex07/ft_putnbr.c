/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:13:49 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/07 18:52:20 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	show_number(int nb)
{
	char	letter_aux;

	if (nb < 10)
	{
		letter_aux = nb + '0';
		write(1, &letter_aux, 1);
	}
	else
	{
		show_number(nb / 10);
		letter_aux = (nb % 10) + '0';
		write(1, &letter_aux, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		show_number(nb);
	}
}

/*
int	main(void)
{
	int	number;

	number = 42;
	ft_putnbr(number);
	ft_putnbr(-2147483648);
	ft_putnbr(453443);
	ft_putnbr(-89);
	return (0);
}
*/
