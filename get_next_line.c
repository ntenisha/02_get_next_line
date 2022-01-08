/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntenisha <ntenisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:35:23 by ntenisha          #+#    #+#             */
/*   Updated: 2022/01/08 15:35:23 by ntenisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_read(int fd, char *ostatok_str)
{
	char	*buff;
	int		read_byt;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_byt = 1;
	while (!ft_strchr(ostatok_str, '\n') && read_byt != 0)
	{
		read_byt = read(fd, buff, BUFFER_SIZE);
		if (read_byt == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_byt] = '\0';
		ostatok_str = ft_strjoin(ostatok_str, buff);
	}
	free(buff);
	return (ostatok_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*ostatok_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ostatok_str = ft_str_read(fd, ostatok_str);
	if (!ostatok_str)
		return (NULL);
	line = ft_get_str_n(ostatok_str);
	ostatok_str = ft_new_ostatok_str(ostatok_str);
	return (line);
}


/*
** int	main(void)
** {
** 	char	*line;
** 	int		i;
** 	int		fd1;
** 	fd1 = open("text.txt", O_RDONLY);
** 	i = 1;
** 	while (i < 7)
** 	{
** 		line = get_next_line(fd1);
** 		printf("line  %d %s", i, line);
** 		free(line);
** 		i++;
** 	}
** 	close(fd1);
** 	return (0);
** }
*/
