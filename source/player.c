/*
** EPITECH PROJECT, 2017
** player.c
** File description:
** player movement functions.
*/

#include <curses.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "soko.h"

void move_player_up(pos_t *pos)
{
	if (pos->map[pos->py - 1][pos->px] != '#') {
		if (pos->map[pos->py - 1][pos->px] != 'X') {
			pos->map[pos->py][pos->px] = ' ';
			pos->map[pos->py - 1][pos->px] = 'P';
			pos->py = pos->py - 1;
		} else
			box_up(pos);
	}
}

void move_player_down(pos_t *pos)
{
	if (pos->map[pos->py + 1][pos->px] != '#') {
		if (pos->map[pos->py + 1][pos->px] != 'X') {
			pos->map[pos->py][pos->px] = ' ';
			pos->map[pos->py + 1][pos->px] = 'P';
			pos->py = pos->py + 1;
		} else
			box_down(pos);
	}
}

void move_player_left(pos_t *pos)
{
	if (pos->map[pos->py][pos->px - 1] != '#') {
		if (pos->map[pos->py][pos->px - 1] != 'X') {
			pos->map[pos->py][pos->px] = ' ';
			pos->map[pos->py][pos->px - 1] = 'P';
			pos->px = pos->px - 1;
		} else
			box_left(pos);
	}
}

void move_player_right(pos_t *pos)
{
	if (pos->map[pos->py][pos->px + 1] != '#') {
		if (pos->map[pos->py][pos->px + 1] != 'X') {
			pos->map[pos->py][pos->px] = ' ';
			pos->map[pos->py][pos->px + 1] = 'P';
			pos->px = pos->px + 1;
		} else
			box_right(pos);
	}
}
