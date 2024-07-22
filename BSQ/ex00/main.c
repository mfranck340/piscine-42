/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvera-ve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:42:11 by jvera-ve          #+#    #+#             */
/*   Updated: 2024/07/22 19:31:42 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int     *search_square(char **matrix, char *symbols, int n_rows);

int	get_nbr_of_lines(int fd, char **recipient)
{
	char	*aux;
	int		res;
	char	*box_status;

	res = 0;
	aux = (char *)malloc(sizeof(char) * 2);
	box_status = (char *)malloc(sizeof(char) * 1);
	while (read(fd, aux, 1) && (aux[0] != '\n'))
	{
		if (aux[0] >= '0' && aux[0] <= '9')
			res = res * 10 + (aux[0] - '0');
		else
		{
			box_status[0] = aux[0];
			read(fd, aux, 2);
			box_status[1] = aux[0];
			box_status[2] = aux[1];
		}
	}
	*recipient = box_status;
	return (res);
}

void	print_map(char **map, int nbr_lines)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbr_lines)
	{
		j = 0;
		while (j < nbr_lines)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	init_map(int fd, char ***recipient, int nbr_lines)
{
	char	**map;
	int		i;
	int		j;
	char	*aux;


	map = malloc(sizeof(char *) * nbr_lines + 1);
	aux = malloc(sizeof(char) * 1);
	i = 0;
	while (i < nbr_lines)
	{
		map[i] = malloc(sizeof(char *) * nbr_lines + 1);
		j = 0;
		while (j < nbr_lines)
		{
			read(fd, &map[i][j], 1);
			j++;
		}
		map[i][j] = '\0';
		read(fd, aux, 1);
		i++;
	}
	*recipient = map;
}

int main(int argc, char **args)
{
	int		fd;
	char	**map;
	char	*box_status;
	int		nbr_lines;
	int	*coords;

	fd = open(args[1], O_RDONLY);
	nbr_lines = get_nbr_of_lines(fd, &box_status);
	if (fd == -1 || !box_status)
	{
		free(box_status);
		write(1, "Error\n", 6);
		return (-1);
	}
	init_map(fd, &map, nbr_lines);

	coords = search_square(map, box_status, nbr_lines);

	print_map(map, nbr_lines);
	printf("%i\n", nbr_lines);
	printf("(%i,", coords[0]);
	printf("%i)\n", coords[1]);
	printf("%i\n", argc);
	printf("%s\n", box_status);
	//printf("%s", map[0]);
}

