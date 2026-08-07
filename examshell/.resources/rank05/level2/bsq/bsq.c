#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bsq.h"

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void	print_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		fprintf(stdout, "%s\n", map[i]);
		i++;
	}
}

static int	min3(int a, int b, int c)
{
	if (a > b)
		a = b;
	if (a > c)
		a = c;
	return (a);
}


void	fill_square(char **map, t_square sq, char full)
{
	int	i;
	int	j;

	i = sq.row - sq.size + 1;
	while (i <= sq.row)
	{
		j = sq.col - sq.size + 1;
		while (j <= sq.col)
		{
			map[i][j] = full;
			j++;
		}
		i++;
	}
}

t_square	find_bsq(char **map, int rows, int cols,
					char empty, char obstacle)
{
	int			**dp;
	t_square	best;
	int			i;
	int			j;

	dp = malloc(sizeof(int *) * rows);
	i = 0;
	while (i < rows)
	{
		dp[i] = calloc(cols, sizeof(int));
		i++;
	}
	best.size = 0;
	best.row = 0;
	best.col = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else if (map[i][j] == empty)
    			dp[i][j] = min3(
						dp[i - 1][j],
						dp[i][j - 1],
						dp[i - 1][j - 1]) + 1;
			if (dp[i][j] > best.size)
			{
				best.size = dp[i][j];
				best.row = i;
				best.col = j;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < rows)
		free(dp[i++]);
	free(dp);
	return (best);
}

char	**read_map(FILE *file, int *rows, int *cols,
				char *empty, char *obstacle, char *full)
{
	char	*line;
	size_t	len;
	char	**map;
	int		i;
	int		j;

	line = NULL;
	len = 0;

	if (fscanf(file, "%d %c %c %c\n",
			rows, empty, obstacle, full) != 4)
		return (NULL);

	map = malloc(sizeof(char *) * (*rows));
	if (!map)
		return (NULL);

	i = 0;
	while (i < *rows)
	{
		line = NULL;
		len = 0;

		if (getline(&line, &len, file) == -1)
		{
			free(line);
			return (NULL);
		}

		*cols = 0;
		while (line[*cols] != '\n'
			&& line[*cols] != '\0')
			(*cols)++;

		map[i] = malloc((*cols) + 1);
		if (!map[i])
			return (NULL);

		j = 0;
		while (j < *cols)
		{
			map[i][j] = line[j];
			j++;
		}

		map[i][*cols] = '\0';

		free(line);
		i++;
	}

	return (map);
}

void free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	convert_file_pointer(char *filename)
{
	FILE	*file;

	file = fopen(filename, "r");

	if (!file)
		return (-1);

	if (execute_bsq(file) == -1)
	{
		fclose(file);
		return (-1);
	}

	fclose(file);

	return (0);
}

int	execute_bsq(FILE *file)
{
	char		**map;
	int			rows;
	int			cols;
	char		empty;
	char		obstacle;
	char		full;
	t_square	square;

	map = read_map(file,
		&rows,
		&cols,
		&empty,
		&obstacle,
		&full);

	if (!map)
	{
		fprintf(stderr, "map error\n");
		return (1);
	}

	square = find_bsq(map, rows, cols,
			empty, obstacle);

	fill_square(map, square, full);

	print_map(map, rows);

	free_map(map, rows);

	return (0);
}

int main() {}