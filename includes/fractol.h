#ifndef FRACTOL_H

#define FRACTOL_H

#include "../printf/includes/ft_printf.h"
#include "../libft/libft.h"
#include <mlx.h>
#include <X11/keysym.h>
#include "stdlib.h"
#include <stdio.h>
#include <math.h>

# define WIDTH				400
# define HEIGHT				400
# define TITLE				"fractol"

# define ANSI_COLOR_BLUE		"\x1b[94m"
# define ANSI_COLOR_LIGHT_WHITE		"\x1b[97m"
# define ANSI_COLOR_LIGHT_RED		"\x1b[91m"
# define ANSI_COLOR_RESET		"\x1b[0m"

# define MANUAL1			"key functioning"

# define MANDELBROT			1
# define JULIA				2
# define OTHER				3

# define MAX_ITERATIONS		80
# define COLOR_SHIFT		0.01

# define MLX_ERROR			11

# define ESC_KEY			65307
# define LEFT_KEY			65361
# define RIGHT_KEY			65363
# define UP_KEY				65362
# define DOWN_KEY			65364
# define SPACE_KEY			99
# define ZOOM_IN_KEY		4
# define ZOOM_OUT_KEY		5

/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;*/

typedef struct	s_complex {
	double	re;
	double	im;
}		t_complex;

typedef struct	s_fractal {
	t_complex	nbr;
	int			iterations;
}		t_fractal;

typedef struct	s_data {
	void		*mlx_ptr;
	void		*window_ptr;
	int			type;
	t_complex	c;
	t_complex	*points;
	t_fractal	*fractal;
}		t_data;

//main.c
void	print_error(int error);
int	check_args(int argc, char **argv);
int	is_float(char *str);
void	print_manual(void);
void	ft_putstr_fd_color(char *str, int fd, char *color);

//start.c
int	start_fractol(char **argv);
void	initialize_info(t_data *data, char **argv);

//parse.c
double	parse_double(char *str);

//draw.c
void	draw_fractal(t_data *data);

//compute.c
void	compute_fractal(t_data *data);

//maths.c
unsigned int	distance(t_complex z);
t_complex	square(t_complex z);
t_complex	sum(t_complex z1, t_complex z2);

//transpose.c
void	transpose_to_image(void *image, t_data *data);

#endif
