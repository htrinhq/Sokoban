##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	source/main.c	\
		source/my_sokoban.c	\
		source/initiation.c	\
		source/player.c	\
		source/basic_functions.c	\
		source/box.c	\
		source/check.c	\
		source/fill_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	=	-W -Wall -Wextra -I include

LDFLAGS	=	-lcurses

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

PHONY: fclean clean all re
