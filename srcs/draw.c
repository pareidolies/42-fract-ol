#include "../includes/fractol.h"

void	initialize_info(t_fractal_data *fractal_data, char *argv)
{
	if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])))
		data->type = MANDELBROT;
	else if (!ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])))
		data->type = JULIA;
	else
		data-type = OTHER;
	//MIN MAX COLOR_SHIFT
}

t_complex	*create_frame(void)
{
	t_complex	point[WIDTH * HEIGHT];
	t_complex	tmp;
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		tmp.im = (4 * y / HEIGHT) - 2;
		while (x < WIDTH)
		{
			tmp.re = (4 * x / WIDTH) - 2;
			point[y * HEIGHT + x] = tmp;
			x++;
		}
		y++;
	}
	return (point);
}

void	draw_fractal(t_mlx_data *mlx_data, t_fractal_data *fractal_data)
{
	void		*image;
	t_complex	point[WIDTH * HEIGHT];
	t_color		*result;

	points = create_frame();
	result = compute_fractal();
	image = mlx_new_image(mlx_data->mlx_ptr, WIDTH, HEIGHT);
	transpose_to_image();
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->window_ptr, image, 0, 0);
	//clean
}
