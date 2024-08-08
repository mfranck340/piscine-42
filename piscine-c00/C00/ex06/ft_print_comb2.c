/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:42:11 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/07 18:57:32 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		n1;
	int		n2;
	char	n_aux;

	n1 = 0;
	while (n1 <= 99)
	{
		n2 = n1 + 1;
		while (n2 <= 99)
		{
			n_aux = (n1 / 10) + '0';
			write(1, &n_aux, 1);
			n_aux = (n1 % 10) + '0';
			write(1, &n_aux, 1);
			write(1, " ", 1);
			n_aux = (n2 / 10) + '0';
			write(1, &n_aux, 1);
			n_aux = (n2 % 10) + '0';
			write(1, &n_aux, 1);
			if (!(n1 == 98 && n2 == 99))
				write(1, ", ", 2);
			n2++;
		}
		n1++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
