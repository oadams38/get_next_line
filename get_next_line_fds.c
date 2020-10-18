#include "get_next_line.h"

char     *set_offset(char *fd_offset, int fd, int offset)
{
    int     i;
    char    *c_fd;
    char    *c_offset;
    char    *fd_offset_2;
    char    **tab;

    if ((c_fd = ft_itoa(fd)) == NULL)
        return (NULL);
    tab = ft_strsplit(fd_offset, ' ');
    i = ft_strintab(tab, c_fd);
    if (i == -1)
    {
        fd_offset_2 = ft_strnew(ft_strlen(fd_offset) + 50);
        if (ft_strlen(fd_offset) > 0)
            fd_offset_2 = ft_strcat(fd_offset, " ");
        fd_offset_2 = ft_strcat(fd_offset_2, c_fd);
        fd_offset_2 = ft_strcat(fd_offset_2, " 0");
        free((void*)c_fd);
        return (fd_offset_2);
    }
    offset += ft_atoi(tab[i + 1]);
    c_offset = ft_itoa(offset);
    tab[i + 1] = c_offset;
    free((void*)c_offset);
    free((void*)c_fd);
    fd_offset = ft_tabjoin(tab, " ");
    ft_freetab(tab);
    return (fd_offset);
}

int     get_offset(char *fd_offset, int fd)
{
    char    *c_fd;
    char    **tab;
    int     i;
    int     offset;

    if ((c_fd = ft_itoa(fd)) == NULL)
        return (0);
    tab = ft_strsplit(fd_offset, ' ');
    i = ft_strintab(tab, c_fd);
    offset = ft_atoi(tab[i + 1]);
    ft_freetab(tab);
    return (offset);
}

int     get_next_line(const int fd, char **line)
{
    char        *buf;
    char        *Pline;
    int         ret;
    int         i;
    static char *fd_offset = "";
    int         offset;

    fd_offset = set_offset(fd_offset, fd, 0);
    fd_offset = set_offset(fd_offset, fd, 0);
    offset = get_offset(fd_offset, fd);
    buf = ft_strnew(BUFF_SIZE);
    Pline = *line;
    lseek(fd, offset, SEEK_SET);
    i = -1;
    if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
        return (ret);
    ft_strclr(*line);
    while (buf[++i] != '\n' && buf[i] != EOF)
    {
        if (i < BUFF_SIZE)
        {
            *Pline++ = buf[i];
            offset++;
        }
        else
        {
            ft_memset(buf, '\0', BUFF_SIZE);
            if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
                return (ret);
            i = -1;
        }
    }
    offset++;
    fd_offset = set_offset(fd_offset, fd, offset);
    return (buf[i] == '\n' ? 1 : 0);
}