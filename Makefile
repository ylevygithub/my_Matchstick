##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

SRC		=	main.c \
			my_getnbr.c \
			game.c \
			lib.c \
			create_map.c \
			check_matches.c \
			error_handling.c \
			lib2.c

OBJ		=		$(SRC:.c=.o)

NAME	=		matchstick

all:	$(NAME)

$(NAME):		$(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
