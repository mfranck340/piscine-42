/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <ffierro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:27:31 by ffierro-          #+#    #+#             */
/*   Updated: 2024/08/12 12:21:24 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	show_solution(char table[10][10])
{
	int		i;
	int		j;
	char	idx;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (table[i][j] == 'Q')
			{
				idx = j + '0';
				write(1, &idx, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

void	update_table(char table[10][10], int i, int j, int value)
{
	int	x;

	x = 0;
	while (x < 10)
	{
		if (x != i)
			table[x][j] += value;
		if (x != j)
			table[i][x] += value;
		x++;
	}
	x = -9;
	while (x <= 9)
	{
		if (i + x >= 0 && i + x < 10 && j + x >= 0 && j + x < 10 && x != 0)
			table[i + x][j + x] += value;
		if (i + x >= 0 && i + x < 10 && j - x >= 0 && j - x < 10 && x != 0)
			table[i + x][j - x] += value;
		x++;
	}
}

void	find_solution(char table[10][10], int *count, int n_pieza)
{
	int	i;

	if (n_pieza == 10)
	{
		show_solution(table);
		(*count)++;
	}
	else
	{
		i = 0;
		while (i < 10)
		{
			if (table[n_pieza][i] == '0')
			{
				table[n_pieza][i] = 'Q';
				update_table(table, n_pieza, i, 1);
				find_solution(table, count, n_pieza + 1);
				table[n_pieza][i] = '0';
				update_table(table, n_pieza, i, -1);
			}
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		count;
	char	table[10][10];
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			table[i][j] = '0';
			j++;
		}
		i++;
	}
	count = 0;
	find_solution(table, &count, 0);
	return (count);
}

/*
int	main(void)
{
	write(1, "inicio\n", 7);
	printf("N: %d\n", ft_ten_queens_puzzle());
	write(1, "fin\n", 4);
	return (0);
}
*/
