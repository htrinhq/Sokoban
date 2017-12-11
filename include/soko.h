/*
** EPITECH PROJECT, 2017
** soko.h
** File description:
** soko.h
*/

#ifndef SOKO_H
#define SOKO_H

struct position {
        char **map;
        char *buf;
        int x;
        int y;
        int nbline;
        int length;
};

typedef struct position pos_t;

int get_length(int fd);
void fill_map(pos_t *position, char *av);
void read_file(pos_t *position, char *av);
void change_line(pos_t *position, int *x, int *y, int i);
void my_sokoban(pos_t *position);

#endif
