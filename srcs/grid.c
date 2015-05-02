/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 16:59:12 by cdeniau           #+#    #+#             */
/*   Updated: 2015/05/02 18:30:39 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

int		**ft_grid(char *path)
{
	int		fd;
	char	*line;
	int		**grid;//[8][20];
	int		xy[2];
	char	**str;

	xy[1] = 0;
	fd = open(path, O_RDONLY);
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
