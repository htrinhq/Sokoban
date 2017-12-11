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
                        mvprintw(LINES / 2, COLS / 2, "RESET");
                        break;
                case 113:
                        endwin();
                        exit(0);
        }
}

void my_sokoban(pos_t *pos)
{
        int key;
        WINDOW *win = initscr();

        keypad(win, true);
        while (1) {
                display_map(pos);
                key = getch();
                get_input(pos, key);
                refresh();
        }
}
