/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_proj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iongradea <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 03:07:43 by iongradea         #+#    #+#             */
/*   Updated: 2017/10/25 03:19:59 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		proj_iso(t_point *map, int zoom)
{
	int		i;

	i = 0;
	while ((map[i]).in_tab == TRUE)
	{
		map[i].x_proj = 1920 / 2 + 0.7 * map[i].x - 0.7 * map[i].y;
		map[i].y_proj = 1080 / 2 + 0.82 * map[i].z 
			- 0.41 * (map[i].x + map[i].y);
		map[i].x_proj *= zoom;
		map[i].y_proj *= zoom;
		i++;
	}
	return (TRUE);
}
