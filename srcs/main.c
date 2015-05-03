/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:19:02 by cdeniau           #+#    #+#             */
/*   Updated: 2015/05/03 17:23:12 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

int		main(int ac, char **av)
{
	GLFWwindow	*window;
	int			**grid;
	t_ball		*ball;

	/* Initialisations */

	(void)av;
	(void)ac;
	score = 0;
	life = 7;
	if (!glfwInit())
        return -1;
	shippos = 0.f;
    window = glfwCreateWindow(800, 800, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return (-1);
    }
	    /* Make the window's context current */
    glfwMakeContextCurrent(window);
		/* Set Callbacks */

	ft_putstr("Oyoooooo\n");
	if (!(grid = ft_grid("./levels/level0.lvl")))
	{
		ft_putendl("No map in : ./levels/level0.lvl");
		exit (0);
	}
	ft_putstr("Oyeeeeeeeeeee\n");

	glfwSetKeyCallback(window, key_handler);
		/* Sort of VSync */
	glfwSwapInterval(1);

	ball = (t_ball *)malloc(sizeof(t_ball));
	ball->x = 0.f;
	ball->y = -0.8f;
	ball->dir = 55.1f;
	ball->speed = 50;
	/* End of initiliaisialisitions */

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
		if (show(window, grid, ball))
			exit (1);//ici une fonction win pour quitter proprement

		ft_disp_score();

        /* Swap front and back buffers -> Show render */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

	glfwDestroyWindow(window);
    glfwTerminate();
	free(ball);
    return 0;
}
