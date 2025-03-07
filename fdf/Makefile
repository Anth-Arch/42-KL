NAME = fdf
HEADER = fdf.h

LIB_DIRS = ./ft_libft ./minilibx-linux

LIBS = ./ft_libft/libft.a ./minilibx-linux/libmlx.a

SRCS = fdf.c

OBJS = $(SRCS:.c=.o)

AR =  ar rcs
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

%.o:%.c $(HEADER)
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(LIBS):
	for dir in $(LIB_DIRS); do \
		$(MAKE) -C $$dir; \
	done

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	for dir in $(LIB_DIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ft_libft fclean; \

re: fclean all

.PHONY: all clean fclean re