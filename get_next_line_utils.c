#include "get_next_line.h"

char *ft_strnew(size_t size)
{
    char *str;

    size++;
    if ((str = malloc(size)) == NULL)
        return (NULL);
    while (size--)
        str[size] = '\0';
    return (str);
}

char *ft_strcpy(char *dest, const char *src)
{
    int i;

    i = -1;
    while (src[++i])
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

void ft_strclr(char *s)
{
    int i;

    i = -1;
    while (s[++i])
        s[i] = '\0';
}

size_t  ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}