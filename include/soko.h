/*
** EPITECH PROJECT, 2017
** soko.h
** File description:
** soko.h
*/

#ifndef SOKO_H
#define SOKO_H

struct pos {
        char **map;
        char **copy;
        char *buf;
        int px;
        int xfirst;
        int yfirst;
        int py;
        int nbline;
        int length;
};

typedef struct pos pos_t;

int get_length(int fd);
void fill_map(pos_t *pos, char *av);
void read_file(pos_t *pos, char *av);
void change_line(pos_t *pos, int *x, int *y, int i);
void my_sokoban(pos_t *pos);
void move_player_up(pos_t *pos);
void move_player_down(pos_t *pos);
void move_player_left(pos_t *pos);
void move_player_right(pos_t *pos);
int my_strlen(const char *str);
char *my_strdup(char *src);

#endif
