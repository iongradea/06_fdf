/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:34:55 by igradea           #+#    #+#             */
/*   Updated: 2017/10/25 18:05:33 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	set_bresen(t_bresen *bre, t_point pt, t_point next)
{
	bre->x = pt.x_proj;
	bre->y = pt.y_proj;
	bre->dx = next.x_proj - pt.x_proj;
	bre->dy = next.y_proj - pt.y_proj;
	bre->xinc = (bre->dx > 0) ? 1 : -1;
	bre->yinc = (bre->dy > 0) ? 1 : -1;
	bre->dx = fabsf(bre->dx);
	bre->dy = fabsf(bre->dy);
	return (TRUE);
}

static void	sub_draw_1(t_bresen *bre, t_map map_c)
{
	bre->x += bre->xinc;
	bre->cumul += bre->dy;
	if (bre->cumul >= bre->dx)
	{
		bre->cumul -= bre->dx;
		bre->y += bre->yinc;
	}
	mlx_pixel_put(map_c.mlx, map_c.win, bre->x, bre->y, 0x00FFFFFF);
}

static void	sub_draw_2(t_bresen *bre, t_map map_c)
{
	bre->y += bre->yinc;
	bre->cumul += bre->dx;
	if (bre->cumul >= bre->dy)
	{
		bre->cumul -= bre->dy;
		bre->x += bre->xinc;
	}
	mlx_pixel_put(map_c.mlx, map_c.win, bre->x, bre->y, 0x00FFFFFF);
}

static int	sub_draw(t_bresen bre, t_map map_c)
{
	int	i;

	i = -1;
	if (bre.dx > bre.dy)
	{
		bre.cumul = bre.dx / 2;
		while (++i <= bre.dx)
			sub_draw_1(&bre, map_c);
	}
	else
	{
		bre.cumul = bre.dy / 2;
		while (++i <= bre.dy)
			sub_draw_2(&bre, map_c);
	}
	return (TRUE);
}

int			draw(t_point *map, t_map map_c)
{
	t_bresen	bre;
	int			pos;

	pos = 0;
	while (map && ((map + pos)->in_tab == TRUE))
	{
		mlx_pixel_put(map_c.mlx, map_c.win, (map + pos)->x_proj,
				(map + pos)->y_proj, 0x00FFFFFF);
		if ((pos + 1) % map_c.line_len != 0)
		{
			set_bresen(&bre, *(map + pos), *(map + pos + 1));
			sub_draw(bre, map_c);
		}
		if (pos + map_c.line_len < map_c.nb_pts)
		{
			set_bresen(&bre, *(map + pos), *(map + pos + map_c.line_len));
			sub_draw(bre, map_c);
		}
		pos++;
	}
	return (TRUE);
}
