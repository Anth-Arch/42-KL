NAME = fdf
HEADER = fdf.h

LIB_DIRS = ./ft_libft ./minilibx-linux

LIBS = ./ft_libft/libft.a ./minilibx-linux/libmlx.a

SRCS = main.c drawing_algorithms.c drawing_functions.c event_handling.c map_data_parsing.c memory.c transform_coordinate.c utility.c
OBJS = $(SRCS:.c=.o)

AR = ar rcs
CC = cc
FLAGS = -Wall -Wextra -Werror -Imlx_linux
FLAGS2 = -lXext -lX11 -lm
RM = rm -f

%.o:%.c $(HEADER)
	$(CC) $(FLAG) -c $< -o $@

all: $(LIBS) $(NAME)

$(LIBS):
	for dir in $(LIB_DIRS); do \
		$(MAKE) -C $$dir all; \
	done

$(NAME): $(OBJS)
	$(AR) libft.a $(OBJS)
	$(CC) $(FLAGS) $(FLAGS2) $(OBJS) $(LIBS) -L. -lft -o $(NAME)

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