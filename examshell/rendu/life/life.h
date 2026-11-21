#ifndef LIFE_H
#define LIFE_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_game
{
	int	w;
	int	h;
	int	iter;
	char	**map;
} t_game;

#endif
