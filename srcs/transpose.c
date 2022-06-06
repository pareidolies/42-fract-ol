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

int	get_color_fractal(int iterations, int speed, t_data *data)
{
	if (iterations == MAX_ITERATIONS)
		return (data->palette[data->color_shift]);
	else
	{
		if (data->color_shift <= 2)
			return (get_redder(data->gradient[data->color_shift], speed));
		else if (data->color_shift == 3)
			return (get_lighter(data->gradient[data->color_shift], speed));
		else if (data->color_shift == 4 || data->color_shift == 6)
			return (get_greener(data->gradient[data->color_shift], speed));
		else if (data->color_shift == 5 || data->color_shift == 7)
			return (get_darker(data->gradient[data->color_shift], speed));
		else
			return (get_bluer(data->gradient[data->color_shift], speed));
	}
}

int	get_color(int iterations, t_data *data)
{
	return (get_color_fractal(iterations, iterations * data->psyche, data));
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
