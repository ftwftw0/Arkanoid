/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 17:13:30 by cdeniau           #+#    #+#             */
/*   Updated: 2015/05/03 18:19:50 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

void		ft_disp_life_num(void)
{
	size_t	z;
	char	*str2;
	char	*str;

	str = ft_itoa(life);
	str2 = ft_strdup(str);
	free(str);
	z = 0;
	glColor3d(0.5, 0.0, 0.0);
	glRasterPos2d(+0.9, -0.95);
	while (z <= ft_strlen(str2))
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[z]);
		z++;
	}
	free(str2);
}

void		retry(void)
{
	char	*str3;
	size_t	z;

	str3 = ft_strdup("PRESS SPACE TO RETRY");
	glColor3d(0.5, 0.0, 0.0);
	glRasterPos2d(0., -0.5);
	z = 0;
	while (z <= ft_strlen(str3))
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[z]);
		z++;
	}
	free(str3);
}

void		ft_disp_life(void)
{
	char	*str3;
	size_t	z;

	str3 = ft_strdup("LIFE ---- ");
	glColor3d(0.5, 0.0, 0.0);
	glRasterPos2d(+0.7, -0.95);
	z = 0;
	while (z <= ft_strlen(str3))
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[z]);
		z++;
	}
	free(str3);
}

void		ft_disp_score(void)
{
	char	*str;
	char	*str2;
	size_t	z;

	if (score > 0)
	{
		str2 = ft_itoa(score);
		str = ft_strdup(str2);
		free(str2);
		z = 0;
		glColor3d(0.5, 0.5, 0.5);
		glRasterPos2d(-0.2, 0.937);
		while (z <= ft_strlen(str))
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[z]);
			z++;
		}
		ft_disp_life_num();
		ft_disp_life();
		free(str);
	}
}
