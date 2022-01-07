
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	len = ft_strlen(src);
	str = (char *) malloc (sizeof (*str) * (len + 1));
	if (NULL == str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int ch)
{
	int				i;
	unsigned char	sym;

	i = 0;
	sym = ch;
	while (str[i])
	{
		if (str[i] == sym)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == sym)
		return ((char *)(str + i));
	return ((void *)0);
}