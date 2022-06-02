#include "../includes/fractol.h"

void	initialize_info(t_data *data, char **argv)
{
	if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])))
		data->type = MANDELBROT;
	else if (!ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])))
	{
		data->type = JULIA;
		data->c.re = parse_double(argv[2]);
		printf("%f\n", data->c.re);
		data->c.im = parse_double(argv[3]);
		printf("%f\n", data->c.im);
	}
	else
		data->type = SIERPINSKI;
	printf("%d\n", data->type);
	//MIN MAX COLOR_SHIFT
}

int	start_fractol(char **argv)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.window_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!data.window_ptr)
	{
		free(data.window_ptr);
		return (MLX_ERROR);
	}
	//Initialize
	initialize_info(&data, argv);
	//Draw fractal (loop hook)
	draw_fractal(&data);
	//Setup hooks
	//mlx_key_hook(data.window_ptr, FUNCTION, data);
	//mlx_mouse_hook(data.window_ptr, FUNCTION, data);
	//while(1)
	mlx_loop(data.mlx_ptr);
	//End
	//mlx_destroy_window(data.mlx_ptr, data.window_ptr);
	//mlx_destroy_display(data.mlx_ptr);
	//free(data.mlx_ptr);
	return (0);
}
