/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:34:11 by igradea           #+#    #+#             */
/*   Updated: 2017/10/25 02:29:09 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ch_main_err(int fd, int ac, char **av, t_map *map)
{
	if (((fd = open(av[1], O_RDONLY)) == ERROR) || (ac != 2))
	{
		write(1, "Error\n", 6);
		close(fd);
		return (ERROR);
	}
	if (ch_map_err(fd, map) == ERROR_MAP)
	{
		write(1, "Map error\n", 10);
		close(fd);
		return (ERROR_MAP);
	}
	close(fd);
	return (TRUE);
}

int		main(int ac, char **av)
{
	t_map	map_c;
	int		fd;
	t_point	*map_pts;

	fd = 0;
	write(1, "1\n", 2);
	if (ch_main_err(fd, ac, av, &map_c) != TRUE)
		return (ERROR);
	write(1, "2\n", 2);
	if ((fd = open(av[1], O_RDONLY)) == ERROR)
	{
		close(fd);
		return (ERROR);
	}
	write(1, "3\n", 2);
	if (!(map_pts = (t_point*)ft_memalloc(sizeof(t_point) 
					* (map_c.nb_pts + 1))))
		return (ERROR);
/*	write(1, "line_len : ", 11);
	ft_putnbr(map_c.line_len);
	write(1, "\n", 1);
	write(1, "nb_pts : ", 9);
	ft_putnbr(map_c.nb_pts);
	write(1, "\n", 1);*/
	write(1, "4\n", 2);
	if (parser(map_pts, map_c, fd) != TRUE)
		return (ERROR);
	free(map_pts);
	write(1, "OK\n", 3);
	return (0);
}
