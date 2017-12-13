/*
** EPITECH PROJECT, 2017
** initiation.c
** File description:
** initiation functions (before sokoban)
*/

#include <curses.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "soko.h"

int get_length(int fd)
{
        char *table = malloc(sizeof(char) * 66);
        int len = 0;
        int size = 0;

        len = read(fd, table, 67);
        while (len > 0) {
                size = size + len;
                len = read(fd, table, 67);
        }
        return (size);
}

void change_line(pos_t *pos, int *x, int *y, int i)
{
        if (pos->buf[i] == '\n') {
                pos->map[*y][*x] = '\0';
                pos->copy[*y] = my_strdup(pos->map[*y]);
                *x = 0;
                *y = *y + 1;
                pos->map[*y] = malloc(sizeof(char) * pos->length);
                pos->copy[*y] = malloc(sizeof(char) * pos->length);
        } else
                *x = *x + 1;
}

void find_player(pos_t *pos, int *x, int *y, int i)
{
        if (pos->buf[i] == 'P') {
                pos->xfirst = *x;
                pos->yfirst = *y;
        }
}

void error(pos_t *pos, int i)
{
        if (pos->buf[i] != ' ' && pos->buf[i] != 'P' &&\
        pos->buf[i] != 'X' && pos->buf[i] != 'O' &&\
        pos->buf[i] != '#' && pos->buf[i] != '\0' &&\
        pos->buf[i] != '\n')
                exit(84);
        if (pos->buf[i] == 'P')
                pos->nbp = pos->nbp + 1;
	else if (pos->buf[i] == 'X')
		pos->startnbx = pos->startnbx + 1;
}

void read_file(pos_t *pos, char *av)
{
        int fd;

        fd = open(av, O_RDONLY);
	if (fd == -1)
		exit(84);
        pos->length = get_length(fd);
        if (pos->length == 0)
                exit(84);
        pos->buf = malloc(sizeof(char) * pos->length);
        pos->map = malloc(sizeof(char*) * pos->length);
        pos->copy = malloc(sizeof(char*) * pos->length);
        close(fd);
}
