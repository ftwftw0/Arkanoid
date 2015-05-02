/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:17:25 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/02 17:19:48 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

static void block(int x, int y, int type)
{
	if (!type)
		return ;
    glBegin(GL_QUADS); //Begin quadrilateral coordinates
    glColor3f(0.8f, 0.2f, 0.1f);
    glVertex2d(-1.f + 0.1f * x, 0.95 - 0.05f * y);
    glVertex2d(-0.9f + 0.1f * x, 0.95 - 0.05f * y);
    glVertex2d(-0.9f + 0.1f * x, 1 - 0.05f * y);
    glVertex2d(-1.f + 0.1f * x, 1 - 0.05f * y);
    glEnd(); //End quadrilateral coordinates
}

static void displaygrid(t_grid *grid)
{
	int x;
	int y;

	y = -1;
	ft_putstr("Heyo\n");
	while (++y < grid->columns)
	{
		x = 0;
		while (++x <= 20)
		{
			ft_putstr("Heyo\n");
			block(x - 1, y, 1);
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
	}
}

int	show(GLFWwindow* window, t_grid *grid)
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


	glEnd();
	return (1);
}
