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
                *x = 0;
                *y = *y + 1;
                pos->map[*y] = malloc(sizeof(char) * pos->length);
        } else
                *x = *x + 1;
}

void find_player(pos_t *pos, int x, int y, int i)
{
        if (pos->buf[i] == 'P') {
                pos->px = x;
                pos->py = y;
        }
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
                pos->map[y][x] = pos->buf[i];
                find_player(pos, x, y, i);
                change_line(pos, &x, &y, i);
                i = i + 1;
        }
        pos->map[y][x] = '\0';
        pos->map[y + 1] = '\0';
        pos->nbline = y;
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
        close(fd);
}
