/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 19:11:01 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/02 19:11:52 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

static double ft_incredible_cos(double angle)
{
	int step;
	double fact;
	double square_angle;
	double ret;

	square_angle = angle * angle;
	angle = 1;
	step = 0;
	fact = 1;
	ret = 1;
	while (step++ < 10)
	{
		angle = - angle * square_angle;
		fact = (fact + fact) * step * (step + step - 1);
		ret = ret + angle / fact;
	}
	return (ret);
}

double ft_cos(double angle)
{
	int sign;
	double pi;

	pi = 3.141592653589793;
	sign = 1;
	if (angle < 0)
		angle = - angle;
	if (angle == 0)
		return (1);
	else if (angle == pi / 2)
		return (0);
	else if (angle > pi / 2)
	{
		angle = pi - angle;
		sign = -1;
	}
	return (sign * ft_incredible_cos(angle));
}
