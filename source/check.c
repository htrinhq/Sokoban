/*
** EPITECH PROJECT, 2017
** check.c
** File description:
** check functions, win, lose conditions
*/

#include <curses.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "soko.h"

void check_lose(pos_t *pos, int *x, int y)
{
	if ((pos->map[y - 1][*x] == '#' && pos->map[y][*x + 1] == '#' &&\
	     pos->copy[y][*x] != 'O') ||\
	    (pos->map[y - 1][*x] == '#' && pos->map[y][*x - 1] == '#' &&\
	     pos->copy[y][*x] != 'O')) {
		pos->nbx = pos->nbx - 1;
	} else if ((pos->map[y + 1][*x] == '#' && pos->map[y][*x + 1] == '#' &&\
		    pos->copy[y][*x] != 'O') ||\
		   (pos->map[y + 1][*x] == '#' && pos->map[y][*x - 1] == '#' &&\
		    pos->copy[y][*x] != 'O')) {
		pos->nbx = pos->nbx - 1;
	}
	if (pos->nbx == 0) {
		endwin();
		free(pos);
		exit(1);
	}
}

void check_Ox(pos_t *pos, int *x, int y)
{
	while (pos->map[y][*x] != '\0') {
		if (pos->map[y][*x] == ' ' && pos->copy[y][*x] == 'O')
			pos->map[y][*x] = 'O';
		if (pos->map[y][*x] == 'O' ||\
		    (pos->map[y][*x] == 'P' && pos->copy[y][*x] == 'O'))
			pos->bo = 1;
		if (pos->map[y][*x] == 'X')
			check_lose(pos, x, y);
		*x = *x + 1;
	}
}

void check_O(pos_t *pos)
{
	int x = 0;
	int y = 0;

	while (pos->map[y]) {
		check_Ox(pos, &x, y);
		x = 0;
		y = y + 1;
	}
}

void check_win(pos_t *pos)
{
	if (!pos->bo) {
		endwin();
		free(pos);
		exit(0);
	}
}
