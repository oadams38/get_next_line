#include "get_next_line.h"

int     do_read(char *buf, int fd)
{
    ft_strclr(buf);
    if (read(fd, buf, BUFF_SIZE) < 0)
    {
        free((void*)buf);
        return (-1);
    }
    return (1);
}

int     do_copy(char *buf, char *address, char *Pline, int fd)
{
    int     i;

    i = -1;
    while (buf[++i] != '\n' && buf[i] != EOFile)
    {
        if (buf[i] != '\0')
        {
            *Pline++ = buf[i];
            *address++;
        }
        else
        {
            if (do_read(buf, fd) == -1)
                return (-1);
            i = -1;
        }
    }
    return (i);
}

char    *init_buf(char *buf, char *address, int fd)
{
    if (address == 0)
    {
        buf = ft_strnew(BUFF_SIZE);
        if (do_read(buf, fd) == -1)
            return (NULL);
    }
    else
        buf = ft_strcpy(buf, address);
    return (buf);
}

int     get_next_line(const int fd, char **line)
{
    char        *buf;
    int         i;
    char        *Pline;
    static char *address = 0;

    if ((buf = init_buf(buf, address, fd)) == NULL)
        return (-1);
    address = buf;
    ft_strclr(*line);
    Pline = *line;
    if ((i = do_copy(buf, address, Pline, fd)) == -1)
        return (i);
    if (buf[i + 1] == '\0')
    {
        if (do_read(buf, fd) == -1)
            return (-1);
        i = -1;
    }
    address = &(buf[i + 1]);
    i = (buf[i] == '\n' || i == -1) ? 1 : 0;
    if (i == 0)
        free((void*)buf);
    return (i);
}