/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:43:31 by smostefa          #+#    #+#             */
/*   Updated: 2022/06/03 17:43:32 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move(int keycode, t_data *data)
{
	double			len;

	if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
	{
		len = data->max.x - data->min.x;
		if (keycode == LEFT_KEY)
			len = (-1) * len;
		data->min.x += len * GAMMA;
		data->max.x += len * GAMMA;
	}
	else if (keycode == DOWN_KEY || keycode == UP_KEY)
	{
		len = data->max.y - data->min.y;
		if (keycode == UP_KEY)
			len = (-1) * len;
		data->min.y += len * GAMMA;
		data->max.y += len * GAMMA;
	}
	draw_fractal(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		ft_putstr_fd_color(GOODBYE, 1, ANSI_COLOR_BLUE);
		mlx_loop_end(data->mlx_ptr);
	}
	else if (keycode >= LEFT_KEY && keycode <= DOWN_KEY)
		move(keycode, data);
	else if (keycode == SPACE_KEY)
	{
		if (data->color_shift == 9)
			data->color_shift = 0;
		else
			data->color_shift++;
		draw_fractal(data);
	}
	else if (keycode == TAB_KEY)
	{
		if (data->psyche == 18)
			data->psyche = 2;
		else
			data->psyche += 8;
		draw_fractal(data);
	}
	return (0);
}

int	destroy(t_data *data)
{
	ft_putstr_fd_color(GOODBYE, 1, ANSI_COLOR_BLUE);
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	mouse_hook(int button, int xx, int yy, t_data *data)
{
	double				len;
	t_coordinates		mouse;

	mouse.x = xx;
	mouse.y = yy;
	if (button == ZOOM_IN_KEY || button == ZOOM_OUT_KEY)
	{
		len = data->max.x - data->min.x;
		if (button == ZOOM_OUT_KEY)
			len = (-1) * len;
		data->min.x += (mouse.x / WIDTH) * (len * ZOOM);
		data->max.x -= (1 - mouse.x / WIDTH) * (len * ZOOM);
		if (data->type == JULIA)
		{
			data->max.y += (1 - mouse.y / HEIGHT) * (len * ZOOM);
			data->min.y -= (mouse.y / HEIGHT) * (len * ZOOM);
		}
		else
		{
			data->min.y += (mouse.y / HEIGHT) * (len * ZOOM);
			data->max.y -= (1 - mouse.y / HEIGHT) * (len * ZOOM);
		}
		draw_fractal(data);
	}
	return (0);
}
