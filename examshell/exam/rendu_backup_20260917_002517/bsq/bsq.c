#include "bsq.h"


ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    int c;
    size_t i;

    if (!lineptr || !n || !stream)
        return -1;

    if (*lineptr == NULL || *n == 0)
    {
        *n = 128;
        *lineptr = malloc(*n);
        if (*lineptr == NULL)
            return -1;
    }

    i = 0;
    while ((c = fgetc(stream)) != EOF)
    {
        if (i + 1 >= *n)
        {
            char *tmp = realloc(*lineptr, *n * 2);
            if (tmp == NULL)
                return -1;

            *lineptr = tmp;
            *n *= 2;
        }

        (*lineptr)[i++] = c;

        if (c == '\n')
            break;
    }

    if (i == 0 && c == EOF)
        return -1;

    (*lineptr)[i] = '\0';

    return i;
}


void	free_map(char** map)
{
	int	i = 0;
	
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

int	parse_elements(FILE* file, t_elements *elements)
{
	int	n = 0;

	n = fscanf(file, "%d %c %c %c", &(elements->ln), &(elements->empty), &(elements->obstacle), &(elements->full));
	if (n != 4)
		return (1);
	if (elements->ln <= 0)
		return (1);
	if (elements->empty == elements->obstacle || elements->empty == elements->full || elements->obstacle == elements->full)
		return (1);
	if (!is_printable(elements->empty) || !is_printable(elements->obstacle) || !is_printable(elements->full))
		return (1);
	return (0);
}

int	free_data(t_map *map, char *line)
{
	free(line);
	free_map(map->map);
	return (1);
}

char	*ft_substr(char *str, int start, int len)
{
	int	i = start;
	int	j = 0;
	char*	res = (char *)malloc(len + 1);

	while (str[i] && j < len)
		res[j++] = str[i++];
	res[j] = '\0';
	return (res);
}

int	check_map(char	**map, t_elements* elements)
{
	int	i = 0;
	int	j = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != elements->empty && map[i][j] != elements->obstacle)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_map(FILE* file, t_map *map, t_elements *elements)
{
	char	*line = NULL;
	size_t	len = 0;

	map->h = elements->ln;
	map->map = (char **)malloc(sizeof(char *) * (map->h + 1));
	map->map[map->h] = NULL;

	if (my_getline(&line, &len, file) == -1)
	{
		free_map(map->map);
		return (1);
	}

	for (int i = 0; i < map->h; i++)
	{
		int read = my_getline(&line, &len, file);
		if (read == -1)
			return (free_data(map, line));
		if (line[read - 1] == '\n')
			read--;
		else
			return (free_data(map, line));
		map->map[i] = ft_substr(line, 0, read);
		if (!map->map[i])
			return (free_data(map, line));
		if (i == 0)
			map->w = read;
		else
		{
			if (map->w != read)
				return (free_data(map, line));
		}

	}
	if (check_map(map->map, elements))
		return (free_data(map, line));
	free(line);

	return (0);
}

int	min3(int n1, int n2, int n3)
{
	int	min = n1;

	if (n2 < min)
		min = n2;
	if (n3 < min)
		min = n3;
	return (min);
}

void	find_square(t_map* map, t_square* square, t_elements* elements)
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
				matrix[i][j] = min3(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;

			if (matrix[i][j] > square->size)
			{
				square->size = matrix[i][j];
				square->i = i - matrix[i][j] + 1;
				square->j = j - matrix[i][j] + 1;
			}
		}
	}

}

void print_square(t_map* map, t_square* square, t_elements* elements)
{

	for(int i = square->i; i < square->i + square->size; i++)
	{
		for(int j = square->j; j < square->j + square->size; j++)
		{
			if((i < map->h) && (j < map->w))
				map->map[i][j] = elements->full;
		}
	}

	for(int i = 0; i < map->h; i++)
	{
		fputs(map->map[i], stdout);
		fputc('\n', stdout);
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
	if (parse_map(file, &map, &elements))
		return (1);

	find_square(&map, &square, &elements);
	print_square(&map, &square, &elements);
	free_map(map.map);	
	return (0);
}

int	read_file(char* name)
{
	int	error_code = 0;
	FILE*	file = fopen(name, "r");
	
	if (!file)
		 return (1);
	error_code = execute_bsq(file);
	fclose(file);
	return (error_code);
}
