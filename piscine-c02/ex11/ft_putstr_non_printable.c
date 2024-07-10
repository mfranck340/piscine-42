/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:51:40 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/10 19:24:15 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	write_hex(char car)
{
	int		a;
	char	*c;

	c = "0123456789abcdef";
	write(1, "\\", 1);
	a = car;
	if (a < 16)
	{
		write(1, "0", 1);
		if (a < 10)
			write(1, &c[a], 1);
		else
			write(1, &c[a], 1);
	}
	else if (a < 32)
	{
		write(1, "1", 1);
		if (a - 16 < 10)
			write(1, &c[a], 1);
		else
			write(1, &c[a], 1);
	}
	else if (car == 127)
		write(1, "7f", 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write_hex(str[i]);
		}
		i++;
	}
}

/*
int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas \tbien ?");
}
*/
