#include "ft_lib.h"

int		ft_count_longest(char *p, int size)
{
	int		count;
	int		count2;
	int		i;
	char 	*r;

	i = 0;
	count2 = 0;
	while (i < size - 1)
	{
		if (p[i] >= 'a' && p[i] <= 'z')
		{	
			count = 0;
			r = &p[i];
			while(*r != '\n' && *r != '\0')
			{
				r++;
				count++;
			}
			if(count > count2)
				count2 = count;
		}
		i++;
	}
	return(count2);
}

int ft_count_lines(char *str, unsigned int size)
{
	unsigned int i;
	int count;
	i = 0;
	count = 0;
	while (i < size)
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	if (str[i] == '\0' && str[i - 1] != '\n')
		count++;
	return (count);
}