#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
	int *range;
	int i;

	if (min >= max)
		return (NULL);
	range = (int *) malloc(sizeof(int) * (max - min));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}

int main()
{
	int *range = ft_range(1, 10);
	int i = 0;
	while (i < 9)
	{
		printf("%d\n", range[i]);
		i++;
	}
	free(range);
	return 0;
}
