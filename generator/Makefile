CC	=	gcc -Wall -Wextra

NAME	=	generator

SRC	=	main.c			\
		small_maze.c		\
		create_map.c		\
		use_queue.c		\
		select_random_node.c	\
		modifie_map.c		\

OBJ	=	$(addprefix ./src/, $(SRC:.c=.o))

CFLAGS	=	-I./include

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
