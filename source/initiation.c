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

void change_line(pos_t *position, int *x, int *y, int i)
{
        if (position->buf[i] == '\n') {
                position->map[*y][*x] = '\0';
                *x = 0;
                *y = *y + 1;
                position->map[*y] = malloc(sizeof(char) * position->length);
        } else
                *x = *x + 1;
}

void fill_map(pos_t *position, char *av)
{
        int i = 0;
        int y = 0;
        int x = 0;
        int fd;

        fd = open(av, O_RDONLY);
        read(fd, position->buf, position->length + 1);
        position->map[y] = malloc(sizeof(char) * position->length);
        while (i != position->length) {
                position->map[y][x] = position->buf[i];
                change_line(position, &x, &y, i);
                i = i + 1;
        }
        position->map[y][x] = '\0';
        position->map[y + 1] = '\0';
        position->nbline = y;
}

void read_file(pos_t *position, char *av)
{
        int fd;

        fd = open(av, O_RDONLY);
	if (fd == -1)
		exit(84);
        position->length = get_length(fd);
        if (position->length == 0)
                exit(84);
        position->buf = malloc(sizeof(char) * position->length);
        position->map = malloc(sizeof(char*) * position->length);
        close(fd);
}
