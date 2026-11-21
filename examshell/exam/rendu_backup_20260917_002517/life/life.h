#ifndef LIFE_HPP
#define LIFE_HPP

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

typedef struct
{
	int	w;
	int	h;
	int	iter;
	char**	map;
} t_game;

#endif
