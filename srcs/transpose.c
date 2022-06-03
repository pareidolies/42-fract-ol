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

//check

/*int	get_color(int iterations, int shift)
{
	int	color;

	if (iterations == MAX_ITERATIONS)
		return (0xFF000000);
	iterations += shift;
	color = 0;
	if (iterations % 60 < 20)
	{
		color += (int)(255 - iterations % 60 / 20.0 * 255) << 16;
		color += (int)(iterations % 60 / 20.0 * 255) << 8;
	}
	else if (iterations % 60 < 40)
	{
		color += (int)(255 - (iterations - 20) % 60 / 20.0 * 255) << 8;
		color += (int)((iterations - 20) % 60 / 20.0 * 255);
	}
	else
	{
		color += (int)(255 - (iterations - 40) % 60 / 20.0 * 255);
		color += (int)((iterations - 40) % 60 / 20.0 * 255) << 16;
	}
	return (color);
}*/

/*JRALEMAN
fractol->image.data[pos] = fractol->color.red + (depth * 2.42);
		fractol->image.data[pos + 1] = fractol->color.green + (depth * 2.42);
		fractol->image.data[pos + 2] = fractol->color.blue + (depth * 2.42);*/

/*fractol->color.red = 0x42;
	fractol->color.green = 0x32;
	fractol->color.blue = 0x22;*/

/*fractol->image.data[pos] = fractol->color.red + (depth * 2.42);
		fractol->image.data[pos + 1] = fractol->color.green + (depth * 2.42);
		fractol->image.data[pos + 2] = fractol->color.blue + (depth * 2.42);*/

/*MAX = 42*/

int	lighten_or_darken(int color, int percent)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) + percent;
	g = ((color >> 8) & 0xFF) + percent;
	b = (color & 0xFF) + percent;
	return (r << 16 | g << 8 | b);
}

int	get_color(int iterations, t_data *data)
{
	t_color	color;
	int		result;

	if (iterations == MAX_ITERATIONS)
		return ((int)0x00A3D4CB);
	color.red = 0xD0 + (iterations * 2.42);
	color.green = 0xC5 + (iterations * 2.42);
	color.blue = 0xB0 + (iterations * 2.42);
	result = color.red << 16 | color.green << 8 | color.blue;
	return (lighten_or_darken(result, data->color_shift));
	/*color = (int)0x00800080;
	return (lighten_or_darken(color, iterations * 100));*/
	/*if (iterations == MAX_ITERATIONS)
		return ((int)0x00FF0000);
	else
		return ((int)0x00000000);
	if (iterations == MAX_ITERATIONS)
		return ((int)0x00000058);
	else if (iterations >= 45 && iterations < 50)
		return (lighten_or_darken(color, 10));
	else if (iterations >= 40 && iterations < 45)
		return (lighten_or_darken(color, 20));
	else if (iterations >= 35 && iterations < 40)
		return (lighten_or_darken(color, 30));
	else if (iterations >= 30 && iterations < 35)
		return (lighten_or_darken(color, 40));
	else if (iterations >= 25 && iterations < 30)
		return (lighten_or_darken(color, 50));
	else if (iterations >= 20 && iterations < 25)
		return (lighten_or_darken(color, 60));
	else if (iterations >= 15 && iterations < 20)
		return (lighten_or_darken(color, 70));
	else if (iterations >= 10 && iterations < 15)
		return (lighten_or_darken(color, 80));
	else if (iterations >= 5 && iterations < 10)
		return (lighten_or_darken(color, 100));
	else
		return ((int)0x00000000);*/
}

void	transpose_to_image(void *image, t_data *data)
{
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			*pixels;
	int			x;
	int			y;
	int			index;

	pixels = (int *)mlx_get_data_addr(image, &bits_per_pixel, &size_line, &endian);
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
