#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*int	add_shade(double distance, int color)
{
}*/

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	get_opposite(int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_t(color);
	r = 255 - get_r(color);
	g = 255 - get_g(color);
	b = 255 - get_b(color);
	return (create_trgb(t, r, g, b));
}

int	ft_close(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	mouse_enter_window(int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	(void)vars;
	ft_printf("Hello !\n");
	return(0);
}

int	mouse_leave_window(int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	(void)vars;
	ft_printf("Bye !\n");
	return(0);
}

int main()
{
	t_vars	vars;
	t_data	img;
	int	i;
	int	j;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//carre
	i = 5;
	while (i < 20)
	{
		j = 5;
		while (j < 20)
		{
			if ((i % 2) == 0)
				my_mlx_pixel_put(&img, i, j, get_opposite(0x00FF0000));
			if ((i % 2) == 1)
				my_mlx_pixel_put(&img, i, j, 0x00FFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_hook(vars.win, 6, 1L<<4, mouse_enter_window, &vars);
	mlx_hook(vars.win, 6, 1L<<5, mouse_leave_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
