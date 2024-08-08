/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:38:37 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/22 19:30:21 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	expand_square(t_map map, int i, int j, int n_rows)
{
	int	x;
	int	y;
	int	expand;
	int	size;

	size = 1;
	expand = 1;
	while (expand)
	{
		x = 0;
		while (x < size)
		{
			y = 0;
			while (y < size)
			{
				if (i + x >= n_rows 
					|| map.matrix[i + x][j + y] == map.symbols[1])
					return (size);
				y++;
			}
			x++;
		}
		size++;
	}
	return (size);
}

int	*search_square(t_map map, int n_rows)
{
	int	i;
	int	j;
	int	*coords;
	int	size_square;
	int	new_size;

	coords = (int *) malloc(sizeof(int) * 2);
	i = 0;
	size_square = 0;
	while (i < n_rows)
	{
		j = 0;
		while (map.matrix[i][j] != '\0')
		{
			if (map.matrix[i][j] == map.symbols[0])
			{
				new_size = expand_square(map, i, j, n_rows);
				if (new_size > size_square)
				{
					size_square = new_size;
					coords[0] = i;
					coords[1] = j;
				}
			}
			j++;
		}
		i++;
	}
	return (coords);
}

void	fill_square(t_map map, int *cords, int n_rows)
{
	int	x;
	int	y;
	int	size;

	size = 1;
	while (1)
	{
		x = 0;
		while (x < size)
		{
			y = 0;
			while (y < size)
			{
				map.matrix[cords[0] + x][cords[1] + y] = map.symbols[2];
				if (cords[0] + x >= n_rows
					|| map.matrix[cords[0] + x][cords[1] + y] == map.symbols[1])
					return ;
				y++;
			}
			x++;
		}
		size++;
	}
}



/*
int	main(int argc, char *argv[])
{

	int	**map;
	int	fd;
	char	buffer[1];
	fd = open(argv[1], "r");

	if (fd < 0)
		return (1);

	buffer = read(fd, buffer, 1);
	while (buffer > 0)
	{

	}

	close(fd);
}*/
