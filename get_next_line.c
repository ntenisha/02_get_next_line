#include "get_next_line.h"

char *cft_check_rem(char *rem, char **line)
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

char *get_next_line(int fd)
{


}

int main (void)
{
    char    *line;
    int     fd;

    fd = open ("text.txt", O_RDONLY);
    while (get_next_line(fd, &line))
        printf("%s \n\n , line");
    

}