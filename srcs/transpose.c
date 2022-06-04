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

	if (data->type == 3)
	{
		if (iterations == 0)
			return (0x00FFFAF0);
		else if (iterations == 1) // orange
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
	}
	if (iterations == MAX_ITERATIONS)
		return ((int)0x00A3D4CB);
	color.red = 0xD0 + (iterations * 2.42);
	color.green = 0xC5 + (iterations * 2.42);
	color.blue = 0xB0 + (iterations * 2.42);
	result = color.red << 16 | color.green << 8 | color.blue;
	return (lighten_or_darken(result, data->color_shift));
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
