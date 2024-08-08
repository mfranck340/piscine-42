#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_void(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*get_memory(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += (size - 1) * ft_strlen(sep);
	str = (char *)malloc(sizeof(char) * (len + 1));
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		k;
	
	if (size == 0)
		return (get_void());
	str = get_memory(size, strs, sep);
	if (str == NULL)
		return (NULL);
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			str[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			str[k++] = sep[j++];
	}
	str[k] = '\0';
	return (str);
}

int main()
{
	char *strs[] = {"cositas", "y", "mas", "cositas"};
	char *sep = ", ";
	char *str = ft_strjoin(4, strs, sep);
	printf("%s\n", str);
	free(str);
	return 0;
}
