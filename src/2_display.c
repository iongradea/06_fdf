/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_display.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 22:26:01 by igradea           #+#    #+#             */
/*   Updated: 2017/10/25 15:16:31 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		display(t_point *map, t_map *map_c)
{
	if ((map_c->mlx = mlx_init()) == NULL)
		return (ERROR);
	if ((map_c->win = mlx_new_window(map_c->mlx, 1920, 1080, "FdF")) == NULL)
		return (ERROR);
	map_c->zoom = ZOOM;
	proj_iso(map);
	draw(map, *map_c);
	mlx_key_hook(map_c->win, key_hook, (void*)map_c);
	mlx_loop(map_c->mlx);
	return (TRUE);
}
