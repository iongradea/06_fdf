/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:34:11 by igradea           #+#    #+#             */
/*   Updated: 2017/10/25 18:17:43 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	init_map_c(t_map *map)
{
	map->mlx = NULL;
	map->win = NULL;
	map->line_len = FALSE;
	map->nb_pts = FALSE;
	map->zoom = ZOOM;
	map->adjust_z = ADJUST_Z;
	map->rev_z = REV_Z * REV_Z;
	map->win_x = WIN_X / 2;
	map->win_y = WIN_Y / 2;
	map->map_pts = NULL;
}

static int	ch_main_err(int fd, int ac, char **av, t_map *map)
{
	int	ret;

	if (((fd = open(av[1], O_RDONLY)) == ERROR) || (ac != 2))
	{
		write(1, "Error\n", 6);
		close(fd);
		return (ERROR);
	}
	ret = ch_map_err(fd, map); 
	if (ret == ERROR_MAP)
	{
		write(1, "Map error\n", 10);
		close(fd);
		return (ERROR_MAP);
	}
	else if (ret == ERROR)
	{
		write(1, "Error\n", 6);
		close(fd);
		return (ERROR);
	}
	close(fd);
	return (TRUE);
}

static int	close_fd_exit_error(int fd, int err)
{
	if (err == ERROR)
	{
		close(fd);
		return (ERROR);
	}
	return (TRUE);
}

int			main(int ac, char **av)
{
	t_map	map_c;
	int		fd;
	t_point	*map_pts;

	fd = 0;
	init_map_c(&map_c);
	if (ch_main_err(fd, ac, av, &map_c) != TRUE)
		return (ERROR);
	if ((fd = open(av[1], O_RDONLY)) == ERROR)
		close_fd_exit_error(fd, ERROR);
	if (!(map_pts = (t_point*)ft_memalloc(sizeof(t_point)
					* (map_c.nb_pts + 1))))
		close_fd_exit_error(fd, ERROR);
	map_c.map_pts = map_pts;
	if (parser(map_pts, map_c, fd) != TRUE)
		close_fd_exit_error(fd, ERROR);
	if (display(map_pts, &map_c) == ERROR)
		close_fd_exit_error(fd, ERROR);
	free(map_pts);
	return (0);
}
