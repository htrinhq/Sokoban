/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main sokoban
*/



int main(int ac, char **av)
{
        struct stat s;
        
        if (ac != 2)
                return (84);
        my_sokoban(av[1]);
        return (0);
}
