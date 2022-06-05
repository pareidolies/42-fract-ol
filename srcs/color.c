/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:14:01 by smostefa          #+#    #+#             */
/*   Updated: 2022/06/05 17:14:06 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_redder(int original, int speed)
{
	t_color	color;
	int		result;

	color.red = ((original >> 16) & 0xFF) + speed;
	color.green = ((original >> 8) & 0xFF);
	color.blue = (original & 0xFF);
	result = color.red << 16 | color.green << 8 | color.blue;
	return (result);
}

int	get_greener(int original, int speed)
{
	t_color	color;
	int		result;

	color.red = ((original >> 16) & 0xFF);
	color.green = ((original >> 8) & 0xFF) + speed;
	color.blue = (original & 0xFF);
	result = color.red << 16 | color.green << 8 | color.blue;
	return (result);
}

int	get_bluer(int original, int speed)
{
	t_color	color;
	int		result;

	color.red = ((original >> 16) & 0xFF);
	color.green = ((original >> 8) & 0xFF);
	color.blue = (original & 0xFF) + speed;
	result = color.red << 16 | color.green << 8 | color.blue;
	return (result);
}
