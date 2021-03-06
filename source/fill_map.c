/*
** EPITECH PROJECT, 2017
** fill_map.c
** File description:
** functions that fill the table
*/

#include <curses.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "soko.h"

void helper(void)
{
	write(1, "\nUSAGE\n", 7);
	write(1, "\t./my_sokoban map\n\n", 19);
	write(1, "\t./my_sokoban -h\n\n", 18);
	write(1, "DESCRIPTION\n", 12);
	write(1, "\t-h\tdisplay help\n\n", 18);
	write(1, "\tmap\tfile representing the wharehouse map,", 42);
	write(1, " containing '#' for walls, 'P' for the player,\n", 47);
	write(1, "\t\t'X' for boxes and 'O' for storage locations.\n\n", 48);
	write(1, "\tSPACE\treset level.\n\n", 21);
	write(1, "\tQ\tquit my_sokoban.\n\n", 21);
}

void into_the_while(pos_t *pos, int *x, int *y, int i)
{
	error(pos, i);
	pos->map[*y][*x] = pos->buf[i];
	find_player(pos, x, y, i);
	change_line(pos, x, y, i);
}

void fill_map(pos_t *pos, char *av)
{
	int i = 0;
	int y = 0;
	int x = 0;
	int fd;

	fd = open(av, O_RDONLY);
	read(fd, pos->buf, pos->length + 1);
	pos->map[y] = malloc(sizeof(char) * pos->length);
	while (i != pos->length) {
		into_the_while(pos, &x, &y, i);
		i = i + 1;
	}
	if (pos->nbp != 1)
		exit(84);
	pos->map[y][x] = '\0';
	pos->map[y + 1] = '\0';
	pos->nbline = y;
}
