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

LDFLAGS	=	-lcurses -L ./lib/my -lprintf

all:	libmake $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

libmake:
	make -C ./lib/my
	rm -f $(OBJ)

clean:
	make clean -C ./lib/my/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my/
	rm -f $(NAME)

re:	fclean all

PHONY: fclean clean all re libmake
