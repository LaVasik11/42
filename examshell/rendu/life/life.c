#include "life.h"

void	free_map(t_game* game)
{
	for (int i = 0; i < game->h; i++)
		free(game->map[i]);
	free(game->map);
}

void	print_map(t_game game)
{
	for (int i = 0; i < game.h; i++)
	{
		for (int j = 0; j < game.w; j++)
			fputc(game.map[i][j], stdout);
		fputc('\n', stdout);
	}
}

void	init_game(t_game* game, char **argv)
{
	game->w = atoi(argv[1]);
	game->h = atoi(argv[2]);
	game->iter = atoi(argv[3]);
	game->map = malloc(sizeof(char *) * game->h);

	for (int i = 0; i < game->h; i++)
	{
		game->map[i] = malloc(sizeof(char) * game->w);
		for (int j = 0; j < game->w; j++)
			game->map[i][j] = ' ';
	}
}

void	fill_map(t_game* game)
{
	char	buffer;
	int	i = 0;
	int	j = 0;
	bool	draw = false;

	while (read(STDIN_FILENO, &buffer, 1) == 1)
	{
		switch (buffer)
		{
			case('w'): if (i > 0) {i--;}; break;
			case('a'): if (j > 0) {j--;}; break;
			case('s'): if (i < game->h - 1) {i++;}; break;
			case('d'): if (j < game->w - 1) {j++;}; break;
			case('x'): draw = !draw; break;
			default: continue;
		}
		if (draw)
			game->map[i][j] = '0';
	}
}

int	count_neighbor(t_game game, int i, int j)
{
	int count = 0;

	for (int ii = -1; ii < 2; ii++)
	{
		for (int jj = -1; jj < 2; jj++)
		{
			if (ii == 0 && jj == 0)
				continue;
			int x = i + ii;
			int y = j + jj;
			if (x >= 0 && x < game.h && y >= 0 && y < game.w && game.map[x][y] == '0')
				count++;
		}
	}
	
	return (count);
}

void	play_game(t_game* game)
{
	char	**new_map = malloc(sizeof(char *) * game->h);
	for (int i = 0; i < game->h; i++)
		new_map[i] = malloc(sizeof(char) * game->w);
	
	for (int i = 0; i < game->h; i++)
	{
		for (int j = 0; j < game->w; j++)
		{
			int cn = count_neighbor(*game, i, j);
			if (game->map[i][j] == '0')
			{
				if (cn == 2 || cn == 3)
					new_map[i][j] = '0';
				else
					new_map[i][j] = ' ';
			}
			else
			{	
				if (cn == 3)
					new_map[i][j] = '0';
				else
					new_map[i][j] = ' ';
			}
		}
	}
	free_map(game);
	game->map = new_map;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	t_game game;

	init_game(&game, argv);
	fill_map(&game);
	for (int i = 0; i < game.iter; i++)
		play_game(&game);
	print_map(game);
	free_map(&game);
	return (0);
}
