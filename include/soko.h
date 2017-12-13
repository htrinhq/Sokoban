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
	int bo;
	int nbp;
	int nbx;
	int startnbx;
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
void box_right(pos_t *pos);
void box_left(pos_t *pos);
void box_down(pos_t *pos);
void box_up(pos_t *pos);
void check_lose(pos_t *pos, int *x, int y);
void check_Ox(pos_t *pos, int *x, int y);
void check_O(pos_t *pos);
void check_win(pos_t *pos);
void into_the_while(pos_t *pos, int *x, int *y, int i);
void find_player(pos_t *pos, int *x, int *y, int i);
void error(pos_t *pos, int i);
int my_printf(const char *format, ...);
void helper(void);

#endif
