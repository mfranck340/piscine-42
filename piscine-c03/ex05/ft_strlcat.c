/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:18:23 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/15 17:54:47 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	length_dest;
	unsigned int	length_src;
	int				i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	length_dest = i;
	i = 0;
	while (src[i] != '\0')
		i++;
	length_src = i;
	if (length_dest + length_src >= size)
		return (size + length_src);
	i = 0;
	while (src[i] != '\0')
	{
		dest[length_dest + i] = src[i];
		i++;
	}
	dest[length_dest + i] = '\0';
	return (length_dest + length_src);
}

/*
int main(void)
{
	char	a[15] = "hola-";
	printf("%d - %s\n", ft_strlcat(a, "cosiitaa", 15), a);
}
*/
