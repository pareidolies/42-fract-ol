/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:42:49 by smostefa          #+#    #+#             */
/*   Updated: 2022/06/03 17:42:51 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calculate_iterations(t_complex z0, t_complex c, t_data *data)
{
	t_complex	zn;
	int			n;

	n = 0;
	zn = z0;
	while (n < MAX_ITERATIONS)
	{
		if (data->type == 1 || data->type == 2)
			zn = sum(square(zn), c);
		else if (data->type == 4)
			zn = sum(square_abs(zn), c);
		if (distance(zn) > 2)
			break ;
		n++;
	}
	return (n);
}

void	compute_fractal(t_data *data)
{
	t_fractal	tmp;
	int			i;
	t_complex	z0;

	i = 0;
	z0.re = 0;
	z0.im = 0;
	while (i < WIDTH * HEIGHT)
	{
		tmp.nbr = data->points[i];
		if (data->type == MANDELBROT)
			tmp.iterations = calculate_iterations(z0, data->points[i], data);
		else if (data->type == BURNINGSHIP)
			tmp.iterations = calculate_iterations(z0, data->points[i], data);
		else if (data->type == JULIA)
			tmp.iterations = calculate_iterations(data->points[i], data->c, data);
		data->fractal[i] = tmp;
		i++;
	}
}

void	initialize_sierpinski(t_data *data)
{
	t_fractal	tmp;
	int			i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		tmp.nbr = data->points[i];
		tmp.iterations = 0;
		data->fractal[i] = tmp;
		i++;
	}
}

void	fill_rectangle(double x, double y, double a, double b, int n, t_data *data)
{
	int	i;
	int	j;
	int	index;

	j = (int)y;
	while (j <= b)
	{
		i = (int)x;
		while (i <= a)
		{
			index = i * WIDTH + j;
			data->fractal[(int)index].iterations = n;
			i++;
		}
		j++;
	}
}

void	fill_sierpinski(double x, double y, double a, double b, int n, t_data *data)
{
	if (n > 0)
	{
		fill_rectangle(x + a / 3, y + b / 3, x + 2 * a / 3, y + 2 * b / 3, n, data);
		fill_sierpinski(x, y, a / 3, b / 3, n - 1, data);
		fill_sierpinski(x + a / 3, y, a / 3, b / 3, n - 1, data);
		fill_sierpinski(x + 2 * a / 3, y, a / 3, b / 3, n - 1, data);
		fill_sierpinski(x, y + b / 3, a / 3, b / 3, n - 1, data);
		fill_sierpinski(x + 2 * a / 3, y + b / 3, a / 3, b / 3, n - 1, data);
		fill_sierpinski(x, y + 2 * b / 3, a / 3, b / 3, n - 1, data);
		fill_sierpinski(x + a / 3, y + 2 * b / 3, a / 3, b / 3, n - 1, data);
		fill_sierpinski(x + 2 * a / 3, y + 2 * b / 3, a / 3, b / 3, n - 1, data);
	}
}

void	compute_sierpinski(t_data *data)
{
	initialize_sierpinski(data);
	fill_sierpinski(0.0000, 0.0000, WIDTH, HEIGHT, 7, data);
}
