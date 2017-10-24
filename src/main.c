/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:34:11 by igradea           #+#    #+#             */
/*   Updated: 2017/10/24 16:12:05 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ch_main_err(int fd, int ac, char **av, t_map *map)
{
	char	**tab;

	if (((fd = open(av[1], O_RDONLY)) == ERROR) || (ac != 2))
	{
		write(1, "Error\n", 6);
		close(fd);
		return (ERROR);
	}
	if (ch_map_err(fd, map, &tab) == ERROR_MAP)
	{
		write(1, "Map error\n", 10);
		close(fd);
		return (ERROR_MAP);
	}
	close(fd);
	free(tab);
	return (TRUE);
}

int		main(int ac, char **av)
{
	t_map	map;
	int		fd;

	fd = 0;
	if (ch_main_err(fd, ac, av, &map) != TRUE)
		return (ERROR);
	return (0);
}
