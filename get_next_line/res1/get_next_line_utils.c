#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	while (*str && *str != c)
		str++;
	if (*str && *str == c)
		return (str);
	else
		return (NULL);
}

char	*ft_calloc(int n, int size)
{
	char	*res;

	res = malloc(n * size);
	ft_bzero(res, n * size);
	return (res);
}

void	ft_bzero(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
		str[i++] = 0;
}

char	*ft_strjoin(char *str1, char *str2)
{
	int	i;
	int	j;
	int	totalsize;
	char	*res;

	i = 0;
	totalsize = ft_strlen(str1) + ft_strlen(str2);
	res = malloc((totalsize + 1) * sizeof(char));
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		res[i++] = str2[j++];
	res[totalsize] = 0;
	return (res);
}
