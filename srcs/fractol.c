#include "../includes/fractol.h"

int	start_fractol(char **argv)
{
	t_mlx_data	mlx_data;
	t_fractal_data	fractal_data;

	mlx_data.mlx_ptr = mlx_init();
	if (!mlx_data.mlx_ptr)
		return (MLX_ERROR);
	mlx_data.window_ptr = mlx_new_window(WIDTH, HEIGHT, TITLE);
	if (!mlx_data.window_ptr)
	{
		free(mlx_data.window_ptr);
		return (MLX_ERROR);
	}
	//Draw fractal
	initialize_info(&fractal_data, argv);
	draw_fractal();
	//Setup hooks
	mlx_key_hook();
	mlx_mouse_hook();
	mlx_loop();
	//End
	mlx_destroy_display(mlx_data.mlx_ptr);
	return (0);
}
