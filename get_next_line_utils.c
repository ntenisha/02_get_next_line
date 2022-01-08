/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntenisha <ntenisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:36:36 by ntenisha          #+#    #+#             */
/*   Updated: 2022/01/08 15:36:36 by ntenisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(str1) + ft_strlen(str2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str1)
		while (str1[++i] != '\0')
			str[i] = str1[i];
	while (str2[j] != '\0')
		str[i++] = str2[j++];
	str[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	free(str1);
	return (str);
}

char	*ft_get_str_n(char *strnew)
{
	int		i;
	char	*str;

	i = 0;
	if (!strnew[i])
		return (NULL);
	while (strnew[i] && strnew[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (strnew[i] && strnew[i] != '\n')
	{
		str[i] = strnew[i];
		i++;
	}
	if (strnew[i] == '\n')
	{
		str[i] = strnew[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


char	*ft_new_ostatok_str(char *str_ost)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (str_ost[i] && str_ost[i] != '\n')
		i++;
	if (!str_ost[i])
	{
		free(str_ost);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(str_ost) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (str_ost[i])
		str[j++] = str_ost[i++];
	str[j] = '\0';
	free(str_ost);
	return (str);
}
