/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:19:02 by cdeniau           #+#    #+#             */
/*   Updated: 2015/05/03 18:18:35 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

int		main(void)
{
	GLFWwindow	*window;
	int			**grid;
	t_ball		*ball;

	score = 0;
	life = 7;
	if (!glfwInit())
		return (-1);
	shippos = 0.f;
	window = glfwCreateWindow(800, 800, "Arkanoid v0.1337 - flagoutt & cdeniau", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(window);
	if (!(grid = ft_grid("./levels/level0.lvl")))
	{
		ft_putendl("No map in : ./levels/level0.lvl");
		exit (0);
	}
	glfwSetKeyCallback(window, key_handler);
	glfwSwapInterval(1);
	ball = (t_ball *)malloc(sizeof(t_ball));
	ball->x = 0.f;
	ball->y = -0.8f;
	ball->dir = 55.1f;
	ball->speed = 50;
	while (!glfwWindowShouldClose(window))
	{
		if (show(window, grid, ball))
			exit (1);
		ft_disp_score();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	free(ball);
	return (0);
}
