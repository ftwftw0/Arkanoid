/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 16:59:12 by cdeniau           #+#    #+#             */
/*   Updated: 2015/05/03 17:07:57 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

int		check_win(int **grid)
{
	int		x;
	int		y;
	int		win;

	x = -1;
	win = 1;
	while (++x < 20)
	{
		y = -1;
		while (++y < 8)
		{
			if (grid[y][x] < 0)
			{
				grid[y][x] = 0;
				score++;
			}
			if (grid[y][x] < 30 && grid[y][x] > 0)
				win = 0;
		}
	}
	return (win);
}

int		**ft_grid(char *path)
{
	int		fd;
	char	*line;
	int		**grid;
	int		xy[2];
	char	**str;

	xy[1] = 0;
	if ((fd = open(path, O_RDONLY)) <= 0)
		return (NULL);
	grid = (int **)malloc(sizeof(int *) * MAPH);
	xy[0] = -1;
	while (++(xy[0]) < MAPH)
		grid[xy[0]] = (int *)malloc(sizeof(int) * MAPW);
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		xy[0] = 0;
		while (xy[0] < 20)
		{
			grid[xy[1]][xy[0]] = ft_atoi(str[xy[0]]);
			xy[0]++;
		}
		xy[1]++;
	}
	return (grid);
}
