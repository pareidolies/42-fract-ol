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

t_color	*compute_fractal()
{
	t_color	*result;
	t_color	tmp;
	int	i;
	t_complex	z0;

	result = malloc(sizeof(*result) * WIDTH * HEIGHT);
	if (!result)
		return (0);
	i = 0;
	z0.re = 0;
	z0.im = 0;
	while (i < WIDTH * LENGTH)
	{
		tmp.nbr = point[i];
		if (fractal_data->type == MANDELBROT)
			tmp.color = calculate_iterations(z0, point[i]);
		else if (fractal_data->type == JULIA)
			tmp.color = calculate_iterations(point[i], fractal_data->c);
		result[i] = tmp;
		i++;
	}
	return (result);
}
