/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:19:02 by cdeniau           #+#    #+#             */
/*   Updated: 2015/05/01 21:48:16 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

int		main(int ac, char **av)
{

	if (av[ac - 1])
		ft_putstr(av[ac - 1]);
	return (0);
}
