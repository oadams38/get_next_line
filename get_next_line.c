#include "get_next_line.h"

int     do_read(char *buf, int fd)
{
    int     ret;

    if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
    {
        free((void*)buf);
        return (ret);
    }
    return (1);
}

int     do_copy(char *buf, char *Pline, int fd)
{
    int     i;
    int     ret;

    i = -1;
    while (ft_strlen(buf) != 0 && buf[++i] != '\n')
    {
        if (buf[i] != '\0')
            *Pline++ = buf[i];
        else
        {
            if ((ret = do_read(buf, fd)) <= 0)
                return (ret);
            i = -1;
        }
    }
    Pline[0] = '\0';
    return (i);
}

char    *init_buf(int fd, char *buf)
{
    if (do_read(buf, fd) == -1)
        return (NULL);
    return (buf);
}

int     get_next_line(const int fd, char **line)
{
    char        *buf;
    int         i;
    char        *Pline;
    static char static_buf[BUFF_SIZE] = "";

    buf = ft_strnew(BUFF_SIZE);
    if (static_buf[0] == '\0')
    {
        if ((buf = init_buf(fd, buf)) == NULL)
            return (-1);
    }
    else
        buf = ft_strcpy(buf, static_buf);
    ft_strclr(*line);
    Pline = *line;
    if ((i = do_copy(buf, Pline, fd)) <= 0)
        return (i);
    if (buf[i + 1] == '\0')
    {
        if (do_read(buf, fd) == -1)
            return (-1);
        i = -1;
    }
    ft_strcpy(static_buf, &(buf[i + 1]));
    i = (buf[i] == '\n' || i == -1) ? 1 : 0;
    free((void*)buf);
    return (i);
}