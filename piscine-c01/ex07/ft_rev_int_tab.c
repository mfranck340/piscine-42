/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:43:55 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/08 20:23:18 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	n_aux;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		n_aux = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = n_aux;
		i++;
	}
}

/*
int	main(void)
{
	int	array[4] = {0, 1, 2, 3};

	printf("%d-%d-%d-%d\n", array[0], array[1], array[2], array[3]);
	ft_rev_int_tab(array, 4);
	printf("%d-%d-%d-%d\n", array[0], array[1], array[2], array[3]);
}
*/
