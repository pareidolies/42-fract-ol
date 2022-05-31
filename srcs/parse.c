#include "../includes/fractol.h"

//check que zero bien écrit

double	parse_double(char *str)
{
	double	result;
	int	float_part;
	char	**str;
	int	len;

	str = ft_split(str, '.');
	result = (double)ft_atoi(str[0]);
	if (!str[1])
		return (result);
	else
	{
		float_part = ft_atoi(str[1]);
		len = pow(10, ft_strlen(str[1]));
		if (result >= 0)
			result += float_part / len;
		else
			result -= float_part / len;
		return (result);
	}
}
