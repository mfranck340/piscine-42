/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <ffierro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:45:25 by ffierro-          #+#    #+#             */
/*   Updated: 2024/08/13 21:56:13 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	if (str[0] != '\0')
	{
		if (!is_charset(str[0], charset))
			count++;
	}
	else
		return (0);
	i = 1;
	while (str[i] != '\0')
	{
		if (!is_charset(str[i], charset) && is_charset(str[i - 1], charset))
			count++;
		i++;
	}
	return (count);
}

int	save_memory(char *str, char *charset, char **result, int j)
{
	int	k;

	k = 0;
	while (str[k] != '\0' && !is_charset(str[k], charset))
		k++;
	result[j] = (char *) malloc(sizeof(char) * (k + 1));
	if (result[j] == NULL)
	{
		while (j >= 0)
		{
			free(result[j]);
			j--;
		}
		free(result);
		return (0);
	}
	result[j][k] = '\0';
	return (1);
}

int	split_str(char *str, char *charset, char **result)
{
	int	j;
	int	k;

	j = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			if (!save_memory(str, charset, result, j))
				return (0);
			k = 0;
			while (*str && !is_charset(*str, charset))
			{
				result[j][k] = *str++;
				k++;
			}
			j++;
		}
		else
			str++;
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		size;

	size = count_words(str, charset);
	result = (char **) malloc(sizeof(char *) * (size + 1));
	if (result == NULL)
		return (0);
	result[size] = '\0';
	if (!split_str(str, charset, result))
		return (0);
	return (result);
}

/*
int	main(void)
{
	char	*str;
	char	*charset;
	char	**result;
	char	**tmp;

	str = "COSITA? cosita,y,mas cositas";
	result = ft_split(str, charset);
	tmp = result;
	while (*result)
	{
		printf("%s\n", *result);
		free(*result);
		result++;
	}
	free(tmp);
	return (0);
}
*/
