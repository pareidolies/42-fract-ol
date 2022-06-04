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
	double			shift;

	if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
	{
		shift = (data->max.x - data->min.x) * 0.1;
		shift *= (keycode == LEFT_KEY) * (-1) + (keycode == RIGHT_KEY) * 1;
		data->min.x += shift;
		data->max.x += shift;
	}
	else if (keycode == DOWN_KEY || keycode == UP_KEY)
	{
		shift = (data->max.y - data->min.y) * 0.1;
		shift *= (keycode == UP_KEY) * (-1) + (keycode == DOWN_KEY) * 1;
		data->min.y += shift;
		data->max.y += shift;
	}
	draw_fractal(data);
}

int	key_hook(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	if (keycode == ESC_KEY)
	{
		ft_putstr_fd_color("Good Bye !\n", 1, ANSI_COLOR_BLUE);
		mlx_loop_end(data->mlx_ptr);
	}
	else if (keycode >= LEFT_KEY && keycode <= DOWN_KEY)
		move(keycode, data);
	else if (keycode == SPACE_KEY)
	{
		data->color_shift += 10;
		draw_fractal(data);
	}
	return (0);
}

int	mouse_hook(int button, int xx, int yy, t_data *data)
{
	double				n_len;
	double				len;
	t_coordinates		mouse;

	mouse.x = xx;
	mouse.y = yy;
	if (button == ZOOM_IN_KEY || button == ZOOM_OUT_KEY)
	{
		len = data->max.x - data->min.x;
		if (button == ZOOM_IN_KEY)
			n_len = len / 1.2;
		else
			n_len = len * 1.2;
		data->min.x += mouse.x / WIDTH * (len - n_len);
		data->min.y += mouse.y / HEIGHT * (len - n_len);
		data->max.x -= (1 - mouse.x / WIDTH) * (len - n_len);
		data->max.y -= (1 - mouse.y / HEIGHT) * (len - n_len);
		draw_fractal(data);
	}
	return (0);
}
