/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:44:32 by igradea           #+#    #+#             */
/*   Updated: 2017/10/25 17:35:02 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		key_hook(int keycode, t_map *map)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	if ((map->zoom > 5 && keycode == ZOOM_MIN) || keycode == ZOOM_PLUS)
		map->zoom = keycode == ZOOM_MIN ? map->zoom - 5 : map->zoom + 10;
	if (keycode == LEFT || keycode == RIGHT)
		map->win_x = keycode == RIGHT ? map->win_x + 100 : map->win_x - 100;
	if (keycode == DOWN || keycode == UP)
		map->win_y = keycode == DOWN ? map->win_y + 100 : map->win_y - 100;
	if (keycode == U)
		map->adjust_z += 0.2;
	if (keycode == D)
		map->adjust_z -= 0.2;
	if (keycode == R)
		map->rev_z *= REV_Z;
	mlx_clear_window(map->mlx, map->win);
	proj_iso(map->map_pts, *map);
	draw(map->map_pts, *map);
	return (TRUE);
}
