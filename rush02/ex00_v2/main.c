/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshidal <joshidal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:30:09 by ffierro-          #+#    #+#             */
/*   Updated: 2024/07/21 23:08:40 by joshidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_error(void)
{
	write (1, "Dict Error\n", 11);
	return (-1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (order_data(argv[1], "numbers.dict") == -1)
			return (ft_error());
	}
	else if (argc == 3)
	{
		if (order_data(argv[2], argv[1]) == -1)
			return (ft_error());
	}
	else
		return (ft_error());
	return (0);
}

/*
	0. Control de errores. 
	1.- Meter el diccionario en nuestro diccionario.-> **dict.key y **dict.value
	2. Trabajar con el numero: 
	2.1 -> ver el numero de numeros que hay->módulo de 3 si hay más de 3 numeros.
	2.2 -> poder imprimir los numeros menores de mil. 
	2.3 -> asignar numeros menores de mil a los millones, billones, trillones 
	e ir para abajo con todo lo demás. 
*/
