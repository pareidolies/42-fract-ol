#include "../includes/fractol.h"

//check

int	get_color(int speed, int shift)
{
	int	color;

	if (speed == -1)
		return (0xFF000000);
	speed += shift;
	color = 0;
	if (speed % 60 < 20)
	{
		color += (int)(255 - speed % 60 / 20.0 * 255) << 16;
		color += (int)(speed % 60 / 20.0 * 255) << 8;
	}
	else if (speed % 60 < 40)
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

void	fill_image(void *image, t_color *color, t_fractal_data *fractal_data)
{
	int			junk;
	int			*buffer;
	t_complex	screen;

	buffer = (int *)mlx_get_data_addr(image, &junk, &junk, &junk);
	screen.y = 0;
	while (screen.y < SIZE)
	{
		screen.x = 0;
		while (screen.x < SIZE)
		{
			buffer[(int)(screen.y * SIZE + screen.x)] = get_color(
					color[(int)(screen.y * SIZE + screen.x)].color,
					fractal_data->color_shift);
			screen.x++;
		}
		screen.y++;
	}
}
