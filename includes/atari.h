/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atari.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 21:46:28 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/02 18:32:02 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARI_H
# define ATARI_H

# include <GLFW/glfw3.h>
# include "libft.h"
# include <fcntl.h>

# define WIDTH 800
# define SHIPSIZE 0.1
# define MAPH 8
# define MAPW 20

typedef struct		s_ball
{
	float			x;
	float			y;
	float			dir;
	int				type;
}					t_ball;

float shippos;

void				key_handler(GLFWwindow* window, int keycode,
								int scancode, int action, int mods);
int					show(GLFWwindow *window, int **grid, t_ball *ball);
int					**ft_grid(char *path);

#endif
