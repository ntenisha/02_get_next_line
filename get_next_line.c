#include "get_next_line.h"

char *check_rem(char *rem, char **line)
{
    char    *p_n;

    p_n = NULL;
    if (rem)
        if ((p_n = ft_strchr(rem, '\n')))
        {
            *p_n = '\0';
            *line = ft_strdup (rem);
            ft_strcpy(rem, ++p_n);
        }
        else
        {
            *line = ft_strdup(rem);
            ft_strclr(rem);
        }
    else
		*line = ft_strnew(1);
	return(p_n);
}

char *get_next_line(int fd, char **line)
{
    static char     *rem;
    char            buff[BUFFER_SIZE + 1];
    int             bwr;
    char            *p_n;
    char            tmp;

    p_n = check_rem(rem, line);
    while (!p_n && (bwr = read  (fd, buf, BUFFER_SIZE)))
    {
        buf[bwr] = '\0';
        if ((p_n = strchr(buf, '\n')))
        {
            *p_n = '\0';
            p_n++;
            rem = ft_strdup(p_n);
        }
        tmp = *line;
        *line = ft_strjoin(*line, buf);
        free(tmp);
    }
    return (bwr || ft_strlen(rem) || ft_strlen(*line)) ? 1 : 0;
}

int main (void)
{
    char    *line;
    int     fd;

    fd = open ("text.txt", O_RDONLY);
    while (get_next_line(fd, &line))
        printf("%s \n\n , line");
}