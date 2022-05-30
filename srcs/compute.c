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

t_color	*compute_fractal(t_data *data, t_fractal *fractal, t_complex **points)
{
	t_fractal	tmp;
	int			i;
	t_complex	z0;

	fractal = malloc(sizeof(*fractal) * WIDTH * HEIGHT);
	if (!fractal)
		return (0);
	i = 0;
	z0.re = 0;
	z0.im = 0;
	while (i < WIDTH * LENGTH)
	{
		tmp.nbr = data->points[i];
		if (data->type == MANDELBROT)
			tmp.iterations = calculate_iterations(z0, points[i]);
		else if (data->type == JULIA)
			tmp.iterations = calculate_iterations(points[i], data->c);
		fractal[i] = tmp;
		i++;
	}
	return (fractal);
}