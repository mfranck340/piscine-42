/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:32:49 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/08 20:23:53 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	n_aux;

	i = 0;
	j = -1;
	while (++i < size)
	{
		while (++j < size - i)
		{
			if (tab[j] > tab[j + 1])
			{
				n_aux = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = n_aux;
			}
		}
		j = -1;
	}
}

/*
int	main(void)
{
	int	a[5] = {32, 55, 33, 33, 12};

	printf("%d-%d-%d-%d-%d\n", a[0], a[1], a[2], a[3], a[4]);
	ft_sort_int_tab(a, 5);
	printf("%d-%d-%d-%d-%d", a[0], a[1], a[2], a[3], a[4]);
}
*/
