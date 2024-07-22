#include <stdlib.h>
#include "ft_lib.h"

long *ft_find_numbers(char *p,int size)
{
	int i;
	int r;
	long *k;
	char *t;

	i = 0;
	r = 0;
	k = malloc((ft_count_lines(p, size))*4);
	while (i < size )
	{
		if (i == 0)
		{
			t = &p[i];
			k[r] = 0;
			r++;
		}
		if (p[i] == '\n' )
		{
			t = &p[i] + 1;
			k[r] = ft_atoi2(t);
			r++;
		}
		i++;
	}
	return(k);
}

char	**new_tab(char *p, int size)
{
	char **name_tab;
    int i;
	int j;
	name_tab = (char **)malloc(8 * ft_count_lines(p, size));
	i = 0;
    while(i < ft_count_lines(p, size))//checking purpose
    {
        name_tab[i]=(char *)malloc(ft_count_longest(p, size));
		j = 0;
        while(j < ft_count_longest(p, size))
        {
            name_tab[i][j]='\0';
			j++;
        }
		i++;
    }
	return(name_tab);
}
char	**ft_find_names(char *p ,char **name_tab)
{
	int		y;
	int		l;
	char 	*r;
	r = p;
	y = 0;
	while ( *r != '\0')
	{
		if (*r == ':' )
		{
			r++;
			l = 0;
			while ((*r == ' ') || (*r >= 9 && *r <= 13))
				r++;
			while(*r != '\n' && *r != '\0')
			{
				name_tab[y][l] = *r;
				r++;
				l++;
			}
			y++;
		}
		r++;
	}
	return (name_tab);
}