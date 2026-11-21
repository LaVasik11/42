#include "bsq.h"


#include <stdio.h>
#include <stdlib.h>

ssize_t ft_getline(char **lineptr, size_t *n, FILE *stream)
{
    int c;
    size_t len = 0;

    if (!lineptr || !n || !stream)
        return -1;

    if (*lineptr == NULL || *n == 0)
    {
        *n = 16;
        *lineptr = malloc(*n);
        if (!*lineptr)
            return -1;
    }

    while ((c = fgetc(stream)) != EOF)
    {
        if (len + 1 >= *n)
        {
            *n *= 2;
            char *tmp = realloc(*lineptr, *n);
            if (!tmp)
                return -1;
            *lineptr = tmp;
        }

        (*lineptr)[len++] = c;

        if (c == '\n')
            break;
    }

    if (len == 0 && c == EOF)
        return -1;

    (*lineptr)[len] = '\0';

    return len;
}

void	free_map(char **map)
{
	int i = 0;

	if (map)
	{
		while (map[i])
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		free(map);
	}
}

int	is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

int	parse_elements(FILE* file, t_elements* elements)
{
	if (fscanf(file, "%d %c %c %c", &(elements->nl), &(elements->empty), &(elements->obstacle), &(elements->full)) != 4)
		return (1);
	if (elements->nl <= 0)
		return (1);
	if (elements->empty == elements->obstacle || elements->empty == elements->full || elements->obstacle == elements->full)
		return (1);
	if (!is_printable(elements->empty) || !is_printable(elements->obstacle) || !is_printable(elements->full))
		return (1);
	return (0);
}

int	free_data(char* line, t_map* map)
{
	free(line);
	free_map(map->map);
	return (1);
}

char	*ft_substr(char *src, int start, int len)
{
	int	i = start;
	int	j = 0;
	char	*res = (char *)malloc(len + 1);

	while (j < len)
		res[j++] = src[i++];
	res[j] = '\0';
	return (res);
}

int	check_map(t_map* map, t_elements* elements)
{
	for (int i = 0; i < map->h; i++)
	{
		for (int j = 0; j < map->w; j++)
		{
			if (map->map[i][j] != elements->empty && map->map[i][j] != elements->obstacle)
				return (1);
		}
	}
	return (0);
}

int	parse_map(FILE* file, t_elements* elements, t_map* map)
{
	size_t	len = 0;
	char	*line = NULL;

	map->h = elements->nl;
	map->map = (char **)malloc((map->h + 1) * sizeof(char *));
	map->map[map->h] = NULL;
	
	if (ft_getline(&line, &len, file) == -1)
	{
		free_map(map->map);
		return (1);
	}

	for (int i = 0; i < map->h; i++)
	{
		int read = ft_getline(&line, &len, file);
		if (read == -1)
			return (free_data(line, map));
		map->map[i] = ft_substr(line, 0, read);
		if (line[read - 1] == '\n')
			read--;
		if (!map->map[i])
			return (free_data(line, map));
		if (i == 0)
			map->w = read;
		else
		{
			if (map->w != read)
				return (free_data(line, map));
		}
	}
	if (check_map(map, elements))
		return (free_data(line, map));
	free(line);
	return (0);
}

int	min3(int n1, int n2, int n3)
{
	int min = n1;

	if (n2 < min)
		min = n2;
	if (n3 < min)
		min = n3;
	return (min);
}
void	find_square(t_map* map, t_elements* elements, t_square* square)
{
	int	matrix[map->h][map->w];

	for (int i = 0; i < map->h; i++)
	{
		for (int j = 0; j < map->w; j++)
		{
			if (map->map[i][j] == elements->obstacle)
				matrix[i][j] = 0;
			else if (i == 0 || j == 0)
				matrix[i][j] = 1;
			else
				matrix[i][j] = min3(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]) + 1;
			if (matrix[i][j] > square->size)
			{
				square->size = matrix[i][j];
				square->i = i - matrix[i][j] + 1;
				square->j = j - matrix[i][j] + 1;
			}
		}
	}
}

void	print_square(t_map* map, t_elements* elements, t_square* square)
{
	for (int i = square->i; i < square->i + square->size; i++)
	{
		for (int j = square->j; j < square->j + square->size; j++)
		{
			if (i < map->h && j < map->w)
				map->map[i][j] = elements->full;
		}
	}
	for (int i = 0; i < map->h; i++)
	{
		fputs(map->map[i], stdout);
	}
}

int	execute_bsq(FILE* file)
{
	t_elements	elements;
	t_map		map;
	t_square	square;

	square.size = 0;
	square.i = 0;
	square.j = 0;

	if (parse_elements(file, &elements))
		return (1);
	if (parse_map(file, &elements, &map))
		return (1);
	find_square(&map, &elements, &square);
	print_square(&map, &elements, &square);
	free_map(map.map);
	return (0);
}

int	open_file(char *name)
{
	FILE* file = fopen(name, "r");
	if (!file)
		return (1);
	if (execute_bsq(file))
		return (1);
	fclose(file);
	return (0);
}
