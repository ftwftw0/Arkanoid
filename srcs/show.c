/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:17:25 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/03 13:38:57 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

static void block(int x, int y, int type)
{
	if (!type)
		return ;
    glBegin(GL_QUADS); //Begin quadrilateral coordinates
	if (type >= 30)
		GRIS;
	else if (type > 20)
		COL3;
	else if (type > 10)
		COL4;
	else
		COL5;
    glVertex2d(-1.f + 0.1f * x, 0.95 - 0.05f * y);
    glVertex2d(-0.9f + 0.1f * x, 0.95 - 0.05f * y);
    glVertex2d(-0.9f + 0.1f * x, 1 - 0.05f * y);
    glVertex2d(-1.f + 0.1f * x, 1 - 0.05f * y);
    glEnd(); //End quadrilateral coordinates
}

static void displaygrid(int **grid)
{
	int x;
	int y;

	y = -1;
	while (++y < MAPH)
	{
		x = -1;
		while (++x < MAPW)
		{
			block(x, y, grid[y][x]);
		}
	}
}

static void	ship(int ship, float x, float y)
{
	if (ship == 1)
	{
		glBegin(GL_QUAD_STRIP);
		glColor3f(1.f, 0.f, 0.f);
		glVertex2d(x - 0.1f, y);
		glColor3f(1.f, 0.5f, 0.f);
		glVertex2d(x + 0.1f, y);
		glColor3f(0.f, 0.f, 0.f);
		glVertex2d(x - 0.05f, y + 0.05f);
		glColor3f(0.f, 0.f, 0.f);
		glVertex2d(x + 0.05f, y + 0.05f);
		glEnd();
	}
}

#include <stdio.h>
static void	checkgrid(t_ball *ball, int **grid)
{
	printf("\nY = %f, X = %f\n", 7 - ((ball->y - 0.6) * 8 / 0.4), 20 + ((-1 + ball->x) * 20 / 2));
	if (grid[7 - (int)((ball->y - 0.6) * 8 / 0.4)][19 + (int)((1 + ball->x) * 20 / 2)])
		ball->dir -= 90.;
}

static int dispball(t_ball *ball, int **grid)
{
	glBegin(GL_QUADS);
	glColor3f(1.f, 1.f, 1.f);
	glVertex2d(ball->x - 0.02f, ball->y - 0.02f);
	glVertex2d(ball->x + 0.02f, ball->y - 0.02f);
	glVertex2d(ball->x + 0.02f, ball->y + 0.02f);
	glColor3f(1.f, 0.f, 0.f);
	glVertex2d(ball->x - 0.02f, ball->y + 0.02f);
	glEnd();

	ball->x += ft_sin(ball->dir * PI / 180) / ball->speed;
	ball->y += ft_cos(ball->dir * PI / 180) / ball->speed;

//	if (ball->y <= -1)
//		return (0);
	if (ball->x >= 1 || ball->y >= 1 ||
		ball->x < -1 || ball->y < -1)
		ball->dir -= 90.;
	
	if (ball->y > 0.6)
		checkgrid(ball, grid);
		
	if (ball->dir > 360)
		ball->dir -= 360;
	if (ball->dir < 0)
		ball->dir += 360;
	return (0);
}

int	show(GLFWwindow* window, int **grid, t_ball *ball)
{
	float ratio;
    int width;
	int height;

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
//	glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

	displaygrid(grid);
	ship(1, shippos, -0.9f);
	return (dispball(ball, grid));
}
