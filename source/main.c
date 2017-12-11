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
        pos_t *pos = malloc(sizeof(pos_t));

        //pos->bo = 0;
        pos->nbp = 0;
        if (ac != 2)
                return (84);
        read_file(pos, av[1]);
        fill_map(pos, av[1]);
        my_sokoban(pos);
        return (0);
}
