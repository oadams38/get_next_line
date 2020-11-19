#include "get_next_line.h"

void        ft_putnbr(int n);

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
    printf("%s\n", str);
    sleep(3);
    ft_putnbr(get_next_line(fd, Pstr));
    printf("%s\n", str);
    sleep(3);
    ft_putnbr(get_next_line(fd, Pstr));
    printf("%s\n", str);
    sleep(3);
    free((void*)str);
    return (0);
}


static void  print_n(int n)
{
    char c;

    if (n > 0)
    {
        c = (unsigned char)(n % 10 + '0');
        print_n(n / 10);
        write(1, &c, 1);
    }
}

void        ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    else if (n == 0)
    {
        write(1, "0", 1);
        return;
    }
    if (n < 0)
    {
        n *= -1;
        write(1, "-", 1);
    }
    print_n(n);
}