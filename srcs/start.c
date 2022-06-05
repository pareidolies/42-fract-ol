/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:43:50 by smostefa          #+#    #+#             */
/*   Updated: 2022/06/03 17:43:51 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	initialize_info(t_data *data, char **argv)
{
	if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])))
		data->type = MANDELBROT;
	else if (!ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])))
	{
		data->type = JULIA;
		data->c.re = parse_double(argv[2]);
		data->c.im = parse_double(argv[3]);
	}
	else
		data->type = BURNINGSHIP;
	data->min.x = -2;
	data->max.x = 2;
	data->min.y = -2;
	data->max.y = 2;
	data->color_shift = 0;
}

void	initialize_colors(t_data *data)
{
	data->palette[0] = 0x00AFF9966;
	data->gradient[0] = 0x00330066;
	data->palette[1] = 0x007B0828;
	data->gradient[1] = 0x00522B47;
	data->palette[2] = 0x003C474B;
	data->gradient[2] = 0x00162521;
	data->palette[3] = 0x003AAED8;
	data->gradient[3] = 0x002BD9FE;
	data->palette[4] = 0x0056203D;
	data->gradient[4] = 0x009D79BC;
	data->palette[5] = 0x00011627;
	data->gradient[5] = 0x00FDFFFC;
	data->palette[6] = 0x0035012C;
	data->gradient[6] = 0x003A015C;
	data->palette[7] = 0x00ADB6C4;
	data->gradient[7] = 0x00294C60;
	data->palette[8] = 0x00C03221;
	data->gradient[8] = 0x00E2C290;
	data->palette[9] = 0x00FCA17D;
	data->gradient[9] = 0x00DA627D;
}

int	start_fractol(char **argv)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.window_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!data.window_ptr)
	{
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}
	initialize_info(&data, argv);
	initialize_colors(&data);
	draw_fractal(&data);
	mlx_key_hook(data.window_ptr, key_hook, &data);
	mlx_mouse_hook(data.window_ptr, mouse_hook, &data);
	mlx_hook(data.window_ptr, 17, 1L << 8, destroy, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.window_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
