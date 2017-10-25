/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_proj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iongradea <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 03:07:43 by iongradea         #+#    #+#             */
/*   Updated: 2017/10/25 16:54:03 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		proj_iso(t_point *map, t_map map_c)
{
	int		i;

	i = 0;
	while ((map[i]).in_tab == TRUE)
	{
		map[i].x_proj = 0.7 * map[i].x - 0.7 * map[i].y;
		map[i].y_proj = REV_Z * (0.82 * (map[i].z) * map_c.adjust_z 
				* map_c.rev_z / COMPRESS_Z - 0.41 * (map[i].x + map[i].y));
		map[i].x_proj *= map_c.zoom / 2;
		map[i].y_proj *= map_c.zoom / 2;
		map[i].x_proj += map_c.win_x;
		map[i].y_proj += map_c.win_y;
		i++;
	}
	return (TRUE);
}
