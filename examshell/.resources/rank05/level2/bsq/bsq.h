#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
	char	**map;
	int	w;
	int	h;
} t_map;

typedef struct s_elements
{
	int	nl;
	char	empty;
	char	obstacle;
	char	full;
} t_elements;

typedef struct s_square
{
	int	size;
	int	i;
	int	j;
} t_square;

int	execute_bsq(FILE* file);
int	open_file(char *name);

#endif
