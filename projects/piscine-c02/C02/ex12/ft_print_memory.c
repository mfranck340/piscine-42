/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <ffierro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:42:26 by ffierro-          #+#    #+#             */
/*   Updated: 2024/08/11 13:44:22 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	print_address(long addr)
{
	char	*hex;
	char	buffer[16];
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (addr > 0 && i >= 0)
	{
		buffer[i] = hex[addr % 16];
		addr /= 16;
		i--;
	}
	while (i >= 0)
	{
		buffer[i] = '0';
		i--;
	}
	write(1, buffer, 16);
}

void	print_characters(char *addr, unsigned int i, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (addr[j] >= 32 && addr[j] <= 126)
			write(1, &addr[j], 1);
		else
			write(1, ".", 1);
		j++;
	}
}

void	print_sec_hex(char *str, int i, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		print_hex((unsigned char)str[i + j]);
		if (j % 2)
			write(1, " ", 1);
		j++;
	}
	while (j < 16)
	{
		write(1, "  ", 2);
		if (j % 2)
			write(1, " ", 1);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	long			l_addr;
	char			*str;

	i = 0;
	while (i < size)
	{
		str = (char *)addr;
		l_addr = (long)str + i;
		print_address(l_addr);
		write(1, ": ", 2);
		print_sec_hex(str, i, size);
		print_characters(str + i, i, size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

/*
int	main(void)
{
	char *str = "Bonjour les aminches\t\n\tc  est fou.tout.ce qu on peut 
	faire avec...print_memory..lol.lol. ";
	ft_print_memory(str, 92);
	return (0);
}
*/
