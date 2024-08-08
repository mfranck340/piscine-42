/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshidal <joshidal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:39:49 by joshidal          #+#    #+#             */
/*   Updated: 2024/07/21 20:31:08 by joshidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFSIZE 4096

typedef struct s_dict
{
	char	**key;
	char	**value;
}	t_dict;

int		main(int argc, char *argv[]);
/*order_data.c*/
char	*save_key(char *buffer);
char	*save_value(char *buffer);
t_dict	complete_dictionary(t_dict dict, char *buffer);
t_dict	create_dictionary(int lines, int fd);
int		order_data(char *nbr, char *path);
/*functions.c*/
void	ft_printstr(char *str);
int		ft_strlen(char *str);
int		chars_before_num(char *str);
int		num_length(char *str, int n);
char	*assign_numbers(char *str, int bf, int len);
/*functions2.c*/
int		count_lines(char *buffer);
int		get_lines(char *path);
void	free_dictionary(t_dict dict);
/*ft_atoi*/
long	ft_atoi(char *str);
/*get_solution.c*/
int		get_solution(char *nbr, t_dict dict);
void	ft_print_tens(char *nbr, t_dict dict);
void	ft_print_hundreds(char *nbr, int len, t_dict dict);
void	ft_print_separator(int i, t_dict dict);
void	ft_print_numbers(char *nb, int len, t_dict dict);
#endif
