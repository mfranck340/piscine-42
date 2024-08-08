/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:50:41 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/23 20:42:13 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	number;

	if (nb < 0)
		return (0);
	number = 0;
	while (number * number <= nb)
	{
		if (number * number == nb)
			return (number);
		number++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(49));
	printf("%d\n", ft_sqrt(48));
}
*/
