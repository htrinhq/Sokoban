/*
** EPITECH PROJECT, 2017
** box.c
** File description:
** box functions
*/

#include <curses.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "soko.h"

void box_up(pos_t *pos)
{
	if (pos->map[pos->py - 2][pos->px] == ' ' ||\
	pos->map[pos->py - 2][pos->px] == 'O') {
		pos->map[pos->py][pos->px] = ' ';
		pos->map[pos->py - 1][pos->px] = 'P';
		pos->map[pos->py - 2][pos->px] = 'X';
		pos->py = pos->py - 1;
	}
}

void box_down(pos_t *pos)
{
	if (pos->map[pos->py + 2][pos->px] == ' ' ||\
	pos->map[pos->py + 2][pos->px] == 'O') {
		pos->map[pos->py][pos->px] = ' ';
		pos->map[pos->py + 1][pos->px] = 'P';
		pos->map[pos->py + 2][pos->px] = 'X';
		pos->py = pos->py + 1;
	}
}

void box_left(pos_t *pos)
{
	if (pos->map[pos->py][pos->px - 2] == ' ' ||\
	pos->map[pos->py][pos->px - 2] == 'O') {
		pos->map[pos->py][pos->px] = ' ';
		pos->map[pos->py][pos->px - 1] = 'P';
		pos->map[pos->py][pos->px - 2] = 'X';
		pos->px = pos->px - 1;
	}
}

void box_right(pos_t *pos)
{
	if (pos->map[pos->py][pos->px + 2] == ' ' ||\
	pos->map[pos->py][pos->px + 2] == 'O') {
		pos->map[pos->py][pos->px] = ' ';
		pos->map[pos->py][pos->px + 1] = 'P';
		pos->map[pos->py][pos->px + 2] = 'X';
		pos->px = pos->px + 1;
	}
}
