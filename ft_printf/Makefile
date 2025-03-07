NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

LIB = ar rcs

CC = cc

FLAGS = -Werror -Wall -Wextra

RM = rm -rf

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	$(LIB) $(NAME) $(OBJS)
	ranlib $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:fclean all

PHONY: all clean fclean re