/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:15:08 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/24 11:50:46 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	number;

	number = nb;
	while (!ft_is_prime(number))
		number++;
	return (number);
}

/*
int	main(void)
{
	printf("%d\n", ft_find_next_prime(44));
	printf("%d\n", ft_find_next_prime(2));
	printf("%d\n", ft_find_next_prime(66));
	printf("%d\n", ft_find_next_prime(89));
	printf("%d\n", ft_find_next_prime(120));
	printf("%d\n", ft_find_next_prime(2147483647));
}
*/
