##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	source/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	=	-W -Wall -Wextra -I include -g

LDFLAGS	=	-lcurses

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

PHONY: fclean clean all re