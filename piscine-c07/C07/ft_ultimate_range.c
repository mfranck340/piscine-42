#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
	int *r_aux;
	int i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	r_aux = (int *) malloc(sizeof(int) * (max - min));
	if (r_aux == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		r_aux[i] = min;
		min++;
		i++;
	}
	*range = r_aux;
	return (i);
}

int main()
{
	int *range;
	int i;
	int size;

	size = ft_ultimate_range(&range, 1, 10);
	i = 0;
	while (i < 9)
	{
		printf("%d\n", range[i]);
		i++;
	}
	free(range);
	return 0;
}
