/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_display.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 22:26:01 by igradea           #+#    #+#             */
/*   Updated: 2017/10/25 03:30:02 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		display(t_point *map, t_map *map_c)
{
	map_c->mlx = mlx_init();
	map_c->win = mlx_new_window(map_c->mlx, 1920, 1080, "FdF");
	proj_iso(map, ZOOM);

//	mlx_key_hook(param->win, key_hook, *param);
//	mlx_loop(param->mlx);
	return (TRUE);
}
