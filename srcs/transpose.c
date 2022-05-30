#include "../includes/fractol.h"

//check

int	get_color(int iterations, int shift)
{
	int	color;

	if (iterations == MAX_ITERATIONS)
		return (0xFF000000);
	iterations += shift;
	color = 0;
	if (iterations % 60 < 20)
	{
		color += (int)(255 - speed % 60 / 20.0 * 255) << 16;
		color += (int)(speed % 60 / 20.0 * 255) << 8;
	}
	else if (iterations % 60 < 40)
	{
		color += (int)(255 - (speed - 20) % 60 / 20.0 * 255) << 8;
		color += (int)((speed - 20) % 60 / 20.0 * 255);
	}
	else
	{
		color += (int)(255 - (speed - 40) % 60 / 20.0 * 255);
		color += (int)((speed - 40) % 60 / 20.0 * 255) << 16;
	}
	return (color);
}

void	transpose_to_image(void *image, t_fractal *fractal, t_data *data)
{
	int			junk;
	int			*buffer;
	t_complex	screen;

	buffer = (int *)mlx_get_data_addr(image, &junk, &junk, &junk);
	screen.y = 0;
	while (screen.y < HEIGHT)
	{
		screen.x = 0;
		while (screen.x < WIDTH)
		{
			buffer[(int)(screen.y * HEIGHT + screen.x)] = get_color(
					fractal[(int)(screen.y * SIZE + screen.x)].iterations,
					COLOR_SHIFT);
			screen.x++;
		}
		screen.y++;
	}
}