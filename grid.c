/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 16:59:12 by cdeniau           #+#    #+#             */
/*   Updated: 2015/05/02 17:55:11 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> //rajoute ca stp
#include "atari.h"

int		ft_grid(char *path)
{
	int		fd;
	char	*line;
	int		grid[8][20];
	int		xy[2];
	char	**str;

	xy[1] = 0;
	fd = open(path, O_RDONLY);
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
	ft_display(grid);
	return (0);
}
