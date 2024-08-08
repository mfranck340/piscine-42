/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshidal <joshidal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:44:26 by joshidal          #+#    #+#             */
/*   Updated: 2024/07/21 18:25:00 by joshidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_printstr(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	chars_before_num(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	return (i);
}

int	num_length(char *str, int n)
{
	int	i;

	i = 0;
	while (str[n + i] >= '0' && str[n + i] <= '9')
		i++;
	return (i);
}

char	*assign_numbers(char *str, int bf, int len)
{
	char	*nb;
	int		i;

	i = 0;
	nb = malloc((len + 1) * sizeof(char));
	nb[len] = 0;
	while (i < len)
	{
		nb[i] = str[bf + i];
		i++;
	}
	return (nb);
}
