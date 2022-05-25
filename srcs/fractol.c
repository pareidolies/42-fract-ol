#include "../includes/fractol.h"

int	start_fractol(char **argv)
{
	t_mlx_data	mlx_data;

	mlx_data.mlx_ptr = mlx_init();
	if (!mlx_data.mlx_ptr)
		return (MLX_ERROR);
	mlx_data.window_ptr = mlx_new_window(WIDTH, HEIGHT, TITLE);
	if (!mlx_data.window_ptr)
	{
		free(mlx_data.window_ptr);
		return (MLX_ERROR);
	}
	//Setup hooks
	mlx_loop_hook();
	mlx_hook();
	mlx_loop();
	//End
	mlx_destroy_display(mlx_data.mlx_ptr);
	return (0);
}
