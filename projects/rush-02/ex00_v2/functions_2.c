/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshidal <joshidal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:43:39 by joshidal          #+#    #+#             */
/*   Updated: 2024/07/21 23:36:12 by joshidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	count_lines(char *buffer)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == ':' && j == 1)
			return (-1);
		else if (buffer[i] == ':' && j == 0)
			j = 1;
		if (buffer[i] == '\n' && j == 1)
		{
			j = 0;
			count++;
		}
		else if (buffer[i] == '\n' && j == 0)
			return (-1);
		i++;
	}
	return (count);
}

int	get_lines(char *path)
{
	int		fd;
	int		i;
	int		count;
	int		numbytes;
	char	buffer[BUFFSIZE];

	count = 0;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	numbytes = read(fd, &buffer, BUFFSIZE);
	buffer[numbytes] = 0;
	if (numbytes > 0)
		count++;
	while (i < numbytes)
	{
		count += count_lines(buffer);
		numbytes = read(fd, &buffer, 256);
	}
	close(fd);
	return (count);
}

void	free_dictionary(t_dict dict)
{
	int	i;

	i = 0;
	while (dict.key[i])
	{
		free(dict.key[i]);
		free(dict.value[i]);
		i++;
	}
	free (dict.key);
	free (dict.value);
}
