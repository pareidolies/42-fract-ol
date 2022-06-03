/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:43:25 by smostefa          #+#    #+#             */
/*   Updated: 2022/06/03 17:43:27 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_set(t_data *data)
{
	t_complex	tmp;
	double		x;
	double		y;

	data->points = malloc(sizeof(t_complex) * WIDTH * HEIGHT);
	//MALLOC_ERROR
	if (!data->points)
		return ;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		tmp.im = ((data->max.y - data->min.y) * y / HEIGHT) + data->min.y;
		while (x < WIDTH)
		{
			tmp.re = ((data->max.x - data->min.x) * x / WIDTH) + data->min.x;
			data->points[(int)(y * HEIGHT + x)] = tmp;
			x++;
		}
		y++;
	}
}

/*void	print_set(t_data *data)
{
	int	i;

	i = 1030;
	while (i < 1090)
	{
		printf("%f\n", data->points[i].re);
		printf("%f\n\n", data->points[i].im);
		i++;
	}
}

void	print_fractal(t_data *data)
{
	int	i;

	i = 80000;
	while (i < 80100)
	{
		printf("%f\n", data->fractal[i].nbr.re);
		printf("%f\n", data->fractal[i].nbr.im);
		printf("%d\n\n", data->fractal[i].iterations);
		i++;
	}
}*/

void	draw_fractal(t_data *data)
{
	void		*image;

	create_set(data);
	//print_set(data);
	if (data->type == MANDELBROT || data->type == JULIA)
	{
		compute_fractal(data);
	}
	else
		compute_sierpinski(data);
	//print_fractal(data);
	image = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	transpose_to_image(image, data);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, image, 0, 0);
	//clean_set_and_image (free set + mlx_destroy_image(mlx_ptr, image))
}
