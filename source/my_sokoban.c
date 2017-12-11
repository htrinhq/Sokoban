/*
** EPITECH PROJECT, 2017
** my_sokoban.c
** File description:
** my_sokoban
*/

#include <curses.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "soko.h"

void display_map(pos_t *pos)
{
        int y = 0;

        while (pos->map[y]) {
                mvprintw(y, 0, pos->map[y]);
                y = y + 1;
        }
}

void get_input(pos_t *pos, int key)
{
        int y = 0;

        switch (key) {
                case KEY_UP:
                        move_player_up(pos);
                        break;
                case KEY_DOWN:
                        move_player_down(pos);
                        break;
                case KEY_LEFT:
                        move_player_left(pos);
                        break;
                case KEY_RIGHT:
                        move_player_right(pos);
                        break;
                case 32:
                        while (pos->map[y]) {
                                pos->map[y] = my_strdup(pos->copy[y]);
                                y = y + 1;
                        }
                        my_sokoban(pos);
                        break;
                case 113:
                        endwin();
                        exit(0);
        }
}

void check_Ox(pos_t *pos, int *x, int y)
{
        while (pos->map[y][*x] != '\0') {
                if (pos->map[y][*x] == ' ' && pos->copy[y][*x] == 'O')
                        pos->map[y][*x] = 'O';
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

void my_sokoban(pos_t *pos)
{
        int key;
        WINDOW *win = initscr();

        pos->px = pos->xfirst;
        pos->py = pos->yfirst;
        keypad(win, true);
        while (1) {
                refresh();
                display_map(pos);
                key = getch();
                get_input(pos, key);
                check_O(pos);
        }
}
