/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:05:01 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/10 19:08:04 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

/*
int	main(void)
{
	char	*cad;
	char	cad2[15];

	cad = "cositas";
	printf("%s\n", cad);
	ft_strcpy(cad2, cad);
	printf("%s\n", cad2);
	return (0);
}
*/
