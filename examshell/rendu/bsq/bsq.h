#ifndef BSQ_H
#define BSQ_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

typedef struct s_square
{
	int	row;
	int	col;
	int	size;
}	t_square;

int		execute_bsq(FILE *file);
int		convert_file_pointer(char *filename);

#endif