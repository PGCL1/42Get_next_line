NAME= get_next_line.a
HEADER= get_next_line.h

CC=gcc
CFLAGS= -Wall -Werror -Wextra -D BUFFER_SIZE=42
RM= rm -f

SRC= get_next_line.c\
	get_next_line_utils.c\

OBJS= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
