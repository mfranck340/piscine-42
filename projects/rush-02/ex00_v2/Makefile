NAME = rush-02
CC = cc
FLAGS = -Wall -Werror -Wextra -fsanitize=address
SRCS 	= main.c \
		order_data.c \
		functions.c \
		functions_2.c \
		get_solution.c \
		ft_atoi.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
		$(CC) $(FLAGS) -o $(NAME) $(SRCS)

all:
clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:
		fclean all


