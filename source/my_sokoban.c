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

void reset(pos_t *pos)
{
        int y = 0;

        while (pos->map[y]) {
                pos->map[y] = my_strdup(pos->copy[y]);
                y = y + 1;
        }
        my_sokoban(pos);
}

void reset_quit(pos_t *pos, int key)
{
        switch (key) {
                case 32:
                        reset(pos);
                        break;
                case 113:
                        endwin();
                        free(pos);
                        exit(0);
        }
}

void get_input(pos_t *pos, int key)
{
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
                default:
                        reset_quit(pos, key);
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
                pos->bo = 0;
                refresh();
                display_map(pos);
                key = getch();
                get_input(pos, key);
                check_O(pos);
                check_win(pos);
        }
}
