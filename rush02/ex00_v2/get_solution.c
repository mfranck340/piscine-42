/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshidal <joshidal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:18:28 by joshidal          #+#    #+#             */
/*   Updated: 2024/07/21 23:28:04 by joshidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

	/*
	1. VER LA LONGITUD DEL STRING QUE NOS PASA (MÁXIMO 3).
	COGER SÓLO LOS PRIMEROS 3 CARACTERES SI LONGITUD ES MAYOR QUE TRES.
	SI 3 CARACTERES: 
		[0] -> WRITE (DICT.VALUE[NUMERO DE NBR[0]]);
		WRITE DICT.VALUE[29] (HUNDRED);
		WRITE 'AND'
		[1] -> 
			IF NBR[1] > 1 -> WRITE DICT.VALUE[19 + NUMERO DE NBR[1]];
				WRITE DICT.VALUE[NBR[2]];
			ELSE NBR <= 1 -> ASIGNAR DECENAS Y UNIDADES DE LOS
			PRIMEROS 21 ELEMENTOS.  	

	!!!!!!CUIDADO CON LOS CEROS!!!!!!!!
	*/

void	ft_print_tens(char *nbr, t_dict dict)
{
	char	nb[2];
	int		n;

	nb[0] = nbr[0];
	nb[1] = nbr[1];
	n = 0;
	if (nbr[0] > '1')
	{
		ft_printstr(dict.value[18 + nbr[0] - '0']);
		if (nbr[1] != '0')
		{
			ft_printstr("-");
			ft_printstr(dict.value[nbr[1] - '0']);
		}
	}
	else if (nb[0] == '1')
	{
		n = ft_atoi(nb);
		ft_printstr(dict.value [n]);
	}
}

void	ft_print_hundreds(char *nbr, int len, t_dict dict)
{
	if (len == 0 && *nbr)
	{
		ft_printstr(dict.value[nbr[0] - '0']);
		ft_printstr(" ");
		ft_printstr(dict.value[28]);
		ft_printstr(" and ");
		if (nbr[1] > '1')
		{
			ft_printstr(dict.value[18 + nbr[1] - '0']);
			if (nbr[2] != '0')
			{
				ft_printstr("-");
				ft_printstr(dict.value[nbr[2] - '0']);
				ft_printstr(" ");
			}
		}
		else if (nbr[1] == 1)
			ft_printstr(dict.value[(nbr[1] - '0') * 10 + (nbr[2] - '0')]);
	}
	if (len == 2)
		ft_print_tens(nbr, dict);
	if (len == 1)
		ft_printstr(dict.value[nbr[0] - '0']);
}

void	ft_print_separator(int i, t_dict dict)
{
	ft_printstr(dict.value[28 + i]);
	write(1, " and ", 5);
}

void	ft_print_numbers(char *nb, int len, t_dict dict)
{
	int	i;
	int	j;
	int	mod;

	j = 0;
	i = len / 3;
	mod = len % 3;
	while (i >= 0)
	{
		ft_print_hundreds(&nb[3 * j], mod, dict);
		nb += mod;
		if (i > 1)
		{
			if (mod == 0)
				ft_print_separator(i - 1, dict);
			else
				ft_print_separator(i, dict);
		}
		if ((mod == 0 && i != 0) || (mod == 0 && i > 0))
			nb += 3;
		else if (mod != 0)
			nb += mod;
		i--;
	}
}

int	get_solution(char *nbr, t_dict dict)
{
	int		bf;
	int		len;
	char	*nb;

	bf = chars_before_num(nbr);
	len = num_length(nbr, bf);
	nb = assign_numbers(nbr, bf, len);
	ft_print_numbers(nb, len, dict);
	free (nb);
	return (0);
}
