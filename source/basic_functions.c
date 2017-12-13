/*
** EPITECH PROJECT, 2017
** basic_functions.c
** File description:
** basic functions
*/

#include <curses.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "soko.h"

int my_strlen(const char *str)
{
	int x = 0;

	while (str[x])
		x = x + 1;
	return (x);
}

char *my_strdup(char *src)
{
	int x = 0;
	char *copy = malloc(sizeof(char) * my_strlen(src));

	while (src[x] != '\0') {
		copy[x] = src[x];
		x = x + 1;
	}
	copy[x] = '\0';
	return (copy);
}
