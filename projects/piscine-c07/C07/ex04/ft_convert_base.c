/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <ffierro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:05:07 by ffierro-          #+#    #+#             */
/*   Updated: 2024/08/12 19:37:10 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_length(char *str);
int	validate_base(char *base);
int	ft_atoi_base(char *str, char *base);

int	get_new_length(int number, int size_base)
{
	int	length;

	length = 0;
	if (number < 0)
		length++;
	while (number != 0)
	{
		number /= size_base;
		length++;
	}
	return (length);
}

char	*convert_number(int number, char *base_to, int size_to)
{
	char	*res;
	int		new_length;

	new_length = get_new_length(number, size_to);
	res = (char *)malloc(sizeof(char) * (new_length + 1));
	if (res == NULL)
		return (0);
	if (number < 0)
	{
		res[0] = '-';
		number *= -1;
	}
	res[new_length] = '\0';
	while (new_length > 0 && number != 0)
	{
		res[new_length - 1] = base_to[number % size_to];
		number /= size_to;
		new_length--;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		size_from;
	int		size_to;
	int		number;

	if (!validate_base(base_from) || !validate_base(base_to))
		return (0);
	size_from = ft_length(base_from);
	size_to = ft_length(base_to);
	if (size_from < 2 || size_to < 2)
		return (0);
	number = ft_atoi_base(nbr, base_from);
	return (convert_number(number, base_to, size_to));
}

/*
int	main(void)
{
	char *nbr = "-101010";
	char *base_from = "01";
	char *base_to = "0123456789";
	char *resul;

	resul = ft_convert_base(nbr, base_from, base_to);
	write(1, "ini\n", 4);
	printf("%s\n", resul);
	write(1, "fin\n", 4);
	free(resul);
	return (0);
}
*/
