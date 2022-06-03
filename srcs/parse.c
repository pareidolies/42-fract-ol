/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:43:14 by smostefa          #+#    #+#             */
/*   Updated: 2022/06/03 17:43:15 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	parse_double(char *str)
{
	double	result;
	double	float_part;
	char	**tab;
	double	len;

	tab = ft_split(str, '.');
	result = (double)ft_atoi(tab[0]);
	if (!tab[1])
		return (result);
	else
	{
		float_part = ft_atoi(tab[1]);
		len = pow(10, ft_strlen(tab[1]));
		if (str[0] == '-')
			result -= float_part / len;
		else
			result += float_part / len;
		return (result);
	}
}
