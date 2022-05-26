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


