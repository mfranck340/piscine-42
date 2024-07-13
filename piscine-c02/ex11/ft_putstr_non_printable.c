/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:51:40 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/13 13:27:05 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_hex(char car)
{
	char	*c;

	c = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &c[car / 16], 1);
	write(1, &c[car % 16], 1);
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
			write_hex(str[i]);
		i++;
	}
}

/*
int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas \tbien ?");
}
*/
