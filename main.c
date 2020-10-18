#include "get_next_line.h"

int     main()
{
    char *str;
    char **Pstr;
    int     fd;

    str = ft_strnew(50);
    Pstr = &str;
    fd = open("./test", O_APPEND);
    close(fd);
    fd = open("./test", O_APPEND);
    //fd = 1;
    ft_putnbr(get_next_line(fd, Pstr));
    ft_putchar('*');
    ft_putstr(str);
    ft_putchar('*');
    sleep(3);
    ft_putnbr(get_next_line(fd, Pstr));
    ft_putchar('*');
    ft_putstr(str);
    ft_putchar('*');
    sleep(3);
    ft_putnbr(get_next_line(fd, Pstr));
    ft_putchar('*');
    ft_putstr(str);
    ft_putchar('*');
    sleep(3);
    free((void*)str);
    return (0);
}