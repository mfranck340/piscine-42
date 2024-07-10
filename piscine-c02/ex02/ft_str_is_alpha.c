/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:08:19 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/10 19:12:42 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'A' || str[i] > 'z'))
			return (0);
		else if ((str[i] < 'a' && str[i] > 'Z'))
			return (0);
		i++;
	}
	return (1);
}

/*
int	main(void)
{
	char	*cad;

	cad = "xdd";
	printf("%d", ft_str_is_alpha(cad));
}
*/
