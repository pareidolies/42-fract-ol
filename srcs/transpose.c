#include "../includes/fractol.h"

//check

/*int	get_color(int iterations, int shift)
{
	int	color;

	if (iterations == MAX_ITERATIONS)
		return (0xFF000000);
	iterations += shift;
	color = 0;
	if (iterations % 60 < 20)
	{
		color += (int)(255 - iterations % 60 / 20.0 * 255) << 16;
		color += (int)(iterations % 60 / 20.0 * 255) << 8;
	}
	else if (iterations % 60 < 40)
	{
		color += (int)(255 - (iterations - 20) % 60 / 20.0 * 255) << 8;
		color += (int)((iterations - 20) % 60 / 20.0 * 255);
	}
	else
	{
		color += (int)(255 - (iterations - 40) % 60 / 20.0 * 255);
		color += (int)((iterations - 40) % 60 / 20.0 * 255) << 16;
	}
	return (color);
}*/

int	get_color(int iterations, double shift)
{
	(void)shift;
	if (iterations == MAX_ITERATIONS)
		return ((int)0xFF000000);
	else
		return ((int)0x00000000);
}

void	transpose_to_image(void *image, t_data *data)
{
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			*pixels;
	int			x;
	int			y;
	int			index;

	pixels = (int *)mlx_get_data_addr(image, &bits_per_pixel, &size_line, &endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			index = (int)(y * HEIGHT + x);
			pixels[index] = get_color(data->fractal[index].iterations, COLOR_SHIFT);
			x++;
		}
		y++;
	}
}