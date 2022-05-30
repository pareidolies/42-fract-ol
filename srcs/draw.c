#include "../includes/fractol.h"

t_complex	*create_set(void)
{
	t_complex	*points;
	t_complex	tmp;
	int		x;
	int		y;

	points = malloc(sizeof(*points) * WIDTH * HEIGHT);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		tmp.im = (4 * y / HEIGHT) - 2;
		while (x < WIDTH)
		{
			tmp.re = (4 * x / WIDTH) - 2;
			points[y * HEIGHT + x] = tmp;
			x++;
		}
		y++;
	}
	return (points);
}

void	draw_fractal(t_data *data)
{
	void		*image;
	t_complex	points[WIDTH * HEIGHT];
	t_fractal	*fractal;

	data->points = create_set(void);
	fractal = compute_fractal(&data, &fractal);
	image = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	transpose_to_image(&image, fractal, &data);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, image, 0, 0);
	//clean
}
