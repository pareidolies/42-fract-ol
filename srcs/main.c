/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:43:07 by smostefa          #+#    #+#             */
/*   Updated: 2022/06/03 17:43:09 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_manual(void)
{
	ft_putstr_fd_color(M1, 2, ANSI_COLOR_BLUE);
	ft_putstr_fd_color(M2, 2, ANSI_COLOR_BLUE);
	ft_putstr_fd_color(M3, 2, ANSI_COLOR_BLUE);
	ft_putstr_fd_color(M4, 2, ANSI_COLOR_BLUE);
	ft_putstr_fd_color(M5, 2, ANSI_COLOR_BLUE);
	ft_putstr_fd_color(M6, 2, ANSI_COLOR_BLUE);
	ft_putstr_fd_color(M7, 2, ANSI_COLOR_BLUE);
	ft_putstr_fd_color(M8, 2, ANSI_COLOR_BLUE);
	ft_putstr_fd_color(M9, 2, ANSI_COLOR_BLUE);
	ft_putstr_fd_color(M10, 2, ANSI_COLOR_BLUE);
	ft_putstr_fd_color(M11, 2, ANSI_COLOR_BLUE);
}

int	is_float(char *str)
{
	int	i;
	int	dot;
	int	integer_part;

	i = 0;
	dot = 0;
	integer_part = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			integer_part = 1;
		else
		{
			if (str[i] != '-' && str[i] != '.')
				return (0);
			if (str[i] == '-' && i != 0)
				return (0);
			if (str[i] == '.' && (dot != 0 || integer_part == 0))
				return (0);
			if (str[i] == '.')
				dot = 1;
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	len;

	if (argc < 2)
		return (0);
	len = ft_strlen(argv[1]);
	if (!ft_strncmp(argv[1], "Mandelbrot", len) && argc == 2)
		return (1);
	if (!ft_strncmp(argv[1], "Julia", len) && argc == 4)
	{
		if (!is_float(argv[2]) || !is_float(argv[3]))
			return (0);
		return (1);
	}
	if (!ft_strncmp(argv[1], "Burning-Ship", len) && argc == 2)
		return (1);
	return (0);
}

void	print_error(int error)
{
	if (error == MLX_ERROR)
		ft_putstr_fd_color(MLX_MSSG, 2, ANSI_COLOR_LIGHT_RED);
}

int	main(int argc, char **argv)
{
	int	error;

	error = 0;
	if (!check_args(argc, argv))
	{
		print_manual();
		return (1);
	}
	error = start_fractol(argv);
	if (error)
		print_error(error);
	return (error);
}
