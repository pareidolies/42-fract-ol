#include "../includes/fractol.h"

t_complex	sum(t_complex z1, t_complex z2)
{
	t_complex	result;
	
	result.re = z1.re + z2.re;
	result.im = z1.im + z2.im;
	return (result);
}

t_complex	square(t_complex z)
{
	t_complex	result;

	result.re = z.re * z.re - z.im * z.im;
	result.im = 2 * z.re * z.im;
	return (result);
}

unsigned int	distance(t_complex z)
{
	int	distance;

	distance = sqrt(pow(z.re, 2) + pow(z.im, 2));
	return (distance);
}
