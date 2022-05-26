#include "../includes/fractol.h"

void	ft_putstr_fd_color(char *str, int fd, char *color)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(ANSI_COLOR_RESET, fd);
}

void	print_manual(void)
{
	ft_pustr_fd_color("----- MANUAL -----\n", 2, ANSI_COLOR_BLUE);
	ft_pustr_fd_color("1. ./fractol Mandelbrot\n", 2, ANSI_COLOR_BLUE);
	ft_pustr_fd_color("2. ./fractol Julia Re(C) Im(C)\n", 2, ANSI_COLOR_BLUE);
	ft_pustr_fd_color("------------------", 2, ANSI_COLOR_BLUE);
}

int	is_float(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '-' && i != 0)
				return (0);
			if (str[i] == '.' && dot != 0)
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
	if (argc < 2)
		return (0);
	if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) && argc == 2)
		return (1);
	if (!ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) && argc == 4)
	{
		if (!is_float(argv[2]) || !is_float(argv[3]))
			return (0);
		return (1);
	}
	return (0);
}

void	print_error(int error)
{
	if (error == 1)
		ft_pustr_fd_color("Error.\n", 2, ANSI_COLOR_LIGHT_RED);
}

int	main(int argc, char **argv)
{
	int	error;

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
