##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

CC	=	gcc -Wall -Wextra

NAME	=	solver

SRC	=	main.c			\
		use_queue.c		\
		read_map.c		\
		select_random_node.c	\
		error_handling.c	\

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
