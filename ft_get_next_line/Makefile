CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c main.c

OBJ = $(SRC:.c=.o)

# Executable Files
NAME = my_program

# Library
LIB = libft.a

# Header file here to be checked if it has been updated or not
HEADER = get_next_line.h

all: $(NAME)

# Compiling Executable (.L for directory location and -lft is for library file)
$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L. -lft

# Compiling Library
$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

# Compiling object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB) $(NAME)

re: fclean all

.PHONY: all clean fclean re