/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 11:34:25 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/03 18:22:48 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

void key_handler(GLFWwindow *window, int keycode, int scancode, int action, int mods)
{
	(void)scancode;
	(void)action;
	(void)mods;
	(void)window;
	if (keycode == GLFW_KEY_ESCAPE)
		exit(0);
	else if (keycode == GLFW_KEY_LEFT)
		shippos -= 0.05f;
	else if (keycode == GLFW_KEY_RIGHT)
		shippos += 0.05f;
}
