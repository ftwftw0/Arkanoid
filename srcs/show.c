/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:17:25 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/03 16:37:55 by flagoutt         ###   ########.fr       */
/*   Updated: 2015/05/03 11:51:14 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

static void block(int x, int y, int type)
{
	if (type <= 0)
		return ;
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	if (type >= 30)
		COL1;
	else if (type > 20)
		COL3;
	else
		COL4;
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
			block(x, y, grid[y][x]);
	}
}

static void	ship(int ship, float x, float y)
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

static void checkship(t_ball *ball)
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


#include <stdio.h>
static t_point *checkgrid(t_ball *ball, int **grid)
{
	t_point *pt;

	pt = (t_point *)malloc(sizeof(t_point));
	pt->y = 8 - ((ball->y - 0.6) * 8 / 0.4);
	pt->x = 20 + ((-1 + ball->x) * 20 / 2);
	if (grid[pt->y][pt->x] != 0)
	{
		ball->dir = (180 * (ball->dir / 180 + 1)) - (2 * ((int)ball->dir % 90));
		grid[pt->y][pt->x] -= 10;
		printf("\nBLOCK HIT : PT->Y = %i, PT->X = %i -> VALUE : %i\n", pt->y, pt->x, grid[pt->y][pt->x]);
		return (pt);
	}
	return (NULL);
}

static int dispball(t_ball *ball, int **grid)
{
	t_point *pt;

	glBegin(GL_QUADS);
	glColor3f(1.f, 1.f, 1.f);
	glVertex2d(ball->x - 0.02f, ball->y - 0.02f);
	glVertex2d(ball->x + 0.02f, ball->y - 0.02f);
	glVertex2d(ball->x + 0.02f, ball->y + 0.02f);
	glColor3f(1.f, 0.f, 0.f);
	glVertex2d(ball->x - 0.02f, ball->y + 0.02f);
	glEnd();
	pt = NULL;
	if (ball->x >= 1 || ball->y >= 1 ||	ball->x < -1 || ball->y < -1)
		ball->dir = (180 * (ball->dir / 180 + 1)) - (2 * ((int)ball->dir % 90));
	if (ball->y > 0.6)
		pt = checkgrid(ball, grid);
	if (ball->y < -0.8 && ball->y > -0.85)
		checkship(ball);
	ball->x += ft_cos(ball->dir * PI / 180) / ball->speed;
	ball->y += ft_sin(ball->dir * PI / 180) / ball->speed;
	if (ball->x >= 1 || ball->y >= 1 ||	ball->x < -1 || ball->y < -1)
	{
		ball->dir = (180 * (ball->dir / 180 + 1)) - (2 * ((int)ball->dir % 90));
		ball->x += ft_cos(ball->dir * PI / 180) / ball->speed;
		ball->y += ft_sin(ball->dir * PI / 180) / ball->speed;
	}
	else if (ball->y > 0.6 && checkgrid(ball, grid))
	{
		ball->x += ft_cos(ball->dir * PI / 180) / ball->speed;
		ball->y += ft_sin(ball->dir * PI / 180) / ball->speed;
	}
	if (check_win(grid))
		return (1);
	if (ball->dir > 360)
		ball->dir -= 360;
	if (ball->dir < 0)
		ball->dir += 360;
	free(pt);
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
	//HYPNOOOOOOOOOOOOOOOOO
	//
	//
	//
	//
	//
	//
	//
	//LOL
	displaygrid(grid);
	ship(1, shippos, -0.9f);
	return (dispball(ball, grid));
}
