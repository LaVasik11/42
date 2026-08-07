#include "fractol.h"

void	clean_exit(t_fractol *f)
{
	if (!f)
		exit(0);
	if (f->palette)
		free(f->palette);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(0);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	end_fractol(t_fractol *mlx)
{
	clean_exit(mlx);
	return (0);
}
