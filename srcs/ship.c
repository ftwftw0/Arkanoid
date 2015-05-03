/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 18:23:29 by cdeniau           #+#    #+#             */
/*   Updated: 2015/05/03 18:28:11 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

void		ship(int ship, float x, float y)
{
	if (ship == 1)
	{
		glBegin(GL_QUAD_STRIP);
		glColor3f(1.f, 0.f, 0.f);
		glVertex2d(x - 0.2f, y);
		glColor3f(1.f, 0.5f, 0.f);
		glVertex2d(x + 0.2f, y);
		glColor3f(0.f, 0.f, 0.f);
		glVertex2d(x - 0.05f, y + 0.05f);
		glColor3f(0.f, 0.f, 0.f);
		glVertex2d(x + 0.05f, y + 0.05f);
		glEnd();
	}
}

void		checkship(t_ball *ball)
{
	if (ball->x > shippos - 0.2 && ball->x < shippos + 0.2)
	{
		ball->dir = (180 * (ball->dir / 180 + 1)) - (2 * ((int)ball->dir % 90));
		if (ball->dir > 360)
			ball->dir -= 360;
		if (ball->dir < 0)
			ball->dir += 360;
		if (ball->dir < 330 && ball->dir < 210)
		{
			if (ball->x < shippos - 0.1)
				ball->dir += 50;
			if (ball->x > shippos + 0.1)
				ball->dir -= 50;
		}
	}
}
