/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:43:58 by smostefa          #+#    #+#             */
/*   Updated: 2022/06/03 17:43:59 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*int	get_color_sierpinski(int iterations)
{
	if (iterations == 0)
		return (0x00FFFAF0);
	else if (iterations == 1)
		return (0x00FF8C00);
	else if (iterations == 2)
		return (0x00FF0000);
	else if (iterations == 3)
		return (0x00CC0099);
	else if (iterations == 4)
		return (0x003399FF);
	else if (iterations == 5)
		return (0x00663366);
	else if (iterations == 6)
		return (0x00FFCC99);
	else if (iterations == 7)
		return (0x0099CC99);
	else if (iterations == 8)
		return (0x00330099);
	else
		return (0x00000033);
}*/

int	get_color_fractal(int iterations, int speed, t_data *data)
{
	if (iterations == MAX_ITERATIONS)
		return (data->palette[data->color_shift]);
	else
	{
		if (data->color_shift <= 3)
			return (get_redder(data->gradient[data->color_shift], speed));
		else if (data->color_shift <= 6)
			return (get_greener(data->gradient[data->color_shift], speed));
		else
			return (get_bluer(data->gradient[data->color_shift], speed));
	}
}

int	get_color(int iterations, t_data *data)
{
	if (data->type == MANDELBROT)
		return (get_color_fractal(iterations, iterations * 10, data));
	else
		return (get_color_fractal(iterations, iterations * 2, data));
}

void	transpose_to_image(void *image, t_data *data)
{
	int			dust;
	int			*pixels;
	int			x;
	int			y;
	int			index;

	pixels = (int *)mlx_get_data_addr(image, &dust, &dust, &dust);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			index = (int)(y * HEIGHT + x);
			pixels[index] = get_color(data->fractal[index].iterations, data);
			x++;
		}
		y++;
	}
}
