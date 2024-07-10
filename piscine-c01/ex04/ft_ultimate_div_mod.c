/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:38:45 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/08 20:20:38 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	n_aux;

	n_aux = *a % *b;
	*a = *a / *b;
	*b = n_aux;
}

/*
int	main(void)
{
	int	a;
	int	b;

	a = 25;
	b = 4;
	printf("%d - %d \n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("%d - %d \n", a, b);
}
*/
