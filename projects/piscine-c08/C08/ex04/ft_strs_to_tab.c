/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <ffierro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:40:09 by ffierro-          #+#    #+#             */
/*   Updated: 2024/08/14 17:14:20 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	if (*src == '\0')
		return (0);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	int			i;

	stock = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock)
		return (0);
	i = 0;
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		if (!stock[i].copy)
		{
			while (i > 0)
				free(stock[--i].copy);
			free(stock);
			return (0);
		}
		i++;
	}
	stock[i].str = 0;
	return (stock);
}

/*
int     main(void)
{
	int i;
	char *strs[] = {"Cositas", "y", "mas", "cositas"};
	t_stock_str *stock = ft_strs_to_tab(4, strs);
	if (!stock)
		return (1);
	ft_show_tab(stock);
	i = 0;
	while (stock[i].str)
	{
		free(stock[i].copy);
		i++;
	}
	free(stock);
	return (0);
}
*/
