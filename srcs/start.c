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
		printf("%f\n", data->c.re);
		data->c.im = parse_double(argv[3]);
		printf("%f\n", data->c.im);
	}
	else if (!ft_strncmp(argv[1], "Sierpinski", ft_strlen(argv[1])))
		data->type = SIERPINSKI;
	else
		data->type = BURNINGSHIP;
	data->min.x = -2;
	data->max.x = 2;
	data->min.y = -2;
	data->max.y = 2;
	data->color_shift = 0;
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
		free(data.window_ptr);
		return (MLX_ERROR);
	}
	//Initialize
	initialize_info(&data, argv);
	//Draw fractal (loop hook)
	draw_fractal(&data);
	//Setup hooks
	mlx_key_hook(data.window_ptr, key_hook, &data);
	mlx_mouse_hook(data.window_ptr, mouse_hook, &data);
	mlx_hook(data.window_ptr, 17, 1L << 8, destroy, &data);
	//while(1)
	mlx_loop(data.mlx_ptr);
	//End
	//mlx_destroy_window(data.mlx_ptr, data.window_ptr);
	//mlx_destroy_display(data.mlx_ptr);
	//free(data.mlx_ptr);
	return (0);
}
