NAME = get_next_line

SRCS = main.c get_next_line.c get_next_line_utils.c

CFLAGS += -Wall -Werror -Wextra -D

$(NAME): 
	gcc $(CFLAGS) BUFFER_SIZE=32 $(SRCS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re