SRC =	ft_printf.c \
		ft_put_chars.c \
		ft_put_numbers.c \
		ft_putnbr_base.c \
		ft_puthexa.c \

OBJS = $(SRC:.c=.o)

SORT_OBJS = $(SORT:.c=.o)

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

sort: $(OBJS) $(SORT_OBJS)
	ar -rcs $(NAME) $(OBJS) $(SORT_OBJS)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re sort

