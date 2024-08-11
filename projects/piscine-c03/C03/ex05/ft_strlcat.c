/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:18:23 by ffierro-          #+#    #+#             */
/*   Updated: 2024/08/11 20:44:11 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	length_dest;
	unsigned int	length_src;
	unsigned int	i;

	length_dest = 0;
	while (dest[length_dest] != '\0' && length_dest < size)
		length_dest++;
	length_src = 0;
	while (src[length_src] != '\0')
		length_src++;
	if (length_dest >= size)
		return (size + length_src);
	i = 0;
	while (src[i] != '\0' && (length_dest + i) + 1 < size)
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
