/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main sokoban
*/

#include <curses.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "soko.h"

int main(int ac, char **av)
{
        //int y = 0;
        pos_t *position = malloc(sizeof(pos_t));

        if (ac != 2)
                return (84);
        read_file(position, av[1]);
        fill_map(position, av[1]);
        /*while (y < position->nbline) {
                printf("%s\n", position->map[y]);
                y = y + 1;
        }*/
        my_sokoban(position);
        return (0);
}
