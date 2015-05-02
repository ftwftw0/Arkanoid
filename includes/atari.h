/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atari.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 21:46:28 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/02 17:21:23 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARI_H
# define ATARI_H

#include <GLFW/glfw3.h>
#include "libft.h"

#define WIDTH 800
#define SHIPSIZE 100

#define ESCAPE 0
#define LEFT 0
#define RIGHT 0

typedef struct      s_grid
{
    int             **table;
    int             columns;
    int             top;
    int             bot;
}                   t_grid;

typedef struct      s_ball
{
	flaot			x;
	float			y;
	float			dir;
    int             type;
}                   t_ball;

float shippos;

void				key_handler(GLFWwindow* window, int keycode, int scancode, int action, int mods);
int					show(GLFWwindow *window, t_grid *grid);
t_grid              *ft_mktable(char *path);
int                 *ft_createline(char *str);
int                 ft_countcolumns(char *str);
void                ft_puttab(t_grid *grid);

#endif
