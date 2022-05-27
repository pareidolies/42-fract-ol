#include "../includes/fractol.h"

//check

int	key_hook(int keycode, void **params)
{
	t_mlx_data	*mlx_data;
	t_fractal_data	*fractal_data;

	mlx_data = params[0];
	fractal_data = params[1];
	if (keycode == ECHAP_KEY)
	{
		ft_printf("Bye !\n");
		mlx_loop_end(mlx_data->mlx_ptr);
	}
	else if (keycode >= LEFT_KEY && keycode <= DOWN_KEY)
		move(keycode, fractal_data, mlx_data);
	else if (keycode == COLOR_SHIFT_KEY)
	{
		//data->color_shift++;
		draw_fractal(mlx_data, fractal_data);
	}
	return (0);
}

void	move(int keycode, t_fractal_data *data, t_mlx_data *mlx_data)
{
	double			shift;

	if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
	{
		shift = (fractal_data->max.x - fractal_data->min.x) * 0.1;
		shift *= (keycode == LEFT_KEY) * -1 + (keycode == RIGHT_KEY) * 1;
		fractal_data->min.x += shift;
		fractal_data->max.x += shift;
	}
	else if (keycode == DOWN_KEY || keycode == UP_KEY)
	{
		shift = (fractal_data->max.y - fractal_data->min.y) * 0.1;
		shift *= (keycode == UP_KEY) * -1 + (keycode == DOWN_KEY) * 1;
		fractal_data->min.y += shift;
		fractal_data->max.y += shift;
	}
	draw_fractal(mlx_data, fractal_data);
}

int	mouse_hook(int button, int xx, int yy, void **params)
{
	t_mlx_data	*mlx_data;
	t_fractal_data	*fractal_data;
	double			len;
	double			n_len;
	t_complex		mouse;

	mouse.x = xx;
	mouse.y = yy;
	mlx_data = params[0];
	fractal_data = params[1];
	if (button == ZOOM_IN_KEY || button == ZOOM_OUT_KEY)
	{
		len = fractal_data->max.x - fractal_data->min.x;
		if (button == ZOOM_IN_KEY)
			n_len = len / 1.2;
		else
			n_len = len * 1.2;
		fractal_data->min.x += mouse.x / WIDTH * (len - n_len);
		fractal_data->min.y += mouse.y / HEIGHT * (len - n_len);
		fractal_data->max.x -= (1 - mouse.x / WIDTH) * (len - n_len);
		fractal_data->max.y -= (1 - mouse.y / HEIGHT) * (len - n_len);
		draw_fractal(mlx_data, fractal_data);
	}
	return (0);
}
