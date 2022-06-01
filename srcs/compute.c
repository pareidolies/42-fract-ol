#include "../includes/fractol.h"

int	calculate_iterations(t_complex z0, t_complex c)
{
	t_complex	zn;
	int		n;

	n = 0;
	zn = z0;
	while (n < MAX_ITERATIONS)
	{
		zn = sum(square(zn), c);
		if (distance(zn) > 2)
			break;
		n++;
	}
	return (n);
}

void	compute_fractal(t_data *data)
{
	t_fractal	tmp;
	int			i;
	t_complex	z0;

	data->fractal = malloc(sizeof(t_fractal) * WIDTH * HEIGHT);
	//MALLOC_ERROR
	if (!data->fractal)
		return;
	i = 0;
	z0.re = 0;
	z0.im = 0;
	while (i < WIDTH * HEIGHT)
	{
		tmp.nbr = data->points[i];
		if (data->type == MANDELBROT)
			tmp.iterations = calculate_iterations(z0, data->points[i]);
		else if (data->type == JULIA)
			tmp.iterations = calculate_iterations(data->points[i], data->c);
		data->fractal[i] = tmp;
		i++;
	}
}