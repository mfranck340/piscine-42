/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshidal <joshidal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:30:18 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/21 23:26:09 by joshidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*save_key(char *buffer)
{
	int		i;
	int		len;
	char	*key;

	i = 0;
	len = 0;
	while (buffer[len] != ':')
		len++;
	key = malloc(len + 1);
	key[len] = 0;
	while (i < len)
	{
		key[i] = buffer[i];
		i++;
	}
	return (key);
}

char	*save_value(char *buffer)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	len = 0;
	while (buffer[len] != '\n')
		len++;
	value = malloc(len);
	value[len - 1] = 0;
	while (i < len -1)
	{
		value[i] = buffer[i + 1];
		i++;
	}
	return (value);
}

t_dict	complete_dictionary(t_dict dict, char *buffer)
{
	int	is_key;
	int	i;

	is_key = 1;
	i = 0;
	while (*buffer)
	{
		if (is_key)
		{
			dict.key[i] = save_key(buffer);
			buffer += ft_strlen(dict.key[i]) + 1;
			is_key = 0;
		}
		if (is_key == 0)
		{
			dict.value[i] = save_value(buffer);
			buffer += ft_strlen(dict.value[i]) + 1;
			is_key = 1;
		}
		i++;
	}
	return (dict);
}

t_dict	create_dictionary(int lines, int fd)
{
	t_dict	dict;
	char	buffer[BUFFSIZE];
	int		buff;

	dict.key = (char **) malloc(sizeof(char *) * (lines + 1));
	dict.value = (char **) malloc(sizeof(char *) * (lines + 1));
	dict.key[lines] = NULL;
	dict.value[lines] = NULL;
	buff = read(fd, &buffer, BUFFSIZE);
	buffer[buff] = 0;
	dict = complete_dictionary(dict, buffer);
	return (dict);
}

int	order_data(char *nbr, char *path)
{
	int		dict_lines;
	int		fd;
	t_dict	dict;

	dict_lines = get_lines(path);
	if (dict_lines <= 0)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	dict = create_dictionary(dict_lines, fd);
	get_solution(nbr, dict);
	free_dictionary(dict);
	return (0);
}
