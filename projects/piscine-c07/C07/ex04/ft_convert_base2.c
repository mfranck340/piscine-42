/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <ffierro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:06:51 by ffierro-          #+#    #+#             */
/*   Updated: 2024/08/12 19:07:08 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] == '+' || base[i] == '-')
			|| ((base[i] >= 0 && base[i] <= 31) || base[i] == 127))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_str_limit(char *str, char *base)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while (str[i] != '\0')
	{
		found = 0;
		j = 0;
		while (base[j] != '\0' && !found)
		{
			if (base[j] == str[i])
				found = 1;
			j++;
		}
		if (!found)
			return (i);
		i++;
	}
	return (i);
}

int	get_new_number(char *str, char *base, int size_base, int length)
{
	int	i;
	int	j;
	int	idx_char;
	int	number;
	int	n_pow;

	number = 0;
	i = 0;
	while (i < length)
	{
		idx_char = 0;
		while (base[idx_char] != '\0' && base[idx_char] != str[i])
			idx_char++;
		j = 0;
		n_pow = 1;
		while (j < length - i - 1)
		{
			n_pow *= size_base;
			j++;
		}
		number += idx_char * n_pow;
		i++;
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	length;
	int	size;
	int	sign;
	int	number;

	number = 0;
	size = ft_length(base);
	if (size > 1 && validate_base(base))
	{
		i = 0;
		sign = 1;
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		length = get_str_limit(&str[i], base);
		number = get_new_number(&str[i], base, size, length);
	}
	return (sign * number);
}
