/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <ffierro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:36:55 by ffierro-          #+#    #+#             */
/*   Updated: 2024/08/10 17:25:29 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(char *number, int n)
{
	write(1, number, n);
}

void	generate_number(int ini, int n, char *number)
{
	int		limit;
	char	n_char;

	if (n == 0)
	{
		write(1, number, ini);
		if (number[0] != (10 - ini) + '0') 
			write(1, ", ", 2);
	}
	else
	{
		if (ini == 0)
			n_char = '0';
		else
			n_char = number[ini - 1] + 1;
		limit = (10 - n) + '0';
		while (n_char <= limit)
		{
			number[ini] = n_char;
			generate_number(ini + 1, n - 1, number);
			n_char++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	number[10];

	if (n > 0 && n < 10)
	{
		number[n] = '\0';
		generate_number(0, n, number);
	}
}

/*
int	main(void)
{
	ft_print_combn(5);
	write(1, "\n", 1);
	ft_print_combn(3);
	write(1, "\n", 1);
	ft_print_combn(4);
	return (0);
}*/
