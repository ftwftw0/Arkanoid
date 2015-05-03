/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atari.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 21:46:28 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/03 17:21:45 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARI_H
# define ATARI_H

# include <GLFW/glfw3.h>
# include "libft.h"
# include <fcntl.h>
# include <GLUT/glut.h>


# define COL1		glColor3f(1.0f,0.0f,0.0f)
# define GRIS		glColor3f(0.3f,0.3f,0.3f)
# define COL3		glColor3f(0.0f,0.0f,1.0f)
# define COL4		glColor3f(0.0f,1.0f,0.0f)
# define COL5		glColor3f(1.0f,0.0f,1.0f)
# define PI			3.14159
# define WIDTH		800
# define SHIPSIZE	0.1
# define MAPH		8
# define MAPW		20

typedef struct		s_ball
{
	float			x;
	float			y;
	float			dir;
	int				speed;
	int				type;
}					t_ball;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

float				shippos;
int					score;
int					life;

void				ft_disp_score(void);
void				key_handler(GLFWwindow* window, int keycode,
								int scancode, int action, int mods);
int					show(GLFWwindow *window, int **grid, t_ball *ball);
int					**ft_grid(char *path);
double				ft_cos(double angle);
double				ft_sin(double angle);
int					check_win(int **grid);

#endif
