#ifndef FRACTOL_H

#define FRACTOL_H

#include "../printf/includes/ft_printf.h"
#include <mlx.h>

# define ANSI_COLOR_BLUE		"\x1b[94m"
# define ANSI_COLOR_LIGHT_WHITE		"\x1b[97m"
# define ANSI_COLOR_LIGHT_RED		"\x1b[91m"
# define ANSI_COLOR_RESET		"\x1b[0m"

# define MANUAL1			""

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

typedef struct	s_mlx_data {
	void	*mlx_ptr;
	void	*window_ptr;
}		t_mlx_data;

typedef struct	s_fractal_data {
	
}		t_fractal_data	

#endif
