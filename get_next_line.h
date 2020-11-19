#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

# define BUFF_SIZE 1
# define EOFile '\0'

int     get_next_line(const int fd, char **line);
char    *ft_strnew(size_t size);
char    *ft_strcpy(char *dest, const char *src);
void    ft_strclr(char *s);
size_t  ft_strlen(char *str);


#endif