CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c main.c
BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c main.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Executable Files
NAME = my_program

# Header file here to be checked if it has been updated or not
HEADER = get_next_line.h

all: $(NAME)

# Compiling Executable (.L for directory location and -lft is for library file)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

#Compiling Bonus
bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o my_bonus $(BONUS_OBJ)

# Compiling object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) my_bonus

re: fclean all

.PHONY: all clean fclean re