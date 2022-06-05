/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:22:17 by smostefa          #+#    #+#             */
/*   Updated: 2022/06/05 17:22:19 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../printf/includes/ft_printf.h"
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH				400
# define HEIGHT				400
# define TITLE				"fractol"

# define ANSI_COLOR_BLUE			"\x1b[94m"
# define ANSI_COLOR_LIGHT_WHITE		"\x1b[97m"
# define ANSI_COLOR_LIGHT_RED		"\x1b[91m"
# define ANSI_COLOR_RESET			"\x1b[0m"

# define M1			"\n--------------- MANUAL ---------------\n\n"
# define M2			"Case 1 : ./fractol Mandelbrot\n"
# define M3			"Case 2 : ./fractol Julia Re(C) Im(C)\n"
# define M4			"Case 3 : ./fractol Burning Ship\n\n"
# define M5			"--------------------------------------\n\n"

# define MANDELBROT			1
# define JULIA				2
# define BURNINGSHIP		3

# define MAX_ITERATIONS		200

# define MLX_ERROR			11

# define ESC_KEY			65307
# define LEFT_KEY			65361
# define RIGHT_KEY			65363
# define UP_KEY				65362
# define DOWN_KEY			65364
# define SPACE_KEY			32
# define ZOOM_IN_KEY		4
# define ZOOM_OUT_KEY		5

typedef struct s_complex {
	double	re;
	double	im;
}		t_complex;

typedef struct s_fractal {
	t_complex	nbr;
	int			iterations;
}		t_fractal;

typedef struct s_color {
	int	red;
	int	green;
	int	blue;
}		t_color;

typedef struct s_coordinates {
	double	x;
	double	y;
}		t_coordinates;

typedef struct s_data {
	void			*mlx_ptr;
	void			*window_ptr;
	int				type;
	t_coordinates	max;
	t_coordinates	min;
	int				color_shift;
	t_complex		c;
	t_complex		points[WIDTH * HEIGHT];
	t_fractal		fractal[WIDTH * HEIGHT];
	int				palette[10];
	int				gradient[10];
}		t_data;

//main.c
void			print_error(int error);
int				check_args(int argc, char **argv);
int				is_float(char *str);
void			print_manual(void);
void			ft_putstr_fd_color(char *str, int fd, char *color);

//start.c
int				start_fractol(char **argv);
void			initialize_info(t_data *data, char **argv);

//parse.c
double			parse_double(char *str);

//draw.c
void			draw_fractal(t_data *data);

//compute.c
void			compute_fractal(t_data *data);
void			compute_sierpinski(t_data *data);

//maths.c
unsigned int	distance(t_complex z);
t_complex		square(t_complex z);
t_complex		square_abs(t_complex z);
t_complex		sum(t_complex z1, t_complex z2);

//transpose.c
void			transpose_to_image(void *image, t_data *data);

//hook.c
int				key_hook(int keycode, t_data *data);
int				mouse_hook(int button, int xx, int yy, t_data *data);
int				destroy(t_data *data);

//color.c
int				get_redder(int original, int speed);
int				get_greener(int original, int speed);
int				get_bluer(int original, int speed);

//utils.c
void			ft_putstr_fd_color(char *str, int fd, char *color);

#endif
